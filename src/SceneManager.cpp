/*
** 13/03/2020 Paris
** SceneManager.cpp
** File description:
** Adrien Colombier
*/

#include "SceneManager.hpp"

SceneManager::SceneManager():
_window(new sf::RenderWindow(sf::VideoMode(1920, 1080), "SFML Engine", sf::Style::Fullscreen)),
_currentScene(0),
_cursor(new Cursor()),
_leaveKey(sf::Keyboard::Key::Escape)
{
    this->addScene("SFML-Engine-default");
    _window->setVerticalSyncEnabled(true);
}

SceneManager::~SceneManager()
{
    delete _window;
}

void SceneManager::update(void) const
{
    sf::Event event;

    while (_window->isOpen())
    {

        while (_window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(_leaveKey))
                _window->close();
        }

        _window->clear(sf::Color::Black);
        _cursor->setPosition(static_cast<sf::Vector2f>(_cursor->getMouse().getPosition(*_window)), _cursor->getSprite());

        for (auto displayableElement : _scenes[_currentScene].getGameObjects()) {
            if (displayableElement->getTag() == "ActionButton")
                (static_cast<ActionButton *>(displayableElement))->update(_cursor->getPosition());
            
            if (displayableElement->getType() == "DisplayableObject" && (static_cast<DisplayableObject *>(displayableElement)->getActive()))
                _window->draw(*(static_cast<DisplayableObject *>(displayableElement)->getSprite()));
        }
        _window->display();
    }
}

 /* ADDERS */
 
void SceneManager::addScene(std::string const &name)
{
    Scene scene(name);
    _scenes.push_back(scene);
    _scenes[this->getScene(name)].addObject(
        dynamic_cast<GameObject *>(
        dynamic_cast<DisplayableObject *>(_cursor)
        )
    );
}

void SceneManager::addObject(GameObject *object)
{
    _scenes[_currentScene].addObject(object);
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
    _cursor->setActive(false);
}

void SceneManager::setEngineCursor()
{
    _window->setMouseCursorVisible(false);
    _cursor->setActive(true);
}

void SceneManager::setPersonalCursor(std::string const &texture)
{
    _window->setMouseCursorVisible(false);
    _cursor->setActive(true);
    _cursor->setTexture(texture);
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

size_t                SceneManager::getScene(std::string const &name) const
{
    size_t iterator = 0;

    for (auto scene : _scenes) {
        if (scene.getName() == name)
            return iterator;
        iterator++;
    }
    return _currentScene;
}