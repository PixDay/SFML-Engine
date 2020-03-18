/*
** 13/03/2020 Paris
** GameObject.cpp
** File description:
** Adrien Colombier
*/

#include "GameObject.hpp"

GameObject::GameObject():
_tag("default"),
_type("GameObject"),
_position({0.0f, 0.0f}),
_scale({1.0f, 1.0f}),
_active(true)
{
}


/* SETTERS */

void GameObject::setTag(std::string const &tag)
{
    _tag = tag;
}

void GameObject::setType(std::string const &type)
{
    _type = type;
}

void GameObject::setPosition(sf::Vector2f const &position)
{
    _position = position;
}

void GameObject::setPosition(sf::Vector2f const &position, sf::Sprite *sprite)
{
    _position = position;
    sprite->setPosition(position);
}

void GameObject::setScale(sf::Vector2f const &scale, sf::Sprite *sprite)
{
    _scale = scale;
    sprite->setScale(_scale);
    
}

void GameObject::setLayout(size_t const &layout)
{
    _layout = layout;
}

void GameObject::setActive(bool const &active)
{
    _active = active;
}


/* GETTERS */

std::string   GameObject::getTag(void)        const
{
    return _tag;
}

std::string   GameObject::getType(void)       const
{
    return _type;
}

sf::Vector2f  GameObject::getPosition(void)   const
{
    return _position;
}

sf::Vector2f  GameObject::getScale(void)      const
{
    return _scale;
}

size_t        GameObject::getLayout(void)     const
{
    return _layout;
}


bool          GameObject::getActive(void)     const
{
    return _active;
}
