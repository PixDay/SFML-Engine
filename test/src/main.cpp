#include "SFML-Engine.h"

int main(void)
{
    SceneManager sceneManager;

    sceneManager.setEngineCursor();
    sceneManager.addObject(new ActionButton());
    sceneManager.update();
    return 0;
}