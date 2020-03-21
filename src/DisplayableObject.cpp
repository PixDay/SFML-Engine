/*
** 13/03/2020 Paris
** DisplayableObject.cpp
** File description:
** Adrien Colombier
*/

#include "DisplayableObject.hpp"

DisplayableObject::DisplayableObject():
_sprite(new sf::Sprite()),
_animator(Animator(_sprite))
{
    this->setType("DisplayableObject");
}

DisplayableObject::DisplayableObject(std::string const &texture):
_sprite(new sf::Sprite()),
_animator(Animator(_sprite))
{
    this->setType("DisplayableObject");
    
    _texture.loadFromFile(texture);
    _sprite->setTexture(_texture, false);
}

DisplayableObject::~DisplayableObject()
{
    delete _sprite;
}

void DisplayableObject::update()
{
    _animator.update();
}

/* ADDERS */
void DisplayableObject::addAnimation(std::vector<std::string> &frames, float timeToWait, float speed, bool loop)
{
    _animator.addAnimation(frames, timeToWait, speed, loop);
}

/* DELETERS */
void DisplayableObject::deleteAnimation(std::string &name)
{
    _animator.deleteAnimation(name);
}

/* SETTERS */

void DisplayableObject::setTexture(std::string const &texture)
{
    _texture.loadFromFile(texture);
    _sprite->setTexture(_texture, false);
}

void DisplayableObject::setTexture(sf::Texture const &texture)
{
    _texture = texture;
    _sprite->setTexture(texture, false);
}

void DisplayableObject::setDimension(sf::Vector2f const &hitbox)
{
    _hitbox = hitbox;
}

void DisplayableObject::setDimension(size_t const &x, size_t const &y)
{
    _hitbox.x = x;
    _hitbox.y = y;
}

/* GETTERS */

sf::Sprite*   DisplayableObject::getSprite(void)     const
{
    return _sprite;
}

sf::Texture   DisplayableObject::getTexture(void)    const
{
    return _texture;
}

sf::Vector2f    DisplayableObject::getDimension(void)  const
{
    return _hitbox;
}