#include <frog.h>

// Constructor principal para la rana
Frog::Frog(sf::Texture& spriteSheet)
{
	// Configurar el sprite
	size = sf::Vector2f(23,17);
	skin = spriteSheet;
	
	sprite.setScale(1,1);
	sprite.setOrigin(23/2,17/2);
	sprite.setPosition(250,600-(46/2));
	sprite.setTexture(skin);
	sprite.setTextureRect(sf::IntRect(12,368,23,17));
	// Establecer vidas en 3
	iLives = 3;
	// Establecer booleanos en falso
	bCanMove = false;
	bOnLog = false;
	// Establecer propiedades de animación en falso
	bIsAnim = false;
	iFrameCount = 0;
	int iRotation = 0;
	int iDistanceX = 0;
	int iDistanceY = 0;
	
	
}


// La función de actualización que se llama cada vez que se actualiza el juego principal
void Frog::Update(sf::Vector2f windowSize, Text& text)
{
	
	// Llamar al siguiente fotograma de animación. Esto también mueve al jugador
	Animate();
	// Actualizar el texto de conteo de vidas
	text.SetText(sf::String("Vidas: " + std::to_string(iLives)));
	// Verificar si el jugador está en el agua pero no en un tronco y no se está reproduciendo una animación
	if(sprite.getPosition().y < 300 && bOnLog == false)
	{
		if(!bIsAnim)
		{
			// Matar a la rana
			Kill();
		}
	}
	// Verificar si el jugador se ha salido de la pantalla o está a punto de hacerlo
	// Matar al jugador si está fuera de la pantalla
	if(sprite.getPosition().y-size.y/2 < 0)
		{
			
			Kill();
		}
	if(sprite.getPosition().x-size.x/2 < 0 && !bIsAnim)
		{
			
			Kill();
		}
	if(sprite.getPosition().y+size.y/2 > windowSize.y)
		{
			
			Kill();
		}
	if(sprite.getPosition().x+size.x/2 > windowSize.x && !bIsAnim)
		{
			Kill();
			
		}
	// Suponer que la rana no está en un tronco
	bOnLog = false;
	
}

// Este método mueve a la rana si está en un tronco
// Toma la velocidad del tronco y la dirección en la que la rana está intersectando
void Frog::LogMove(int iSpeed, int direction)
{
	if ( direction == 1)
	{
		// Mover al jugador a la velocidad del tronco
		sprite.setPosition(sprite.getPosition().x + iSpeed,sprite.getPosition().y );
	}

	if (direction == 2)
	{
		// Mover al jugador a la velocidad del tronco
		sprite.setPosition(sprite.getPosition().x - iSpeed, sprite.getPosition().y );
	}
}

// El método para mover al jugador. Toma la entrada del teclado y decide qué hacer
void Frog::move(sf::Keyboard::Key key)
{
	// Verificar si la rana puede moverse
	if(bCanMove)
	{
		// Si se mueve hacia arriba
		if(key == sf::Keyboard::W || key == sf::Keyboard::Up)
		{
			// Detener la animación actual
			StopAnimation();
			// Configurar los parámetros para la animación hacia arriba
			iRotation = 0;
			iDistanceX = 0;
			iDistanceY = -5;
			iFinalFrame = 8;
			// Habilitar la animación
			bIsAnim = true;
	
		
		
		}
		// Si se mueve hacia la izquierda
		if(key == sf::Keyboard::A || key == sf::Keyboard::Left)
		{
			// Detener la animación actual
			StopAnimation();
			// Configurar los parámetros para la animación hacia la izquierda
			iRotation = 270;
			iDistanceX = -5;
			iDistanceY = 0;
			iFinalFrame = 10;
			// Habilitar la animación
			bIsAnim = true;
		
		
		}
		// Si se mueve hacia abajo
		if(key == sf::Keyboard::S || key == sf::Keyboard::Down)
		{
			// Detener la animación actual
			StopAnimation();
			// Configurar los parámetros para la animación hacia abajo
			iRotation = 180;
			iDistanceX = 0;
			iDistanceY = 5;
			iFinalFrame = 8;
			// Habilitar la animación
			bIsAnim = true;
	
		
		}
		// Si se mueve hacia la derecha
		if(key == sf::Keyboard::D || key == sf::Keyboard::Right)
		{
			// Detener la animación actual
			StopAnimation();
			// Configurar los parámetros para la animación hacia la derecha
			iRotation = 90;
			iDistanceX = 5;
			iDistanceY = 0;
			iFinalFrame = 10;
			// Habilitar la animación
			bIsAnim = true;
		
		}
	
	}
	
}

// Método para detener la animación actual
void Frog::StopAnimation()
{
	// Restablecer todos los parámetros de animación a sus valores predeterminados para detener la animación
	iRotation = 0;
	iDistanceX = 0;
	iDistanceY = 0;
	iFinalFrame = 0;
	bIsAnim = false;
	iFrameCount = 0;
	bCanMove = true;
}

// Método para animar y mover el sprite
void Frog::Animate()
{
	// Si la animación está reproduciéndose
	if(bIsAnim)
	{
		// Mover el sprite
		sprite.move(iDistanceX,iDistanceY);
		// Asegurarse de que el jugador no pueda moverse
		if(iFrameCount ==1)
		{
		bCanMove = false;
		}
		
		
		// Cambiar el rectángulo de textura para la animación
		if(iFrameCount == 2)
		{
			sprite.setTextureRect(sf::IntRect(46,367,22,25));
			sprite.setRotation(iRotation);

		}
		// Permitir que el jugador se mueva antes de que termine la animación. Esto permitirá una sensación más suave.
		if(iFrameCount ==6)
		{
			bCanMove = true;
		}
		// Si la animación ha terminado, detenerla y restablecer la textura a su valor predeterminado
		if(iFrameCount >= iFinalFrame)
		{
			sprite.setTextureRect(sf::IntRect(12,368,23,17));
			bIsAnim = false;
			bCanMove = true;
			iFrameCount = 0;
		
			
		}

		// Incrementar el contador de fotogramas
		iFrameCount++;
	}

	

}


// Método para matar a la rana
void Frog::Kill()
{
	// Establecer la posición de nuevo al inicio
	sprite.setPosition(250,600-(46/2));
	// Restar una vida
	iLives--;
	// Desactivar cualquier booleano actual
	bOnLog = false;
	bIsAnim = false;
	// Permitir que el jugador se mueva
	bCanMove = true;
}


// Método para cuando el jugador entra en una base
// La misma lógica que Kill pero sin restar una vida
void Frog::Base()
{
	sprite.setPosition(250,600-(46/2));
	bIsAnim = false;
	bCanMove = true;
}

// Getters y setters
int Frog::GetLives()
{
	return iLives;
}

void Frog::SetCanMove(bool b)
{
	bCanMove = b;
}

void Frog::SetLives(int i)
{
	iLives = i;
}

bool Frog::GetCanMove()
{
	return bCanMove;
}
void Frog::SetOnLog(bool b)
{
	bOnLog = b;
}
sf::FloatRect Frog::GetGlobalBounds()
{
	sf::FloatRect rect = sprite.getGlobalBounds();
	return rect;
}