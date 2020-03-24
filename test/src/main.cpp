#include "SFML-Engine.h"
#include "cube"
#include <iostream>
 

SceneManager sceneManager;
SoundManager soundManager;

void menu(void)
{
    sceneManager.setCurrentSceneTransition("SFML-Engine-default");
    sceneManager.setEngineCursor();
}

void game(void)
{
    sceneManager.setCurrentSceneTransition("game");
    sceneManager.setSystemCursor();
}

int main(void)
{
    // CREATING A GAME SCENE 
    sceneManager.addScene("game");

    // SET CURSOR TYPE OF CURRENT SCENE (DEFAULT HERE)
    sceneManager.setEngineCursor();

    // ADD AN ACTIONBUTTON TO THE SCENE
    sceneManager.addObject(new ActionButton(game, 720.0f, 110.0f));

    // ADD AN ACTIONBUTTON TO THE GAME SCENE
    sceneManager.addObjectTo(new ActionButton(menu, 600.0f, 300.0f), "game");
    DisplayableObject * gameBackground = new DisplayableObject("img/background/background.jpg");
    gameBackground->setLayout(0);
    sceneManager.addObjectTo(gameBackground, "game");

    // ADD A BACKGROUND TO THE SCENE
    DisplayableObject * background  = new DisplayableObject("img/background/background.png");
    background->setLayout(0);
    sceneManager.addObject(background); 

    // ADD AN ANIMATED OBJECT TO THE SCENE
    DisplayableObject * cube = new DisplayableObject();    
    cube->setTexture("img/animation/cube/cube000.png");
    cube->addAnimation(cubeAnimation, 0.03, 1.0f, true);
    cube->setLayout(19);
    const sf::Vector2f position(1550.0f, 800.0f);
    cube->setPosition(position, cube->getSprite());
    const sf::Vector2f scale(0.5f, 0.5f);
    cube->setScale(scale, cube->getSprite());
    sceneManager.addObject(cube);
    
    // ADD SOUND TO GLOBAL
    soundManager.addSound("listener", "sound/listener.ogg", true);
    soundManager.playSound("listener");
    // PLAY THE GAME
    sceneManager.update();
    return 0;
}
