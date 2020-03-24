/*
** 24/03/2020 Paris
** Transition.cpp
** File description:
** Adrien Colombier
*/

#include "Transition.hpp"

Transition::Transition():
_duration(1.0)
{
    sf::Vector2f origin(64.0f, 64.0f);

    this->setLayout(100);
    this->setTexture("img/transition/star-transition.png");
    this->setOrigin(origin, this->getSprite());
}

Transition::Transition(std::string const &path, double duration):
_duration(duration)
{
    sf::Vector2u size;
    sf::Vector2f origin;

    this->setLayout(100);
    this->setTexture(path);
    size = this->getTexture().getSize();
    origin.x = ((float)size.x) / 2.0f;
    origin.y = ((float)size.y) / 2.0f;
    this->setOrigin(origin, this->getSprite());
}

bool Transition::playTransition(void)
{
    static float playTime = 0.0f;

    if(_clock.getElapsedTime().asSeconds() >= _duration) {
        playTime = 0.0f;
        sf::Vector2f defaultScale(1.0f, 1.0f);

        this->setScale(defaultScale, this->getSprite());
        return true;
    }
    else if (_clock.getElapsedTime().asSeconds() >= playTime) {
        sf::Vector2f scale = this->getScale();
        
        scale.x += 0.05 / _duration;
        scale.y += 0.05 / _duration;
        playTime += 0.016; // 60 time per seconds
        this->setScale(scale, this->getSprite());
    }
    return false;
}