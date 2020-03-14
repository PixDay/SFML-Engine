#include "SFML-Engine.h"

int main(void)
{
    SceneManager sceneManager;

    while (sceneManager.getWindow()->isOpen())
    {
        sf::Event event;
        while (sceneManager.getWindow()->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                sceneManager.getWindow()->close();
        }
    }
    return 0;
}