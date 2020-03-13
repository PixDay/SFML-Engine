/*
** 13/03/2020 Paris
** DisplayObject.cpp
** File description:
** Adrien Colombier
*/

#include "DisplayObject.hpp"

DisplayObject::DisplayObject()
{
}


/* SETTERS */

void DisplayObject::setTexture(std::string const &texture)
{
    _texture.loadFromFile(texture);
    _sprite.setTexture(_texture, false);
}

void DisplayObject::setLayout(size_t const &layout)
{
    _layout = layout;
}


/* GETTERS */

const sf::Sprite    DisplayObject::getSprite(void)     const
{
    return _sprite;
}

const sf::Texture   DisplayObject::getTexture(void)    const
{
    return _texture;
}

const size_t        DisplayObject::getLayout(void)     const
{
    return _layout;
}