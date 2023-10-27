#pragma once
#include <list>
using namespace std;

class Sprite : public Dibujo // hereda de dibujo--- sprite es un dibujo
{
private:
    int cuadroActual = 0;
    list<Dibujo *> cuadros; // tiene una lista de dibujos
public:
    Sprite(list<Dibujo *> cuadros)
    { // usa una lista de dibujos
        this->cuadros = cuadros;
    }
    void Dibujar()
    {
        this->cuadros[cuadroActual].Dibujar();
    }
    void AvanzarCuadro()
    {
    }
    ~Sprite();
};