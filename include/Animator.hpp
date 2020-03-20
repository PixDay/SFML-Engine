/*
** 20/03/2020 Fontainebleau
** Animator.hpp
** File description:
** Adrien Colombier
*/

#pragma once

#include "Animation.hpp"

class Animator
{
    public:
        Animator(sf::Sprite * sprite);
        ~Animator() = default;

        void update();

        /* ADDERS */
        void addAnimation(std::vector<std::string> &frames, float timeToWait, float speed, bool loop);

        /* DELETERS */
        void deleteAnimation(std::string &name);

        /* SETTERS */
        void setCurrentAnimation(size_t &currentAnimation);
        void setcurrentAnimation(std::string &currentAnimation);

        /* GETTERS */
        size_t  getTotalAnimation(void)     const;
        size_t  getCurrentAnimation(void)   const;

    private:
        std::vector<Animation>  _animations;
        size_t                  _totalAnimation;
        size_t                  _currentAnimation;
        sf::Sprite *            _sprite;
};