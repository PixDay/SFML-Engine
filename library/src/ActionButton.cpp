/*
** 15/03/2020 Paris
** ActionButton.cpp
** File description:
** Adrien Colombier
*/

#include "ActionButton.hpp"

ActionButton::ActionButton(void (*function)(void), float x, float y)
{
    this->setTag("ActionButton");
    _texture.loadFromFile("img/ui/actionButton/button.png");
    this->setTexture(_texture);
    _hoverTexture.loadFromFile("img/ui/actionButton/blueHover.png");
    _function = function;
    this->setPosition({x, y}, this->getSprite());
    this->setLayout(9);
    this->setDimension(190.0f, 49.0f);

}

ActionButton::ActionButton(void (*function)(void), float x, float y, std::string const &texture, std::string const &hoverTexture)
{
    this->setTag("ActionButton");
    _texture.loadFromFile(texture);
    _hoverTexture.loadFromFile(hoverTexture);
    this->setTexture(_texture);
    _function = function;
    this->setPosition({x, y}, this->getSprite());
    this->setLayout(9);
}

void ActionButton::update(sf::Vector2f const &point)
{
    sf::FloatRect hitbox {
        this->getPosition().x, 
        this->getPosition().y, 
        this->getDimension().x * this->getScale().x, 
        this->getDimension().y * this->getScale().y
    };

    this->setTexture((hitbox.contains(point)) ? _hoverTexture : _texture);
    if (hitbox.contains(point) && sf::Mouse::isButtonPressed(sf::Mouse::Left))
        if (_function != nullptr)
            _function();
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

void ActionButton::setEngineBlue(void)
{
    _texture.loadFromFile("img/ui/actionButton/button.png");
    this->setTexture(_texture);
    _hoverTexture.loadFromFile("img/ui/actionButton/blueHover/.png");
}

void ActionButton::setFunction(void (*function)(void))
{
    _function = function;
}
