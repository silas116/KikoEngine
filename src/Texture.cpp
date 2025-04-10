//
// Created by Silas on 13/02/2025.
//

#include "Texture.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
Texture::Texture(const char* filePath) {
    stbi_set_flip_vertically_on_load(true);  // Flip if needed
    unsigned char* data = stbi_load(filePath, &width, &height, &channels, STBI_rgb_alpha );
    std::cout << "Loaded texture: " << filePath
          << " | Size: " << width << "x" << height
          << " | Channels: " << channels
          << " | ID: " << ID << std::endl;

    if (!data) {
        std::cerr << "Failed to load texture: " << filePath << std::endl;
        return;
    }


    glGenTextures(1, &ID);
    glBindTexture(GL_TEXTURE_2D, ID);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);


    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
    glGenerateMipmap(GL_TEXTURE_2D);

    stbi_image_free(data);
    glBindTexture(GL_TEXTURE_2D, 0);
}

Texture::~Texture() {
    glDeleteTextures(1, &ID);
}

void Texture::Bind(GLuint unit) const {
    glActiveTexture(GL_TEXTURE0 + unit);
    glBindTexture(GL_TEXTURE_2D, ID);
}

void Texture::Unbind() const {
    glBindTexture(GL_TEXTURE_2D, 0);
}

