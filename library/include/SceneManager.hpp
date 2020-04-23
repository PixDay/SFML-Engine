/*
** 13/03/2020 Paris
** SceneManager.hpp
** File description:
** Adrien Colombier
*/

#pragma once

#include "Scene.hpp"
#include "Cursor.hpp"
#include "ActionButton.hpp"
#include "Transition.hpp"

class SceneManager
{
    public:
        SceneManager();
        ~SceneManager();
        
        void update();
        void makeTransition();

        /* ADDERS */
        void addScene(std::string const &name);
        void addObject(GameObject *object);
        void addObjectTo(GameObject *object, std::string const &name);

        /* DELETERS */
        void deleteScene(std::string const &name);

        /* SETTERS */
        void setCurrentScene(size_t const &scene);
        void setCurrentScene(std::string const &name);
        void setCurrentSceneTransition(std::string const &name);
        void setTransitionTexture(std::string const &name);
        void setSystemCursor();
        void setEngineCursor();
        void setPersonalCursor(std::string const &texture);

        /* GETTERS */
        sf::RenderWindow *      getWindow()                                                 const;
        std::vector<Scene *>    getScenes()                                                 const;
        size_t                  getCurrentScene()                                           const;
        size_t                  getScene(std::string const &name)                           const;
        bool                    collide(std::string const &tag1, std::string const &tag2)   const;

    private:
        sf::RenderWindow *      _window;
        size_t                  _currentScene;
        std::vector<Scene *>    _scenes;
        Cursor *                _cursor;
        sf::Keyboard::Key       _leaveKey;
        Transition *            _transition;
        std::string             _transitionTo;
};