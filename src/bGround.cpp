#include <bGround.h>

BGround::BGround()
{
    //cargar fondo
    skin.loadFromFile(".\\assets\\froggerbg.png");

    //configurar sprite
    sprite.setTexture(skin);
    sprite.setScale(1,1);
    sprite.setOrigin(0,0);
    sprite.setPosition(0,0);
}