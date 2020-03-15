/*
** 14/03/2020 Paris
** Cursor.cpp
** File description:
** Adrien Colombier
*/

#include "Cursor.hpp"

Cursor::Cursor()
{
    this->setTag("cursor");
    this->setTexture("img/cursor/SFML-Engine-cursor.png");
}

/* GETTERS */
sf::Mouse Cursor::getMouse() const
{
    return _mouse;
}