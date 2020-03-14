/*
** 13/03/2020 Paris
** SceneManager.hpp
** File description:
** Adrien Colombier
*/

#pragma once

#include "Scene.hpp"

class SceneManager
{
    public:
        SceneManager();
        ~SceneManager() = default;

        /* ADDERS */
        void addScene(std::string const &name);

        /* DELETERS */
        void deleteScene(std::string const &name);

        /* SETTERS */
        void setCurrentScene(size_t const &scene);
        void setCurrentScene(std::string const &name);

        /* GETTERS */
        sf::RenderWindow *    getWindow() const;
        std::vector<Scene>    getScenes() const;
        size_t                getCurrentScene() const;

    private:
        sf::RenderWindow    *_window;
        size_t              _currentScene;
        std::vector<Scene>  _scenes;
};