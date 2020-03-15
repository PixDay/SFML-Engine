/*
** 13/03/2020 Paris
** Scene.cpp
** File description:
** Adrien Colombier
*/

#include "Scene.hpp"
#include <iostream>
Scene::Scene(std::string const &name):
_name(name)
{
}

/* ADDERS */
void Scene::addObject(GameObject * const gameObject)
{
    _gameObjects.push_back(gameObject);
}

/* DELETERS */
void Scene::deleteObject(std::string const &tag)
{
    size_t iterator = 0;

    for (auto gameObject : _gameObjects) {
        if (gameObject->getTag() == tag) {
            std::cout << _gameObjects.size() << std::endl;
            delete _gameObjects[iterator];
            //_gameObjects.erase(_gameObjects.begin() + iterator);
            std::cout << _gameObjects.size() << std::endl;
            break;
        }
        iterator++;
    }
}

/* SETTERS */
void Scene::setName(std::string const &name)
{
    _name = name;
}

/* GETTERS */
std::vector<GameObject *> Scene::getGameObjects() const
{
    return _gameObjects;
}

std::string               Scene::getName() const
{
    return _name;
}