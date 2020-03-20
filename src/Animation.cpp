/*
** 20/03/2020 Fontainebleau
** Animation.cpp
** File description:
** Adrien Colombier
*/

#include "Animation.hpp"

Animation::Animation():
_timeToWait(0.0f),
_speed(1.0f),
_totalFrame(0),
_currentFrame(0),
_loop(false),
_play(false)
{
}

Animation::Animation(std::vector<std::string> texturesPath, double timeToWait, double speed):
_texturesPath(texturesPath),
_timeToWait(timeToWait),
_speed(speed),
_totalFrame(texturesPath.size()),
_currentFrame(0),
_loop(false),
_play(false)
{
    for(auto texturePath : _texturesPath) {
        sf::Texture texture;
        texture.loadFromFile(texturePath);
        _textures.push_back(texture);
    }
        
}

Animation::Animation(std::vector<std::string> texturesPath, double timeToWait, double speed, bool loop):
_texturesPath(texturesPath),
_timeToWait(timeToWait),
_speed(speed),
_totalFrame(texturesPath.size()),
_currentFrame(0),
_loop(loop),
_play(loop)
{
    for(auto texturePath : _texturesPath) {
        sf::Texture texture;
        texture.loadFromFile(texturePath);
        _textures.push_back(texture);
    }
}

void Animation::play(sf::Sprite *sprite)
{
    sprite->setTexture(_textures[_currentFrame]);
    _currentFrame++;
    if (_currentFrame >= _totalFrame) {
        _currentFrame = 0;
        _play = _loop;
    }
}

/* SETTERS */
void Animation::setTimeToWait(double &timeToWait)
{
    _timeToWait = timeToWait;
}

void Animation::setSpeed(double &speed)
{
    _speed = speed;
}

void Animation::setCurrentFrame(size_t &frame)
{
    _currentFrame = frame;
}

void Animation::setLoop(bool &loop)
{
    _play = (_loop = loop) ? loop : _play;
}

void Animation::setName(std::string &name)
{
    _name = name;
}

/* GETTERS */
bool            Animation::getLoop(void)    const
{
    return _loop;
}

bool            Animation::getPlay(void)    const
{
    return _play;
}

std::string     Animation::getName(void)    const
{
    return  _name;
}