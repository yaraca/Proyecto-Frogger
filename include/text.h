#pragma once
#include <SFML/graphics.hpp>


class Text
{
private:
	sf::Text text;
	bool bVisible;

public:
	Text(sf::Font& font, int size, sf::String, sf::Vector2f pos, bool visible);
	sf::Text GetText();
	void SetText(sf::String);
	void SetVisible(bool b);
	bool GetVisible();
};