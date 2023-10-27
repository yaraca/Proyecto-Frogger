#include <Dibujo.hpp>
#include <curses.h>
#include <unistd.h>
#include <Ventana.hpp>
#include <list>
#include <Rana.hpp>
#include <Camion.hpp>
#include <Hogar.hpp>
#include <Carro.hpp>
using namespace std;

int main(int argc, char const *argv[])
{

    Ventana ventana;
    Rana *rana = new Rana(50, 30);
    Hogar *hogar1 = new Hogar(50, 0);
    Hogar *hogar2 = new Hogar(0, 0);
    Hogar *hogar3 = new Hogar(100, 0);

    Camion *camion1 = new Camion(0, 40);
    Carro *carro1 = new Carro(20, 100);


    list<Dibujo *> dibujos;
    dibujos.push_back(rana);
    dibujos.push_back(hogar1);
    dibujos.push_back(hogar2);
    dibujos.push_back(hogar3);
    dibujos.push_back(camion1);
    dibujos.push_back(carro1);

    list<Actualizable *> actualizables; 
    actualizables.push_back(rana);
    actualizables.push_back(hogar1);
    actualizables.push_back(hogar2);
    actualizables.push_back(hogar3);
    actualizables.push_back(camion1);

    actualizables.push_back(carro1);

    while (true)
    {

        int key = getch();
        if (key == 'q' || key == 'Q')
            break;

        if (key == 'a' || key == KEY_LEFT)
        { // se mueve izq
            rana->DesplazarIzquierda();
        }
        if (key == 'd' || key == KEY_RIGHT)
        { // se mueve der
            rana->DesplazarDerecha();
        }
        if (key == 'w' || key == KEY_UP)
        {
            rana->DesplazarArriba();
        }
        if (key == 's' || key == KEY_DOWN)
        {
            rana->DesplazarAbajo();
        }

        refresh();

        ventana.Actualizar(actualizables);
        ventana.Dibujar(dibujos);

    }



    return 0;
}
