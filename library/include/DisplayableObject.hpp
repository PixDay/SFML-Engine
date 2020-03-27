/*
** 13/03/2020 Paris
** DisplayableObject.hpp
** File description:
** Adrien Colombier
*/

#pragma once

#include "GameObject.hpp"
#include "Animator.hpp"

class DisplayableObject : public GameObject
{
    public:
        DisplayableObject();
        DisplayableObject(std::string const &texture);
        ~DisplayableObject();

        void update();
        
        /* ADDERS */
        void addAnimation(std::vector<std::string> &frames, float timeToWait, float speed, bool loop);

        /* DELETERS */
        void deleteAnimation(std::string &name);

        /* SETTERS */
        void setTexture(std::string const &texture);
        void setTexture(sf::Texture const &texture);
        void setOrigin(sf::Vector2f const &origin, sf::Sprite *sprite);
        void setScale(sf::Vector2f const &scale, sf::Sprite *sprite);
        void setDimension(sf::Vector2f const &hitbox);
        void setDimension(size_t const &x, size_t const &y);

        /* GETTERS */
        sf::Sprite *    getSprite(void)     const;
        sf::Texture     getTexture(void)    const;
        sf::Vector2f    getDimension(void)  const;

    private:
        sf::Sprite *    _sprite;
        sf::Texture     _texture;
        sf::Vector2f    _origin;
        sf::Vector2f    _scale;
        sf::Vector2f    _hitbox;
        Animator        _animator;
        
};