#pragma once
#include <SFML/graphics.hpp>
#include <DrawableSprite.h>
#include <text.h>
#include <iostream>

class Frog : public DrawableSprite
{
private:
    int iLives;
    bool bOnLog;
    bool bCanMove;
    int iFrameCount;
    bool bIsAnim;
    int iRotation;
    int iDistanceX;
    int iDistanceY;
    int iFinalFrame;

public:
    Frog(sf::Texture &);

    void Update(sf::Vector2f, Text &);
    void LogMove(int, int);

    void SetOnLog(bool);
    void SerCanMove(bool);
    bool GetCanMove();
    bool CheckLife();
    bool CheckCollide();
    void move(sf::Keyboard::Key);
    void moveFrog(int, float);
    sf::FloatRect GetGlobalBounds();
    void Kill();
    void Base();
    int GetLives();
    void SetLives(int);
    void Animate();
    void StopAnimation();
}