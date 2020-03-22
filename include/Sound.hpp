/*
** 21/03/2020 Fontainebleau
** Sound.hpp
** File description:
** Adrien Colombier
*/

#pragma once

#include <SFML/Audio.hpp>

class Sound
{
    public:
        Sound(std::string const name, std::string const path);
        ~Sound();

        /* SETTERS */
        void setName(std::string const name);
        void setSound(std::string const name);

        /* GETTERS */
        std::string     getName()   const;
        sf::Music *     getSound()  const;

    private:
        std::string     _name;  
        sf::Music *     _sound;
};