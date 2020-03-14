/*
** 13/03/2020 Paris
** SceneManager.cpp
** File description:
** Adrien Colombier
*/

#include "SceneManager.hpp"

SceneManager::SceneManager():
_window(new sf::RenderWindow(sf::VideoMode(800, 600), "SFML window")),
_currentScene(0)
{
}

 /* ADDERS */
void SceneManager::addScene(std::string const &name)
{
    Scene scene(name);
    _scenes.push_back(scene);
}

/* DELETERS */
void SceneManager::deleteScene(std::string const &name)
{
    size_t iterator = 0;

    for (auto scene : _scenes) {
        if (scene.getName() == name) {
            _scenes.erase(_scenes.begin() + iterator);
            break;
        }
        iterator++;
    }
}

/* SETTERS */
void SceneManager::setCurrentScene(size_t const &scene)
{
    _currentScene = scene;
}

void SceneManager::setCurrentScene(std::string const &name)
{
    size_t iterator = 0;

    for (auto scene : _scenes) {
        if (scene.getName() == name) {
            _currentScene = iterator;
            break;
        }
        iterator++;
    }
}

/* GETTERS */
const sf::RenderWindow      *SceneManager::getWindow() const
{
    return _window;
}

const std::vector<Scene>    SceneManager::getScenes() const
{
    return _scenes;
}

const size_t                SceneManager::getCurrentScene() const
{
    return _currentScene;
}