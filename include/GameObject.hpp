/*
** 13/03/2020 Paris
** GameObject.hpp
** File description:
** Adrien Colombier
*/

#pragma once

#include <SFML/Graphics.hpp>

class GameObject
{
    public:
        GameObject();
        ~GameObject() = default;

        /* SETTERS */
        void setTag(std::string const &tag);
        void setPosition(sf::Vector2f const &position);
        void setScale(sf::Vector2f const &scale);
        void setActive(bool const &active);     

        /* GETTERS */
        const std::string   getTag(void)        const;
        const sf::Vector2f  getPosition(void)   const;
        const sf::Vector2f  getScale(void)      const;
        const bool          getActive(void)     const;

    private:
        std::string     _tag;
        sf::Vector2f    _position;
        sf::Vector2f    _scale;
        bool            _active;
};