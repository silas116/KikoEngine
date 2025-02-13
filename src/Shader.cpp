//
// Created by Silas on 01/02/2025.
//

#include "Shader.h"
#include <iostream>
#include <fstream>
#include <sstream>

Shader::Shader(const char* vertexPath, const char* fragmentPath) {
    std::string vertexCode = LoadShaderCode(vertexPath);
    std::string fragmentCode = LoadShaderCode(fragmentPath);

    unsigned int vertex = CompileShader(vertexCode.c_str(), GL_VERTEX_SHADER);
    unsigned int fragment = CompileShader(fragmentCode.c_str(), GL_FRAGMENT_SHADER);

    ID = glCreateProgram();
    glAttachShader(ID, vertex);
    glAttachShader(ID, fragment);
    glLinkProgram(ID);

    glDeleteShader(vertex);
    glDeleteShader(fragment);
}
void Shader::SetMat4(const std::string &name, const glm::mat4 &mat) {
    glUniformMatrix4fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, glm::value_ptr(mat));
}
void Shader::Use() {
    glUseProgram(ID);
}
void Shader::SetUniform(const std::string& name, float value) {
    glUniform1f(glGetUniformLocation(ID, name.c_str()), value);
}

void Shader::SetUniform(const std::string& name, int value) {
    glUniform1i(glGetUniformLocation(ID, name.c_str()), value);
}

void Shader::SetUniform(const std::string& name, float x, float y, float z) {
    glUniform3f(glGetUniformLocation(ID, name.c_str()), x, y, z);
}
std::string Shader::LoadShaderCode(const char* filePath) {
    std::ifstream file(filePath);
    if (!file.is_open()) {
        std::cerr << "Fehler: Shader-Datei nicht gefunden! (" << filePath << ")" << std::endl;
        return "";
    }
    std::stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}

unsigned int Shader::CompileShader(const char* code, GLenum type) {
    unsigned int shader = glCreateShader(type);
    glShaderSource(shader, 1, &code, NULL);
    glCompileShader(shader);

    int success;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
    if (!success) {
        char infoLog[512];
        glGetShaderInfoLog(shader, 512, NULL, infoLog);
        std::cerr << "Shader Compilation Failed: " << infoLog << std::endl;
    }
    return shader;
}

