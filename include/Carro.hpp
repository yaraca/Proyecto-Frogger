#pragma once
#include <Dibujo.hpp>
#include <Actualizable.hpp>

class Carro : public Dibujo, public Actualizable
{
private:
    int direccion;

public:
    Carro(int x, int y) : Dibujo(x, y, "carro")
    {
        this->direccion = 1;
    }
    ~Carro() {}
    void CambiarDireccion()
    {
        this->direccion *= -1;
    }
    void Actualizar()
    {
        this->x += this->direccion;
    }
};