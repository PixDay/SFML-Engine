#include "SFML-Engine.h"
#include <iostream>

SceneManager sceneManager;

void test(void)
{
    sceneManager.setCurrentScene("game");
    sceneManager.setEngineCursor();
}

int main(void)
{
    sceneManager.addScene("game");
    sceneManager.setEngineCursor();
    sceneManager.addObject(new ActionButton(test, 100.0f, 100.0f));
    sceneManager.update();
    return 0;
}