/*
** 15/03/2020 Paris
** ActionButton.cpp
** File description:
** Adrien Colombier
*/

#include "ActionButton.hpp"

ActionButton::ActionButton()
{
}

ActionButton::ActionButton(std::string const &texture, std::string const &hoverTexture)
{
    _texture.loadFromFile(texture);
    _hoverTexture.loadFromFile(hoverTexture);

    this->setTexture(_texture);
}

/* SETTERS */
void ActionButton::setTextures(std::string const &texture, std::string const &hoverTexture)
{
    _texture.loadFromFile(texture);
    _hoverTexture.loadFromFile(hoverTexture);

    this->setTexture(_texture);
}

void ActionButton::setDefaultTexture(std::string const &texture)
{
    _texture.loadFromFile(texture);

    this->setTexture(_texture);
}

void ActionButton::setHoverTexture(std::string const &texture)
{
    _hoverTexture.loadFromFile(texture);
}