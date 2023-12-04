#include <log.h>

//Constructor principal
Log::Log(sf::Texture& tex, int x, int y, sf::IntRect TextureRect, int direction, int speed)
{
    //Configurar Sprite
    size = sf::Vector2f(TextureRect.width,TextureRect.height);
    sprite.setScale(1,1);
    sprite.setOrigin(size.x/2,size.y/2);
    sprite.setPosition(x,y);
    sprite.setTexture(tex);
    sprite.setTextureRect(TextureRect);

    //COnfigurar dirección y velocidad
    Log::iDirection = direction;
    velocity = sf::Vector2f(1,0);
    Log::iSpeed = speed;
}

//Método para mover el tronco
void Log::move()
{
    //Establecer newPos como un vector vacío
    sf::Vector2f newPos = sf::Vector2f();
    //Encontrar la derección en la que se mueve el tronco
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
            //Multiplica 1 por la velocidad del tronco para obtener la velocidad
            velocity.x = 1*iSpeed;
            velocity.y = 0;
            //Agrega la velocidad a la posición del sprite
            newPos = sprite.getPosition() + velocity;
            //Establece la nueva posición
            sprite.setPosition(newPos);
            break;
        case(2) :
            //Se mueve hacia la izquierda
            //Multiplica 1 por la velocidad del tronco para obtener la velocidad
            velocity.x = -1*iSpeed;
            velocity.y = 0;
            //Agrega la velocidad a la posición del sprite
            newPos = sprite.getPosition() + velocity;
            //Establece la nueve posición
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

//Verifica si el tronco todavía está en la pantalla
bool Log::CheckLife()
{
    if(sprite.getPosition().x > 700 || sprite.getPosition().x < -200)
    {
        return false;
    }

    return true;
}

//Getters y setters
sf::FloatRect Log::GetGlobalBounds()
{
    sf::FloatRect rect = sprite.getGlobalBounds();
    return rect;
}

int Log::GetSpeed()
{
    return iSpeed;
}

int Log::GetDirection()
{
    return iDirection;
}