/*
** 13/03/2020 Paris
** GameObject.cpp
** File description:
** Adrien Colombier
*/

#include "GameObject.hpp"

GameObject::GameObject():
_tag("default"),
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

void GameObject::setPosition(sf::Vector2f const &position)
{
    _position = position;
}

void GameObject::setScale(sf::Vector2f const &scale)
{
    _scale = scale;
}

void GameObject::setActive(bool const &active)
{
    _active = active;
}


/* GETTERS */

const std::string   GameObject::getTag(void)        const
{
    return _tag;
}

const sf::Vector2f  GameObject::getPosition(void)   const
{
    return _position;
}

const sf::Vector2f  GameObject::getScale(void)      const
{
    return _scale;
}

const bool          GameObject::getActive(void)     const
{
    return _active;
}
