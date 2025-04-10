#ifndef TEXTURE_H
#define TEXTURE_H

#include <iostream>

#include "stb_image.h"

#include <glad/glad.h>  // Include before GLFW

class Texture {
public:
    GLuint ID;
    int width, height, channels;

    Texture(const char* filePath);
    ~Texture();

    void Bind(GLuint unit = 0) const;
    void Unbind() const;
};

#endif // TEXTURE_H
