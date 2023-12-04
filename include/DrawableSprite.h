#pragma once
#include<SFML/graphics.hpp>


class DrawableSprite : public sf::Drawable//Herencia de Drawable
{
protected:
	
	sf::Vector2f position;//Posición del Sprite
	sf::Vector2f size;//Tamaño del sprite
	sf::Texture skin;//Textura del sprite
	sf::Sprite sprite;//Sprite en sí mismo

public:

	DrawableSprite();//COnstructor por defecto
	//Método virtual heredado de Drawable que se implementa para permitir que los objetos se dibujen en un RenderTarget
	void draw(sf::RenderTarget &target, sf::RenderStates states) const;
	void Update();//Actualizar el estado del objeto
	bool CheckLife();//Verificar la vida del objeto
	bool CheckCollide();//Verificar si el objeto ha colisionado con algo
	void move(sf::Keyboard::Key,sf::Vector2f);//Permite mover el objeto en funcion de una tecla y un vector de direccion
	


};
