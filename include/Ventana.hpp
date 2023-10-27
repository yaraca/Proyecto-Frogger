#include <curses.h>
#include <unistd.h>
#include <list>
#include <Actualizable.hpp>

using namespace std;

class Ventana
{
private:
public:
    Ventana()
    {
        initscr();
        noecho();
        curs_set(FALSE);
        cbreak();
        keypad(stdscr, TRUE);
        timeout(10);
    }

    void Actualizar(list<Actualizable *> actualizables)
    {
        for (auto &&actualizable : actualizables)
        {
            actualizable->Actualizar();
        }

        usleep(41000);
    }

    void Dibujar(list<Dibujo *> dibujos)
    {
        clear();
        for (auto &&dibujo : dibujos)
        {
            dibujo->Dibujar();
        }

        box(stdscr, '=', '?');
        refresh();
    }

    ~Ventana()
    {
        keypad(stdscr, FALSE);
        endwin();
    }
};