#pragma once 
#include <SFML/graphics.hpp>
#include <DrawableSprite.h>

class Vehicle : public DrawableSprite
{
private:
    sf::Vector2f velocity;
    int iSpeed;
    int iDirection;

public:
    Vehicle(sf::Texture&, int x, int y, sf::IntRect, int, int);
    Vehicle();
    void Update();
    bool CheckLife();
    bool CheckCollide();
    void move();
    sf::FloatRect GetGlobalBounds();
};


