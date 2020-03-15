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
        void setType(std::string const &type);
        void setPosition(sf::Vector2f const &position);
        void setPosition(sf::Vector2f const &position, sf::Sprite *sprite);
        void setScale(sf::Vector2f const &scale);
        void setActive(bool const &active);

        /* GETTERS */
        std::string     getTag(void)        const;
        std::string     getType(void)       const;
        sf::Vector2f    getPosition(void)   const;
        sf::Vector2f    getScale(void)      const;
        bool            getActive(void)     const;

    private:
        std::string     _tag;
        std::string     _type;
        sf::Vector2f    _position;
        sf::Vector2f    _scale;
        bool            _active;
};