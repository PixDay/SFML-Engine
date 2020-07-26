/*
** 20/03/2020 Fontainebleau
** Animator.cpp
** File description:
** Adrien Colombier
*/

#include "Animator.hpp"

Animator::Animator(sf::Sprite * sprite):
_totalAnimation(0),
_currentAnimation(0),
_sprite(sprite)
{
}

void Animator::update()
{
    if (_totalAnimation != 0 && _animations[_currentAnimation].getPlay())
        _animations[_currentAnimation].play(_sprite);
}

/* ADDERS */
void Animator::addAnimation(std::vector<std::string> &frames, float timeToWait, float speed, bool loop)
{
    Animation animation(frames, timeToWait, speed, loop);

    _animations.emplace_back(animation);
    _totalAnimation++;
}

/* DELETERS */
void Animator::deleteAnimation(std::string &name)
{
    size_t iterator = 0;

    for (auto animation : _animations){
        if (animation.getName() == name) {
            _animations.erase(_animations.begin() + iterator);
            break;
        }
        iterator++;
    }
}

/* SETTERS */
void Animator::setCurrentAnimation(size_t &currentAnimation)
{
    _currentAnimation = currentAnimation;
}

void Animator::setcurrentAnimation(std::string &currentAnimation)
{
    size_t iterator = 0;

    for (auto animation : _animations) {
        if (animation.getName() == currentAnimation)
            _currentAnimation = iterator;
        iterator++;
    }
}

/* GETTERS */
size_t  Animator::getTotalAnimation(void)     const
{
    return _totalAnimation;
}

size_t  Animator::getCurrentAnimation(void)   const
{
    return _currentAnimation;
}
