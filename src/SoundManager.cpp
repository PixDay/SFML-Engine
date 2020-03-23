/*
** 21/03/2020 Fontainebleau
** SoundManager.cpp
** File description:
** Adrien Colombier
*/

#include "SoundManager.hpp"

SoundManager::SoundManager()
{
}

void SoundManager::playSound(std::string const &name)
{
    for (auto sound : _sounds)
        if (sound.getName() == name) {
            sound.getSound()->play();
            break;
        }
}

void SoundManager::playSound(std::string const &name, bool loop)
{
    for (auto sound : _sounds)
        if (sound.getName() == name) {
            sound.getSound()->play();
            sound.getSound()->setLoop(loop);
            break;
        }
}

void SoundManager::stopSound(std::string const &name)
{
    for (auto sound : _sounds)
        if (sound.getName() == name)
            sound.getSound()->stop();
}

/* ADDERS */
void SoundManager::addSound(std::string const &name, std::string const &path)
{
    Sound sound(name, path);

    _sounds.push_back(sound);
}

void SoundManager::addSound(std::string const &name, std::string const &path, bool loop)
{
    Sound sound(name, path);
    
    sound.getSound()->setLoop(loop);
    _sounds.push_back(sound);
}

/* DELETERS */
void SoundManager::deleteSound(std::string const &name)
{
    size_t iterator = 0;

    for (auto sound : _sounds) {
        if (sound.getName() == name) {
            _sounds.erase(_sounds.begin() + iterator);
            break;
        }
        iterator++;
    }
}

/* SETTERS */
void SoundManager::setLoop(std::string const &name, bool loop)
{
    for (auto sound : _sounds)
        if (sound.getName() == name) {
            sound.getSound()->setLoop(loop);
            break;
        }
}