#pragma once
#include<SFML/graphics.hpp>


class DrawableSprite : public sf::Drawable
{
protected:
	
	sf::Vector2f position;
	sf::Vector2f size;
	sf::Texture skin;
	sf::Sprite sprite;

public:

	DrawableSprite();
	void draw(sf::RenderTarget &target, sf::RenderStates states) const;
	void Update();
	bool CheckLife();
	bool CheckCollide();
	void move(sf::Keyboard::Key,sf::Vector2f);
	


};
