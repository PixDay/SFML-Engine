/*
** 13/03/2020 Paris
** SceneManager.cpp
** File description:
** Adrien Colombier
*/

#include "SceneManager.hpp"
#include <iostream>

SceneManager::SceneManager():
_window(new sf::RenderWindow(sf::VideoMode(800, 600), "SFML window")),
_currentScene(0),
_cursor(new Cursor())
{
    this->addScene("SFML-Engine-default");
}

SceneManager::~SceneManager()
{
    delete _window;
}

void SceneManager::update(void) const
{
    _window->clear(sf::Color::Black);

    _cursor->setPosition(static_cast<sf::Vector2f>(_cursor->getMouse().getPosition(*_window)), _cursor->getSprite());
    for (auto displayableElement : _scenes[_currentScene].getGameObjects()) {
        if (displayableElement->getType() == "DisplayableObject") {
            _window->draw(*(static_cast<DisplayableObject *>(displayableElement)->getSprite()));
        }
    }
    _window->display();
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

void SceneManager::setSystemCursor()
{
    _window->setMouseCursorVisible(true);
    _scenes[_currentScene].deleteObject("cursor");
}

void SceneManager::setEngineCursor()
{
    _window->setMouseCursorVisible(false);
    _scenes[_currentScene].deleteObject("cursor");
    _scenes[_currentScene].addObject(
        dynamic_cast<GameObject *>(
        dynamic_cast<DisplayableObject *>(_cursor)
        )
    );
}

void SceneManager::setPersonalCursor(std::string const &texture)
{
    _window->setMouseCursorVisible(false);
    _scenes[_currentScene].deleteObject("cursor");
    _cursor->setTexture(texture);
    _scenes[_currentScene].addObject(
        dynamic_cast<GameObject *>(
        dynamic_cast<DisplayableObject *>(_cursor)
        )
    );
}

/* GETTERS */
sf::RenderWindow      *SceneManager::getWindow() const
{
    return _window;
}

std::vector<Scene>    SceneManager::getScenes() const
{
    return _scenes;
}

size_t                SceneManager::getCurrentScene() const
{
    return _currentScene;
}