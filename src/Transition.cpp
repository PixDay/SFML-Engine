/*
** 24/03/2020 Paris
** Transition.cpp
** File description:
** Adrien Colombier
*/

#include "Transition.hpp"

Transition::Transition():
_duration(0.8)
{
    sf::Vector2f origin(64.0f, 64.0f);
    sf::Vector2f position(960.0f, 540.0f);

    this->setLayout(100);
    this->setTexture("img/transition/star-transition.png");
    this->setOrigin(origin, this->getSprite());
    this->setPosition(position, this->getSprite());
    this->setTag("transition");
}

Transition::Transition(std::string const &path, double duration):
_duration(duration)
{
    sf::Vector2u size;
    sf::Vector2f origin;
    sf::Vector2f position(960.0f, 540.0f);

    this->setLayout(100);
    this->setTexture(path);
    size = this->getTexture().getSize();
    origin.x = ((float)size.x) / 2.0f;
    origin.y = ((float)size.y) / 2.0f;
    this->setOrigin(origin, this->getSprite());
    this->setPosition(position, this->getSprite());
    this->setTag("transition");
}

bool Transition::playTransition(void)
{
    static float playTime = 0.0f;

    if (playTime <= 0.01f)
        _clock.restart();
    if(_clock.getElapsedTime().asSeconds() >= _duration) {
        playTime = 0.0f;
        sf::Vector2f defaultScale(1.0f, 1.0f);
        this->setScale(defaultScale, this->getSprite());
        return true;
    }
    else if (_clock.getElapsedTime().asSeconds() >= playTime) {
        sf::Vector2f scale = this->getSprite()->getScale();
        
        scale.x += 1.2 / _duration;
        scale.y += 1.2 / _duration;
        playTime += 0.016; // 60 times per second
        this->setScale(scale, this->getSprite());
    }
    return false;
}