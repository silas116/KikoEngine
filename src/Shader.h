//
// Created by Silas on 01/02/2025.
//

#ifndef SHADER_H
#define SHADER_H

#include <string>
#include <glad/glad.h>

class Shader {
public:
    unsigned int ID;

    Shader(const char* vertexPath, const char* fragmentPath);
    void Use();
    void SetUniform(const std::string& name, float value);
    void SetUniform(const std::string& name, int value);
    void SetUniform(const std::string& name, float x, float y, float z);
private:
    std::string LoadShaderCode(const char* filePath);
    unsigned int CompileShader(const char* code, GLenum type);
};

#endif

