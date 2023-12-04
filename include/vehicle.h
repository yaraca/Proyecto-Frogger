#pragma once
#include <SFML/graphics.hpp>
#include <DrawableSprite.h>


class Vehicle : public DrawableSprite//Herencia de DrawableSrite
{
private:
	
	sf::Vector2f velocity;//Velocidad bidimensional
	int iSpeed;//Velocidad escalar
	int iDirection;//Direccion


public:
	//Constructor que inicializa con una textura, coordenadas, velocidad, direccion
	Vehicle(sf::Texture&, int x, int y, sf::IntRect, int, int);
	Vehicle();//Cosntructor por defecto
	void Update();;//Actualiza el estado de Vehicle
	bool CheckLife();//Verifica la vida
	bool CheckCollide();//Verificar colisiones
	void move();//Realiza el movimiento
	sf::FloatRect GetGlobalBounds();
	

};
