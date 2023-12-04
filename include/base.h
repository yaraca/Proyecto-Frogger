#pragma once
#include <SFML/graphics.hpp>
#include <DrawableSprite.h>

class Base : public DrawableSprite
{
    private:

    sf::FloatRect base;
    bool bActive;
    bool bVisible;
    public:

    Base(sf::Texture&, sf::FloatRect);
    Base();
    sf::FloatRect GetBase();
    bool GetVisible();
    void SetVisible(bool b);
}