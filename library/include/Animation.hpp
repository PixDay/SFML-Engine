/*
** 20/03/2020 Fontainebleau
** Animation.hpp
** File description:
** Adrien Colombier
*/

#pragma once

#include "SFML/Graphics.hpp"

class Animation
{
    public:
        Animation();
        Animation(std::vector<std::string> texturesPath, double timeToWait, double speed);
        Animation(std::vector<std::string> texturesPath, double timeToWait, double speed, bool loop);
        ~Animation() = default;

        void play(sf::Sprite * sprite);
        
        /* SETTERS */
        void setTimeToWait(double &timeToWait);
        void setSpeed(double &speed);
        void setCurrentFrame(size_t &frame);
        void setLoop(bool &loop); 
        void setName(std::string &name);

        /* GETTERS */
        bool            getLoop(void)   const;
        bool            getPlay(void)   const;
        std::string     getName(void)   const;
 
    private:
        std::vector<std::string>    _texturesPath;
        std::vector<sf::Texture>    _textures;
        sf::Clock                   _clock;
        double                      _timeToWait;
        double                      _speed;
        size_t                      _totalFrame;
        size_t                      _currentFrame;
        bool                        _loop;
        bool                        _play;
        std::string                 _name;
};