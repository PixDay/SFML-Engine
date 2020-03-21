/*
** 15/03/2020 Paris
** ActionButton.hpp
** File description:
** Adrien Colombier
*/

#pragma once

#include "DisplayableObject.hpp"

class ActionButton : public DisplayableObject
{
    public:
        ActionButton(void (*function)(void), float x, float y);
        ActionButton(void (*function)(void), float x, float y, std::string const &texture, std::string const &hoverTexture);
        ~ActionButton() = default;

        void update(sf::Vector2f const &point);

        /* SETTERS */
        void setTextures(std::string const &texture, std::string const &hoverTexture);
        void setDefaultTexture(std::string const &texture);
        void setHoverTexture(std::string const &texture);
        void setEngineBlue(void);
        void setFunction(void (*function)(void));

    private:
        sf::Texture     _texture;
        sf::Texture     _hoverTexture;
        void            (*_function)(void);
};