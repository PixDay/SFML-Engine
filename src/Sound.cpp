/*
** 21/03/2020 Fontainebleau
** Sound.cpp
** File description:
** Adrien Colombier
*/

#include "Sound.hpp"

Sound::Sound(std::string const name, std::string const path):
_name(name),
_sound(new sf::Music())
{
    _sound->openFromFile(path);
}

Sound::~Sound()
{
}

/* SETTERS */
void Sound::setName(std::string const name)
{
    _name = name;
}

void Sound::setSound(std::string const name)
{
    _sound->openFromFile(name);
}

/* GETTERS */
std::string     Sound::getName()   const
{
    return _name;
}

sf::Music *     Sound::getSound()  const
{
    return _sound;
}