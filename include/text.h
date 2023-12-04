#pragma once
#include <SFML/graphics.hpp>


class Text
{
private:
	sf::Text text;//Contenido y estilo del texto
	bool bVisible;//Indica si el texto es visible o no

public:
	//Constructor que inicializa text con una fuente, tamaño, las palabras, posición y un indicador de visibilidad
	Text(sf::Font& font, int size, sf::String, sf::Vector2f pos, bool visible);
	sf::Text GetText();//Devuelve el texto
	void SetText(sf::String);//Establece el contenido de texto 
	void SetVisible(bool b);//Establece la visibilidad del texto
	bool GetVisible();//devuelve la visibilidad actual del texto
};