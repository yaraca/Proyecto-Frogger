#pragma once // para que no se duplique la clase
#include <Dibujo.hpp>
#include <Actualizable.hpp>

class Hogar : public Dibujo, public Actualizable // la Rana es un dibujo
{
private:
public:
    Hogar() : Dibujo("hogar")
    {
    }

    Hogar(int x, int y) : Dibujo(x, y, "hogar")
    { // crear vacas en diferentes posiciones
    }

    void Actualizar()
    {
        // this->x += 1;
        // this->y +=1;
    }

    void DesplazarIzquierda()
    {
        this->x -= 1;
    }

    void DesplazarDerecha()
    {
        this->x += 1;
    }
    void DesplazarArriba()
    {
        this->y -= 1;
    }
    void DesplazarAbajo()
    {
        this->y += 1;
    }

    ~Hogar() {}
};