/*
** 13/03/2020 Paris
** DisplayObject.hpp
** File description:
** Adrien Colombier
*/

#pragma once

#include "GameObject.hpp"

class DisplayObject : GameObject
{
    public:
        DisplayObject();
        ~DisplayObject() = default;

        /* SETTERS */
        void setTexture(std::string const &texture);
        void setLayout(size_t const &layout);

        /* GETTERS */
        const sf::Sprite    getSprite(void)     const;
        const sf::Texture   getTexture(void)    const;
        const size_t        getLayout(void)     const;
        
    private:
        sf::Sprite  _sprite;
        sf::Texture _texture;
        size_t      _layout;
};