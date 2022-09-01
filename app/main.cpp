#include <iostream>
#include <string>
#include <cstdlib>

/**
 * Función que muestra los integrantes del grupo.
 */
void integrantes();

/**
 * Taller 1 de Paralela.
 * @param argc Cantidad de argumentos.
 * @param argv Argumentos.
 * @return El código de salida del programa.
 */
int main(int argc, char **argv)
{
    if (argc > 1)
    {
        // @TODO Programar proyecto.
    }

    integrantes(); // Mostrar los integrantes.
    return EXIT_SUCCESS;
}

void integrantes()
{
    std::cout << "=== Integrantes ===\n";
    std::cout << "Catalina Ponce Puebla\n";
    std::cout << "David Uribe Fuentes\n";
}
