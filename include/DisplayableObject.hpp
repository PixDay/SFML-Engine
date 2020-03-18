/*
** 13/03/2020 Paris
** DisplayableObject.hpp
** File description:
** Adrien Colombier
*/

#pragma once

#include "GameObject.hpp"

class DisplayableObject : public GameObject
{
    public:
        DisplayableObject();
        ~DisplayableObject();

        /* SETTERS */
        void setTexture(std::string const &texture);
        void setTexture(sf::Texture const &texture);
        void setDimension(sf::Vector2f const &hitbox);
        void setDimension(size_t const &x, size_t const &y);

        /* GETTERS */
        sf::Sprite *    getSprite(void)     const;
        sf::Texture     getTexture(void)    const;
        sf::Vector2f    getDimension(void)  const;

    private:
        sf::Sprite *    _sprite;
        sf::Texture     _texture;
        sf::Vector2f    _hitbox;
};