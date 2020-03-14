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
    
    sf::Vector2f position = {20.0f, 20.0f};
    this->setPosition(position);
}