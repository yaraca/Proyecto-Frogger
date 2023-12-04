#include <vehicle.h>

// constructor principal
Vehicle::Vehicle(sf::Texture& tex, int x, int y, sf::IntRect TextureRect, int direction, int speed)
{
	// configurar el sprite
	size = sf::Vector2f(TextureRect.width,TextureRect.height);
	sprite.setScale(1,1);
	sprite.setOrigin(size.x/2,size.y/2);
	sprite.setPosition(x,y);
	sprite.setTexture(tex);
	sprite.setTextureRect(TextureRect);
	// establecer dirección y velocidad
	Vehicle::iDirection = direction;
	velocity = sf::Vector2f(1,0);
	Vehicle::iSpeed = speed;
	
}
// constructor por defecto
Vehicle::Vehicle()
{
}
// método para mover el vehículo
void Vehicle::move()
{
	// establecer newPos como un Vector vacío
	sf::Vector2f newPos = sf::Vector2f();
	// encontrar la dirección en la que se está moviendo el vehículo
	switch(iDirection)
	{
	case(0) :
		// se mueve hacia arriba. nunca se llama
		velocity.x = 0;
		velocity.y = -1*iSpeed;
		newPos = sprite.getPosition() + velocity;
		break;
	case(1) : 
		// se mueve hacia la derecha
		// multiplicar 1 por la velocidad del vehículo para obtener la velocidad
		velocity.x = 1*iSpeed;
		velocity.y = 0;
		// agregar la velocidad a la posición del sprite
		newPos = sprite.getPosition() + velocity;
		// establecer la nueva posición
		sprite.setPosition(newPos);
		break;
	case(2) :
		// se mueve hacia la izquierda
		// multiplicar -1 por la velocidad del vehículo para obtener la velocidad
		velocity.x = -1*iSpeed;
		velocity.y = 0;
		// agregar la velocidad a la posición del sprite
		newPos = sprite.getPosition() + velocity;
		// establecer la nueva posición
		sprite.setPosition(newPos);
		break;
	case(3) :
		// se mueve hacia abajo. nunca se llama
		velocity.x = 0;
		velocity.y = 1*iSpeed;
		newPos = sprite.getPosition() + velocity;
		sprite.setPosition(newPos);
		break;
	}
}


// getters y setters
sf::FloatRect Vehicle::GetGlobalBounds()
{
	sf::FloatRect rect = sprite.getGlobalBounds();
	return rect;
}
// verifica si el vehículo se ha salido de la pantalla
bool Vehicle::CheckLife()
{
	if(sprite.getPosition().x > 550 || sprite.getPosition().x < -50)
	{
		return false;
	}

	
	
		return true;
	
}