/*
** 14/03/2020 Paris
** Cursor.hpp
** File description:
** Adrien Colombier
*/

#pragma once

#include "DisplayableObject.hpp"

class Cursor : public DisplayableObject
{
    public:
        Cursor();
        ~Cursor() = default;
        
        /* GETTERS */
        sf::Mouse   getMouse()  const;

    private:
        sf::Mouse   _mouse;
};