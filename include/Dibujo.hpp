#pragma once
#include <fstream>
#include <string>
#include <iostream>
#include <curses.h>

class Dibujo
{
protected:
    int x;
    int y;

private:
    std::fstream archivo;

public:
    Dibujo()
    {
        this->x = 0;
        this->y = 0;
    }
    Dibujo(int x, int y, std::string recurso)
    { // permite asignar un valor x y inicial
        archivo.open("./data/" + recurso + ".txt");
        this->x = x;
        this->y = y;
    }
    Dibujo(std::string recurso)
    {
        archivo.open("./data/" + recurso + ".txt");
        this->x = 0;
        this->y = 0;
    }

    void Dibujar()
    {
        std::string linea;

        move(this->y, this->x); // reinicia el cursor de la pantalla
        while (std::getline(archivo, linea))
        {
            mvaddstr(getcury(stdscr) + 1,
                     this->x,
                     linea.c_str());
        }
        archivo.clear();  // limpiar variables
        archivo.seekg(0); // para que se vaya el cursor de nuevo al inicio
    }
    ~Dibujo()
    {
        archivo.close();
    }
};