/*
** 13/03/2020 Paris
** DisplayableObject.cpp
** File description:
** Adrien Colombier
*/

#include "DisplayableObject.hpp"

DisplayableObject::DisplayableObject()
{
}


/* SETTERS */

void DisplayableObject::setTexture(std::string const &texture)
{
    _texture.loadFromFile(texture);
    _sprite.setTexture(_texture, false);
}

void DisplayableObject::setLayout(size_t const &layout)
{
    _layout = layout;
}


/* GETTERS */

const sf::Sprite    DisplayableObject::getSprite(void)     const
{
    return _sprite;
}

const sf::Texture   DisplayableObject::getTexture(void)    const
{
    return _texture;
}

const size_t        DisplayableObject::getLayout(void)     const
{
    return _layout;
}