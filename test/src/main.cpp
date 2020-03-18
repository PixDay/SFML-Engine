#include "SFML-Engine.h"
#include <iostream>

void test(void)
{
    std::cout << "Hello function handler" << std::endl;
}

int main(void)
{
    SceneManager sceneManager;

    sceneManager.setEngineCursor();
    sceneManager.addObject(new ActionButton(test, 100.0f, 100.0f));
    sceneManager.update();
    return 0;
}