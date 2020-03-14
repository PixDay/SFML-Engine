/*
** 13/03/2020 Paris
** Scene.cpp
** File description:
** Adrien Colombier
*/

#include "Scene.hpp"

Scene::Scene(std::string const &name):
_name(name)
{
}

/* ADDERS */
void Scene::addObject(GameObject const &gameObject)
{
    _gameObjects.push_back(gameObject);
}

/* DELETERS */
void Scene::deleteObject()
{
}

/* SETTERS */
void Scene::setName(std::string const &name)
{
    _name = name;
}

/* GETTERS */
const std::vector<GameObject> Scene::getGameObjects() const
{
    return _gameObjects;
}

const std::string             Scene::getName() const
{
    return _name;
}