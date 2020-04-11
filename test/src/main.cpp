#include "SFML-Engine.h"
#include "cube"
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>


void menu(void)
{
    sceneManager.setTransitionTexture("img/transition/circle-transition.png");
    sceneManager.setCurrentSceneTransition("SFML-Engine-default");
    sceneManager.setEngineCursor();
}

void game(void)
{
    sceneManager.setTransitionTexture("img/transition/star-transition.png");
    sceneManager.setCurrentSceneTransition("game");
    sceneManager.setSystemCursor();
}

void moveAnimatedObject(DisplayableObject *object)
{   
    static sf::Vector2f direction = {5.0f, 5.0f};

    sf::Vector2f position = object->getPosition();

    if (position.x > 1730.0f)
        direction.x = -10.0f;
    if (position.x < -30.0f)
        direction.x = 10.0f;
    if (position.y > 890.0f)
        direction.y = -10.0f;
    if (position.y < -30.0f)
        direction.y = 10.0f;
    position.x += direction.x;
    position.y += direction.y;
    object->setPosition(position, object->getSprite());
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
    DisplayableObject * cube = new DisplayableObject("img/animation/cube/cube000.png");
    cube->setFunction(moveAnimatedObject);
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
