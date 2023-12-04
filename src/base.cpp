
#include <base.h>
// constructor principal
Base::Base(sf::Texture& spriteSheet, sf::FloatRect rect)
{
	// configurar sprite
	sprite.setScale(1,1);
	sprite.setOrigin(23/2,17/2);
	sprite.setPosition(rect.left+rect.width/2,rect.top+rect.height/2);
	sprite.setTexture(spriteSheet);
	sprite.setTextureRect(sf::IntRect(12,368,23,17));
	// límites del rectángulo de la base
	base = rect;
	// activo pero no visible
	bActive = true;
	bVisible = false;
}
// constructor por defecto
Base::Base()
{
}
// getters y setters
sf::FloatRect Base::GetBase()
{
	return base;
}

bool Base::GetVisible()
{
	return bVisible;
}

void Base::SetVisible(bool b)
{
	bVisible = b;
}