#include <main.h>

// Función principal
int main()
{
	// Crear objetos
	// Objeto ventana
	sf::RenderWindow window(sf::VideoMode(500,600), "Frogger");
	sf::Vector2f windowSize(window.getSize().x,window.getSize().y);
	// Objeto reloj
	sf::Clock clock;
	float fCurrentTime = clock.getElapsedTime().asSeconds();
	window.setPosition(sf::Vector2i(500,100));
	if(!spriteSheet.loadFromFile(".\\assets\\sprite_sheet.png"))
	{
		return 0;
	}
	bGameOver = false;
	sf::Font font;
	if(!font.loadFromFile(".\\assets\\fonts\\FORCEDSQUARE.TTF")) 
	{
		return 0;
	}

	Text countDown(font,100, sf::String("3"),sf::Vector2f(windowSize.x/2,windowSize.y/2), true);
	Text gameOverText(font,100,sf::String("Oh\nno!"), sf::Vector2f(windowSize.x/2-100,windowSize.y/2-200), true);
	Text gameOver2(font,20,sf::String("Presiona espacio para\nempezar de nuevo"), sf::Vector2f(windowSize.x/2-200,windowSize.y/2+200), true);
	Frog player(spriteSheet);
	Text lifeText(font, 20, sf::String("Vidas: "+ to_string(player.GetLives())),sf::Vector2f(400,560), true);
	
	// Crear objetos de vehículos predefinidos para copiar en el vector
	Vehicle v1(spriteSheet,500,487,sf::IntRect(80,264,24,26), 2, 4);
	Vehicle v2(spriteSheet,-50,442,sf::IntRect(46,265,24,24), 1, 4);
	Vehicle v3(spriteSheet, 500, 397,sf::IntRect(10,267,28,20), 2, 4);
	Vehicle v4(spriteSheet,-50,352,sf::IntRect(11,301,23,21), 1, 3);
	Vehicle v5(spriteSheet, -50, 532, sf::IntRect(11,301,23,21),1,3);
	// Crear objetos de troncos predefinidos para copiar en el vector
	Log l1(spriteSheet, -50, 262, sf::IntRect(7,198,116,21), 1, 5);
	Log l2(spriteSheet, 550, 217, sf::IntRect(7,198,116,21), 2, 4);
	Log l3(spriteSheet, -50, 172, sf::IntRect(7,198,116,21), 1, 4);
	Log l4(spriteSheet, 550, 127, sf::IntRect(7,198,116,21), 2, 5);
	Log l5(spriteSheet, -100, 82, sf::IntRect(7,167,177,23), 1, 4);
	// Crear las bases y colocarlas en el arreglo
	bases[0] = Base(spriteSheet,sf::FloatRect(5, 15, 50, 45));
	bases[1] = Base(spriteSheet,sf::FloatRect(115, 15, 50, 45));
	bases[2] = Base(spriteSheet,sf::FloatRect(225, 15, 50, 45));
	bases[3] = Base(spriteSheet,sf::FloatRect(335, 15, 50, 45));
	bases[4] = Base(spriteSheet,sf::FloatRect(445, 15, 50, 45));

	window.setVerticalSyncEnabled(true);
	// Evitar que las teclas se mantengan presionadas
	window.setKeyRepeatEnabled(false);
	
	// Bucle principal del juego
	while (window.isOpen())
	{
		// Objeto para almacenar el evento
		sf::Event event;
		// Verificar si hay eventos
		while(window.pollEvent(event))
		{
			// Cerrar la ventana cuando se presione la tecla de cierre o Escape
			if (event.type == sf::Event::Closed || event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
			{
				window.close();
			}
			// Si hay un evento de tecla
			if (event.type == sf::Event::KeyPressed)
			{
				// Almacenar el código de la tecla
				sf::Keyboard::Key key = event.key.code;
				// Si es la tecla de espacio y el juego ha terminado, reiniciar el juego
				if(key == sf::Keyboard::Space)
				{
					if(bGameOver)
					{
						// Restablecer las variables
						ResetGame(player);
						countDown.SetText(sf::String("3"));
						countDown.SetVisible(true);
						fCurrentTime = 0;
						// Reiniciar el reloj para un nuevo juego
						clock.restart();
					}
				}
				else
				{
					// Enviar el código de la tecla al jugador para moverse
					player.move(key);
				}

			}
		}
		// Estos cuatro condicionales crean la cuenta regresiva al inicio del juego
		// Esto evita que el jugador se mueva mientras los carriles pueden tener tráfico
		// Si ha pasado más de 1 segundo, quedan 2 segundos
		if(clock.getElapsedTime().asSeconds() >= 1.0f)
		{
			countDown.SetText(sf::String("2"));
			
		}
		// Si ha pasado más de 2 segundos, queda 1 segundo
		if(clock.getElapsedTime().asSeconds() >= 2.0f)
		{
			countDown.SetText(sf::String("1"));
			
		}
		// Si el tiempo transcurrido está entre 3 y 3.5 segundos, el juego comienza y el jugador puede moverse
		if(clock.getElapsedTime().asSeconds() >= 3.0f && clock.getElapsedTime().asSeconds() <= 3.5f)
		{
			player.SetCanMove(true);
			countDown.SetText(sf::String("YA!"));
			
		}
		// A partir de este momento, ocultar el texto
		if(clock.getElapsedTime().asSeconds() >= 3.5f)
		{
			countDown.SetVisible(false);
		}
		// Registrar el tiempo transcurrido
		float elapsedTime = clock.getElapsedTime().asSeconds();
		
		// Si ha pasado un segundo o más, generar un vehículo o tronco en cada carril
		if(elapsedTime - fCurrentTime >= 1.0f)
		{
			lanes[0].push_back(v1);
			lanes[1].push_back(v2);
			lanes[2].push_back(v3);
			lanes[3].push_back(v4);
			lanes[4].push_back(v5);
			logs[0].push_back(l1);
			logs[0].push_back(l2);
			logs[0].push_back(l3);
			logs[0].push_back(l4);
			logs[0].push_back(l5);
			// Restablecer el tiempo actual
			fCurrentTime = elapsedTime;
			

		}
		
		
		// Recorrer el arreglo de vectores que almacena los vehículos y realizar la lógica
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < lanes[i].size(); j++)
			{
				// Mover el vehículo
				lanes[i].at(j).move();
				// Si el vehículo se intersecta con el jugador
				if(lanes[i].at(j).GetGlobalBounds().intersects(player.GetGlobalBounds()) && player.GetCanMove())
				{
					// Matar al jugador
					player.Kill();
				}

			}
			// Recorrer en reversa el vector para eliminar elementos
			for (int j = lanes[i].size()-1; j >= 0; j--)
			{
				// Si el vehículo está fuera de la pantalla, eliminarlo del vector
				if(lanes[i].at(j).CheckLife() == false)
				{
					lanes[i].erase(lanes[i].begin()+j);
				}
			}
		}

		// Recorrer el arreglo de vectores que almacena los troncos y realizar la lógica
		for (int i = 0; i < 5; i++)
		{
			for (int j = 0; j < logs[i].size(); j++)
			{
				// Mover los troncos
				logs[i].at(j).move();
				// Si los troncos se intersectan con el jugador
				if(logs[i].at(j).GetGlobalBounds().intersects(player.GetGlobalBounds()))
				{
				
					// Establecer que el jugador está en el tronco
					player.SetOnLog(true);
					// Mover al jugador en el tronco con el que se intersecta
					player.LogMove(logs[i].at(j).GetSpeed(), logs[i].at(j).GetDirection());
				}

			}
			// Recorrer en reversa el vector para eliminar elementos
			for (int j = logs[i].size()-1; j >= 0; j--)
			{
				// Verificar si el tronco está fuera de la pantalla, eliminarlo del vector
				if(logs[i].at(j).CheckLife() == false)
				{
					logs[i].erase(logs[i].begin()+j);
				}
			
			}
		}

		// Recorrer el arreglo de bases
		for(int i = 0; i < 5; i++)
		{
			// Si el jugador se intersecta con una base
			if(player.GetGlobalBounds().intersects(bases[i].GetBase()))
			{
				// Ejecutar el método del jugador para golpear una base
				player.Base();
				// Establecer que el sprite de la base golpeada es visible
				bases[i].SetVisible(true);
	
			}
		}
	


		// Llamar a la función de actualización del jugador para actualizarlo
		player.Update(windowSize, lifeText);

		// Si el jugador se queda sin vidas, establecer el fin del juego
		if(player.GetLives() == 0)
		{
			bGameOver = true;
		}
	
		// Crear una variable para contar las bases
		int iWin = 0;
		// Recorrer el arreglo de bases
		for(int i = 0; i < 5; i++)
		{
			// Verificar si la base es visible
			if(bases[i].GetVisible() == true)
			{
				// Si es así, incrementar la variable de victoria
				iWin++;
				// Si todas las 5 bases son visibles
				if(iWin == 5)
				{
					// El juego ha terminado
					bGameOver = true;
				}
			}
		}
	
		// Si no es el fin del juego, dibujar la pantalla normal. De lo contrario, dibujar la pantalla de fin del juego
		if(!bGameOver)
		{
			Draw(window, player, countDown,lifeText);
		}
		else
		{
			DrawGameOver(window,gameOverText, gameOver2);
		}
		
		
	}
	// Salir del programa
	return 0;
	
}

// Bucle de dibujo
void Draw(sf::RenderWindow& window, Frog& player, Text text, Text livesText)
{
	// Limpiar la pantalla
	window.clear(sf::Color::Yellow);
	// Dibujar el fondo
	window.draw(bGround);
	// Recorrer los carriles de tráfico y dibujar los vehículos
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < lanes[i].size(); j++)
		{
			window.draw(lanes[i].at(j));
		}
	}
	// Recorrer los carriles de troncos y dibujar los troncos
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < logs[i].size(); j++)
		{
			window.draw(logs[i].at(j));
		}
	}
	// Dibujar las bases visibles
	for(int i = 0; i < 5; i++)
	{
		if(bases[i].GetVisible())
		{
			window.draw(bases[i]);
		}
	}
	// Dibujar al jugador
	window.draw(player);
	// Si el texto es visible, dibujarlo en la pantalla
	if(text.GetVisible())
	{
		window.draw(text.GetText());
	}
	if(livesText.GetVisible())
	{
		window.draw(livesText.GetText());
	}
	// Finalizar el bucle de dibujo
	window.display();

}

// Función de dibujo cuando el juego ha terminado
void DrawGameOver(sf::RenderWindow& window, Text text, Text text2)
{
	// Limpiar el fondo
	window.clear(sf::Color::Yellow);
	// Dibujar el fondo
	window.draw(bGround);
	// Dibujar las bases que el jugador ha alcanzado
	for(int i = 0; i < 5; i++)
	{
		if(bases[i].GetVisible())
		{
			window.draw(bases[i]);
		}
	}
	// Mostrar el texto de fin del juego
	if(text.GetVisible())
	{
		window.draw(text.GetText());
	}
	// Mostrar el texto para jugar de nuevo
	if(text2.GetVisible())
	{
		window.draw(text2.GetText());
	}
	// Finalizar el bucle de dibujo
	window.display();
}


// Función para reiniciar el juego
void ResetGame(Frog& player)
{
	// Llamar a la función de matar para reiniciar la rana
	player.Kill();
	// Establecer las vidas de nuevo a 3
	player.SetLives(3);

	// Limpiar los troncos y vehículos de sus vectores
	for (int i = 0; i < 5; i++)
	{
		logs[i].clear();
		lanes[i].clear();
	}
	// Recorrer las bases y asegurarse de que sean invisibles
	for(int i = 0; i < 5; i++)
	{
		bases[i].SetVisible(false);
	}
	// Establecer que el jugador puede moverse
	player.SetCanMove(false);
	// Establecer que el temporizador de fin del juego está en falso
	bGameOver = false;
}