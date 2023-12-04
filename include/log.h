#pragma once
#include<SFML/graphics.hpp>
#include<DrawableSprite.h>

class Log : public DrawableSprite//Herencia de DrawableSprite
{
private:

	sf::Vector2f velocity;//Velocidad de los troncos
	int iSpeed;//Velocidad escalar de Log
	int iDirection;//Dirección en la que se mueve


public:

	//Constructor que inicializa Log con una textura, coordenas
	Log(sf::Texture&, int x, int y, sf::IntRect, int, int);
	void Update();//Actualiza el estado de Log
	bool CheckLife();//Verifica la vida de log
	bool CheckCollision();//Verifica si hay alguna colisión
	void move();//Realiza el movimiento de Log
	int GetSpeed();//Devuelve la velocidad de log
	int GetDirection();//Devuelve la dirección de log
	sf::FloatRect GetGlobalBounds();//Devuelve los límites globales 
};