#include <iostream>
#include <Mascota.hpp>

int main(int argc, char const *argv[])
{
    // Mascota m1;
    // Mascota m2;

    // m1.Comer();
    // m2.Comer();

    // std::cout<<"Mensaje"<<std::endl;
    std::cout << "Tipos de datos" << std::endl;
    std::cout << "int" << sizeof(int) << std::endl;
    std::cout << "char" << sizeof(char) << std::endl;
    std::cout << "bool" << sizeof(bool) << std::endl;
    std::cout << "float" << sizeof(float) << std::endl;
    std::cout << "double" << sizeof(double) << std::endl;
    std::cout << "Mascota" << sizeof(Mascota) << std::endl;

    std::cout << std::endl
              << std::endl;
    std::cout << "Direcciones de memoria" << std::endl;
    int a = 4;
    std::cout << "Tamaño:" << sizeof(a) << std::endl;
    std::cout << "Contenido:" << a << std::endl;
    std::cout << "Direccion:" << &a << std::endl;

    void *puntero = malloc(32); // reservar memoria, memory allocation

    free(puntero); // liberar memoria para que el sistema operativo la pueda utilizar

    
    std::cout << "Direcciones de memoria" << std::endl;
    std::cout << "Size of:" << sizeof(puntero) << std::endl;
    std::cout << "puntero1" << puntero << std::endl;
    std::cout << "puntero2" << &puntero << std::endl;

    //free(puntero); // liberar memoria para que el sistema operativo la pueda utilizar

    // memoria dinamica en C
    std::cout << "\nMascota en C" << std::endl;
    Mascota *mascotaC = (Mascota *)malloc(sizeof(Mascota)); // reservar un tamaño de memoria de un entero
    // Mascota* puntero2 = malloc(sizeof(Mascota));//reserva el tamaño con la cantidad de mascota
    mascotaC->Inicializar();
    mascotaC->DecirNombre();
    mascotaC->Destruir();
    free(mascotaC);

    //////////////////////////////////////////////////////////////
    
        // memoria dinamica C++
    std::cout << "\nMascota en C++" << std::endl;
    Mascota *mascotaCPP = new Mascota();
    mascotaCPP->DecirNombre();
    delete mascotaCPP;
    

    //int a;
    //std::cout << "tamaño void: " << sizeof(Mascota) << std::endl;


    return 0;
}
