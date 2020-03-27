/*
** 24/03/2020 Paris
** Transition.hpp
** File description:
** Adrien Colombier
*/

#pragma once

#include "DisplayableObject.hpp"

class Transition : public DisplayableObject
{
    public:
        Transition();
        Transition(std::string const &path, double duration);
        ~Transition() = default;

        bool playTransition(void);

    private:
        double      _duration;
        sf::Clock   _clock;
};