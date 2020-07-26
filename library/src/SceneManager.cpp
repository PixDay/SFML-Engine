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
_leaveKey(sf::Keyboard::Key::Escape),
_transition(new Transition()),
_transitionTo("")
{
    this->addScene("SFML-Engine-default");
    //_window->setVerticalSyncEnabled(true);
}

SceneManager::~SceneManager()
{
    delete _window;
}

void SceneManager::update(void)
{
    sf::Event event;

displaySkipper:
    while (_window->isOpen())
    {
        while (_window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(_leaveKey))
                _window->close();
        }

        _window->clear(sf::Color::White);
        _cursor->setPosition(static_cast<sf::Vector2f>(_cursor->getMouse().getPosition(*_window)), _cursor->getSprite());

        for (auto displayableElement : _scenes[_currentScene]->getGameObjects()) {
            if (displayableElement->getTag() == "ActionButton")
                (static_cast<ActionButton *>(displayableElement))->update(_cursor->getPosition());
            
            if (displayableElement->getType() == "DisplayableObject" && (static_cast<DisplayableObject *>(displayableElement)->getActive())) {
                static_cast<DisplayableObject *>(displayableElement)->update();
                _window->draw(*(static_cast<DisplayableObject *>(displayableElement)->getSprite()));
            }
            if (_transitionTo != "") {
                this->makeTransition();
                if (_transitionTo == "continue") {
                    _transitionTo = "";
                    goto displaySkipper;
                }
            }
            
        }
        _window->display();
    }
}

void SceneManager::makeTransition(void)
{
    size_t iterator = 0;

    if (_transition->playTransition()) {
        this->_scenes[_currentScene]->eraseObject("transition");
        this->setCurrentScene(_transitionTo);
        _transitionTo = "continue";
    }
}

/* ADDERS */
 
void SceneManager::addScene(std::string const &name)
{
    Scene *scene = new Scene(name);

    _scenes.emplace_back(scene);
    _scenes[this->getScene(name)]->addObject(
        dynamic_cast<GameObject *>(
        dynamic_cast<DisplayableObject *>(_cursor)
        )
    );
}

void SceneManager::addObject(GameObject *object)
{
    _scenes[_currentScene]->addObject(object);
}

void SceneManager::addObjectTo(GameObject *object, std::string const &name)
{
    _scenes[this->getScene(name)]->addObject(object);
}

/* DELETERS */

void SceneManager::deleteScene(std::string const &name)
{
    size_t iterator = 0;

    for (auto scene : _scenes) {
        if (scene->getName() == name) {
            _scenes.erase(_scenes.begin() + iterator);
            delete scene;
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
        if (scene->getName() == name) {
            _currentScene = iterator;
            break;
        }
        iterator++;
    }
}

void SceneManager::setCurrentSceneTransition(std::string const &name)
{
    if (_transitionTo == "") {
        this->addObject(_transition);
        _transitionTo = name;
    }
}

void SceneManager::setTransitionTexture(std::string const &name)
{
    delete _transition;
    _transition = new Transition(name, 0.8);
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

sf::RenderWindow      *SceneManager::getWindow()                                                    const
{
    return _window;
}

std::vector<Scene *>    SceneManager::getScenes()                                                   const
{
    return _scenes;
}

size_t                  SceneManager::getCurrentScene()                                             const
{
    return _currentScene;
}

size_t                  SceneManager::getScene(std::string const &name)                             const
{
    size_t iterator = 0;

    for (auto scene : _scenes) {
        if (scene->getName() == name)
            return iterator;
        iterator++;
    }
    return _currentScene;
}

bool                    SceneManager::collide(std::string const &tag1, std::string const &tag2)     const
{
    DisplayableObject *object1 = nullptr;
    DisplayableObject *object2 = nullptr;
    
    for (auto object : _scenes[_currentScene]->getGameObjects()) {
        if (object->getTag() == tag1)
            object1 = static_cast<DisplayableObject *>(object);
        if (object->getTag() == tag2)
            object2 = static_cast<DisplayableObject *>(object);
    }
    if (object1 == nullptr || object2 == nullptr)
        return false;
    sf::Rect<float> obj1(
        object1->getPosition(), 
        {(float)object1->getSprite()->getTexture()->getSize().x, 
         (float)object1->getSprite()->getTexture()->getSize().y}
    );
    sf::Rect<float> obj2(
        object2->getPosition(), 
        {(float)object2->getSprite()->getTexture()->getSize().x, 
         (float)object2->getSprite()->getTexture()->getSize().y}
    );
    return obj1.intersects(obj2);
}