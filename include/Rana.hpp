#pragma once //para que no se duplique la clase
#include <Dibujo.hpp>
#include <Actualizable.hpp>



class Rana : public Dibujo, public Actualizable//la Rana es un dibujo
{
private:
    
public:
    Rana() : Dibujo("rana"){
    }

    Rana(int x, int y) : Dibujo(x,y,"rana"){//crear vacas en diferentes posiciones
    }
    
    void Actualizar()
    {
        //this->x += 1;
        //this->y +=1;
    }

    void DesplazarIzquierda(){
        this->x -= 1;
    }

    void DesplazarDerecha(){
        this->x += 1;
    }
    void DesplazarArriba(){
        this->y-=1;
    }
    void DesplazarAbajo(){
        this->y+=1;
    }

    ~Rana(){}
};