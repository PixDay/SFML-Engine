#include "SFML-Engine.h"

int main(void)
{
    SceneManager sceneManager;
    sf::Event event;

    sceneManager.setEngineCursor();
    while (sceneManager.getWindow()->isOpen())
    {
        while (sceneManager.getWindow()->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                sceneManager.getWindow()->close();
        }
        sceneManager.update();
    }
    return 0;
}