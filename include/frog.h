#pragma once
#include <SFML/graphics.hpp>
#include <DrawableSprite.h>
#include <text.h>
#include <iostream>


class Frog : public DrawableSprite//Herencia de DrawableSprite
{
private:

	int iLives;//Número de vidas 
	bool bOnLog;//Si Frog esta en un tronco Log
	bool bCanMove;//Si Frog se puede mover
	int iFrameCount;//COntador de fotogramas
	bool bIsAnim;//Si Frog esta animado
	int iRotation;//Rotación de Frog
	int iDistanceX;//Distancia horizontal
	int iDistanceY;//Distancia Vertical
	int iFinalFrame;//Numero de fotogramas finales
	
public:

	Frog(sf::Texture&);
	void Update(sf::Vector2f,Text&);//Actualiza el estado del Frog con una posicion y un objeto de texto
	void LogMove(int, int);//Movimiento cuando Frog esta en el tronco Log
	void SetOnLog(bool);//Establecer si Frog esta en un tronco
	void SetCanMove(bool);//Establecer si Frog puede moverse
	bool GetCanMove();//Devuelve si Frog puede moverse
	bool CheckLife();//Verificar vida
	bool CheckCollide();//Verificar si hay colisiones
	void move(sf::Keyboard::Key);//Para mover Frog con una tecla
	void moveFrog(int, float);
	sf::FloatRect GetGlobalBounds();
	void Kill();//Matar Frog
	void Base();
	int GetLives();//Devuelve el numero de vidas de Frog
	void SetLives(int);//Establece el numero de vidas de Frog
	void Animate();//Animar Frog
	void StopAnimation();//Detener animación de frog
};
