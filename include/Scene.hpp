/*
** 13/03/2020 Paris
** Scene.hpp
** File description:
** Adrien Colombier
*/

#pragma once

#include "GameObject.hpp"

class Scene
{
    public:
        Scene(std::string const &name);
        ~Scene() = default;

        /* ADDERS */
        void addObject(GameObject const &gameObject);

        /* DELETERS */
        void deleteObject();

        /* SETTERS */
        void setName(std::string const &name);

        /* GETTERS */
        const std::vector<GameObject>   getGameObjects() const;
        const std::string               getName() const;

    private:
        std::string             _name;
        std::vector<GameObject> _gameObjects;
};