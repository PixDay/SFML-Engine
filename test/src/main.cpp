#include "SFML-Engine.h"
#include <iostream>

SceneManager sceneManager;

void menu(void)
{
    sceneManager.setCurrentScene("SFML-Engine-default");
    sceneManager.setEngineCursor();
}

void game(void)
{
    sceneManager.setCurrentScene("game");
    sceneManager.setSystemCursor();
    sceneManager.addObject(new ActionButton(menu, 0.0f, 300.0f));
}

int main(void)
{
    sceneManager.addScene("game");
    sceneManager.setEngineCursor();
    sceneManager.addObject(new ActionButton(game, 100.0f, 100.0f));
    sceneManager.addObject(new ActionButton(game, 300.0f, 100.0f));
    sceneManager.addObject(new ActionButton(game, 200.0f, 300.0f));
    DisplayableObject * background  = new DisplayableObject();
    background->setTexture("img/background/background.png");
    background->setLayout(0);
    sceneManager.addObject(background); 
    sceneManager.update();
    return 0;
}