#pragma once
#include <Dibujo.hpp>
#include <Actualizable.hpp>

class Camion : public Dibujo, public Actualizable
{
private:
    int direccion;

public:
    Camion(int x, int y) : Dibujo(x, y, "camion")
    {
        this->direccion = 1;
    }
    ~Camion() {}
    void CambiarDireccion()
    {
        this->direccion *= -1;
    }
    void Actualizar()
    {
        this->x += this->direccion;
    }
};
