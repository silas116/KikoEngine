#version 330 core
in vec2 TexCoords;  // Passed from the vertex shader
out vec4 FragColor;

uniform sampler2D texture1;  // The texture

void main() {
    FragColor = texture(texture1, TexCoords);  // Apply the texture
}