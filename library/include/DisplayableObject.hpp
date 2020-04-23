/*
** 13/03/2020 Paris
** DisplayableObject.hpp
** File description:
** Adrien Colombier
*/

#pragma once

#include "GameObject.hpp"
#include "Animator.hpp"

class DisplayableObject : public GameObject
{
    public:
        DisplayableObject();
        DisplayableObject(std::string const &texture);
        DisplayableObject(std::string const &texture, void (function)(DisplayableObject *));
        ~DisplayableObject();

        void update();
        
        /* ADDERS */
        void addAnimation(std::vector<std::string> &frames, float timeToWait, float speed, bool loop);
        void addObject(DisplayableObject *object);

        /* DELETERS */
        void deleteAnimation(std::string &name);
        void deleteObject(std::string const &tag);

        /* SETTERS */
        void setTexture(std::string const &texture);
        void setTexture(sf::Texture const &texture);
        void setOrigin(sf::Vector2f const &origin, sf::Sprite *sprite);
        void setScale(sf::Vector2f const &scale, sf::Sprite *sprite);
        void setDimension(sf::Vector2f const &hitbox);
        void setDimension(size_t const &x, size_t const &y);
        void setAngle(float const &angle);
        void setAngleCenter(float const &angle);
        void setFunction(void (function)(DisplayableObject *));
        void setVisibleTime(float time);

        /* GETTERS */
        sf::Sprite *                        getSprite(void)     const;
        sf::Texture                         getTexture(void)    const;
        sf::Vector2f                        getDimension(void)  const;
        float                               getAngle(void)      const;
        std::vector<DisplayableObject *>    getObjects()        const;

    private:
        sf::Sprite *                        _sprite;
        sf::Texture                         _texture;
        sf::Vector2f                        _origin;
        sf::Vector2f                        _scale;
        sf::Vector2f                        _hitbox;
        sf::Clock                           _clock;
        float                               _angle;
        float                               _visibleTime;
        Animator                            _animator;
        void                                (*_function)(DisplayableObject *test);
        std::vector<DisplayableObject *>    _objects;
};