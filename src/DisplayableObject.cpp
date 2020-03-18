/*
** 13/03/2020 Paris
** DisplayableObject.cpp
** File description:
** Adrien Colombier
*/

#include "DisplayableObject.hpp"

DisplayableObject::DisplayableObject():
_sprite(new sf::Sprite())
{
    this->setType("DisplayableObject");
}

DisplayableObject::~DisplayableObject()
{
    delete _sprite;
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

void DisplayableObject::setLayout(size_t const &layout)
{
    _layout = layout;
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


size_t        DisplayableObject::getLayout(void)     const
{
    return _layout;
}