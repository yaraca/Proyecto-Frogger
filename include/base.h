
#pragma once
#include <SFML/graphics.hpp>
#include <DrawableSprite.h>

class Base : public DrawableSprite
{
private:

	sf::FloatRect base;//Representa las dimensiones o posiciones de la base
	bool bActive;//Bandera boleana para ver si la base está activa
	bool bVisible;//Bandera bolenana para ver si la base es visible
public:

	Base(sf::Texture&, sf::FloatRect);
	Base();//Constructor por defecto
	sf::FloatRect GetBase();
	bool GetVisible();//Devuelve el valor de la bandera 
	void SetVisible(bool b);//Establece el valor de la bandera
};