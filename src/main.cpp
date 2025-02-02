#include <C:\Users\Silas\CLionProjects\Kiko\vendor\glad\include\glad\glad.h>
#include <C:\Users\Silas\.vcpkg-clion\vcpkg\installed\x64-mingw-dynamic\include\GLFW/glfw3.h>
#include <iostream>
#include <cmath>
#include "Renderer.h"
#include "Game.h"

int main() {



    // 5️⃣ Game-Instanz erstellen und starten
    Game game(800, 600, "Game Engine");


    game.Run();

    // 6️⃣ Aufräumen
    glfwTerminate();
    return 0;
}

