cmake_minimum_required(VERSION 3.10)
project(Kiko)

set(CMAKE_CXX_STANDARD 20)

# vcpkg Toolchain-Datei hinzufügen
set(CMAKE_TOOLCHAIN_FILE "C:/Users/Silas/.vcpkg-clion/vcpkg/scripts/buildsystems/vcpkg.cmake" CACHE STRING "")
set(CMAKE_PREFIX_PATH "C:/Users/Silas/.vcpkg-clion/vcpkg/installed/x64-mingw-dynamic")


# GLFW und OpenGL suchen
find_package(glfw3 CONFIG REQUIRED)
find_package(OpenGL REQUIRED)



# GLAD als statische Bibliothek hinzufügen
add_library(glad STATIC vendor/glad/src/glad.c)

# Weitere Abhängigkeiten einbinden (falls vorhanden)
include_directories(vendor/stb)
include_directories(vendor/glm)
add_executable(Kiko src/main.cpp
        src/Game.cpp
        src/Game.h
        src/Renderer.cpp
        src/Renderer.h
        src/inputManager.cpp
        src/inputManager.h
        src/Scene.cpp
        src/Scene.h
        src/Shader.cpp
        src/Shader.h
        src/Mesh.cpp
        src/Mesh.h
        src/OrbitCamera.cpp
        src/OrbitCamera.h
        src/Texture.cpp
        src/Texture.h)
# GLFW, GLAD und OpenGL verlinken
#target_link_libraries(Kiko PRIVATE glad glfw OpenGL::GL)

# Wenn du auf Windows arbeitest, könnte das Verlinken von glu32 erforderlich sein:
target_include_directories(Kiko PRIVATE vendor/glad/include)
#target_link_libraries(Kiko PRIVATE glad)
target_link_libraries(Kiko PRIVATE  glad glfw OpenGL::GL glu32)
