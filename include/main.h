
#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <SFML/graphics.hpp>
#include <vector>
#include <frog.h>
#include <bGround.h>
#include <vehicle.h>
#include <log.h>
#include <base.h>
#include <text.h>


using namespace std;

sf::Texture spriteSheet;//Textura 
vector<Vehicle> lanes[5];//Arreglo de vectores de Vehicle
	vector<Log> logs[5];//Arreglo de vectores de Log
	Base bases[5];//Arreglo de objetos de Base
	BGround bGround;//Objeto de la BGround
bool bGameOver;//Indica si se termino el juego
void Draw(sf::RenderWindow&, Frog&, Text,Text);//Diseño de la ventana de inicio
void DrawGameOver(sf::RenderWindow&, Text, Text);//Diseño de la ventana al final del juego
void ResetGame(Frog&);//Reiniciar el juego