#include <DrawableSprite.h>

// constructor por defecto
DrawableSprite::DrawableSprite()
{	
}

// función de dibujo para que los hijos la llamen y se dibujen a sí mismos
void DrawableSprite::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	target.draw(sprite, states);
}
