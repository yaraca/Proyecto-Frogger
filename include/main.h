#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <vector>
#include <frog.h>
#include <bGround.h>
#include <vehicle.h>
#include <log.h>
#include <base.h>
#include <text.h>

using namespace std;

sf::Texture spriteSheet;
vector<Vehicle> lanes[5];
vector<Log> logs[5];
Base bases[5];
BGround bGround;
bool bGameOver;
void Draw(sf::RenderWindow &, Frog &, Text, Text);
void DrawGameOver(sf::RenderWindow &, Text, Text);
void ResetGame(Frog &);