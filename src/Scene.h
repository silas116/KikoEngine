//
// Created by Silas on 01/02/2025.
//
#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include "Renderer.h"
#include "InputManager.h"

class Scene {
public:
    Scene();
    ~Scene();

    void Update(float deltaTime); // 🚀 Pro Frame aufrufen
    void Render(Renderer& renderer); // 🎨 Alles zeichnen

    // Hier könnten später GameObjects hinzugefügt werden
    // void AddGameObject(GameObject* obj);

private:
    // std::vector<GameObject*> m_GameObjects; // (später für Objekte)
};

#endif

