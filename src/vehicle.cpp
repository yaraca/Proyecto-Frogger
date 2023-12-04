#include <vehicle.h>

//Constructor principal
Vehicle::Vehicle(sf::Texture& tex, int x, int y, sf::IntRect TextureRect, int direction, int speed)
{
    //Configurar el sprite
    size = sf::Vector2f(TextureRect.width,TextureRect.height);
    sprite.setScale(1,1);
    sprite.setOrigin(size.x/2,size.y/2);
    sprite.setPosition(x,y);
    sprite.setTexture(tex);
    sprite.setTextureRect(TextureRect);
    //Establecer dirección y velocidad
    Vehicle::iDirection = direction;
    velocity = sf::Vector2f(1,0);
    Vehicle::iSpeed = speed;
}

//COnstructor por defecto
Vehicle::Vehicle()
{
}

//Método para mover el vehículo
void Vehicle::move()
{
    //Establecer newPos como un vector vacío
    sf::Vector2f newPos = sf::Vector2f();
    //Encontrar la dirección en la que se está moviendo el vehículo
    switch(iDirection)
    {
        case(0) :
            //Se mueve hacia arriba. Nunca se llama
            velocity.x = 0;
            velocity.y = -1*iSpeed;
            newPos = sprite.getPosition() + velocity;
            break;
        case(1) :
            //Se mueve hacia la derecha
            //Multiplicar 1 por la velocidad del vehículo para obtener la velocidad
            velocity.x = 1*iSpeed;
            velocity.y = 0;
            //Agregar la velocidad a la posición del sprite
            newPos = sprite.getPosition() + velocity;
            //Establecer la nueva posición
            sprite.setPosition(newPos);
            break;
        case(2) :
            //Se mueve hacia la izquierda
            //Multiplicar -1 por la velocidad del vehículo para obtener la velocidad
            velocity.x = -1*iSpeed;
            velocity.y = 0;
            //Agregar la velocidad a la posición del Sprite
            newPos = sprite.getPosition() + velocity;
            //Establecer la nueva posición
            sprite.setPosition(newPos);
            break;
        case(3) :
            //Se mueve hacia abajo. Nunca se llama
            velocity.x = 0;
            velocity.y = 1*iSpeed;
            newPos = sprite.getPosition() + velocity;
            sprite.setPosition(newPos);
            break;

    }
}

//Getters y Setters
sf::FloatRect Vehicle::GetGlobalBounds()
{
    sf::FloatRect rect = sprite.getGlobalBounds();
    return rect;
}

//Verificar si el vehículo se ha salido de la pantalla
bool Vehicle::CheckLife()
{
    if(sprite.getPosition().x > 550 || sprite.setPosition().x < -50)
    {
        return false;
    }
    return true;
}