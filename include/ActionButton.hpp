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
        ActionButton();
        ActionButton(std::string const &texture, std::string const &hoverTexture);
        ~ActionButton() = default;

        void update(sf::Vector2f &point);

        /* SETTERS */
        void setTextures(std::string const &texture, std::string const &hoverTexture);
        void setDefaultTexture(std::string const &texture);
        void setHoverTexture(std::string const &texture);

    private:
        sf::Texture     _texture;
        sf::Texture     _hoverTexture;
};