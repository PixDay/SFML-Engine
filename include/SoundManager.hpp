/*
** 21/03/2020 Fontainebleau
** SoundManager.hpp
** File description:
** Adrien Colombier
*/

#pragma once

#include "Sound.hpp"

class SoundManager
{
    public:
        SoundManager();
        ~SoundManager() = default;

        void playSound(std::string const &name);
        void playSound(std::string const &name, bool loop);

        /* ADDERS */
        void addSound(std::string const &name, std::string const &path);
        void addSound(std::string const &name, std::string const &path, bool loop);

        /* DELETERS */
        void deleteSound(std::string const &name);

        /* SETTERS */
        void setLoop(std::string const &name, bool loop);

    private:
        std::vector<Sound>  _sounds;
};