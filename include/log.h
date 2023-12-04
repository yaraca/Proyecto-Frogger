#pragma once
#include<SFML/graphics.hpp>
#include<DrawableSprite.h>

class Log : public DrawableSprite
{
private:

	
	sf::Vector2f velocity;
	int iSpeed;
	int iDirection;


public:

	Log(sf::Texture&, int x, int y, sf::IntRect, int, int);
	void Update();
	bool CheckLife();
	bool CheckCollision();
	void move();
	int GetSpeed();
	int GetDirection();
	sf::FloatRect GetGlobalBounds();
};