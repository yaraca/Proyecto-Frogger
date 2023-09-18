#include <iostream>
#include <string>
#include <cstdio>

class Mascota
{
private:
    std::string nombre;

public:
    Mascota()
    {
        std::cout << "Ha nacido una nueva mascota. " << std::endl;
        this->nombre = "firulais";
    }
    ~Mascota()
    {
        std::cout << "Adios mundo cruel " << std::endl;
    }
    void Inicializar()
    {
        std::cout << "Ha nacido una nueva mascota. " << std::endl;
        this->nombre = "firulais";
    }
    void Destruir()
    {
        std::cout << "Adios mundo cruel " << std::endl;
    }
    void DecirNombre()
    {
        std::cout << "Mi nombre es: " << this->nombre << std::endl;
    }
};