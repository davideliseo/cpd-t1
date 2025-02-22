#include <iostream>
#include <string>
#include <cstdlib>
#include "compilador.hpp"
#include "polinomio.hpp"

/**
 * Función que imprime un titulo con formato.
 * @param titulo Titulo.
 */
void titulo(std::string titulo);

/**
 * Función que muestra los integrantes del grupo.
 */
void integrantes();

/**
 * Función que a partir de una expresión, la compila en un polinomio y
 * encuentra la solución de dicho polinomio.
 */
void resolver(std::string expresion);

/**
 * Función principla del Taller 1 de CPyD.
 * @param argc Cantidad de argumentos.
 * @param argv Argumentos.
 * @return El código de salida del programa.
 */
int main(int argc, char **argv)
{
    if (argc > 1)
    {
        titulo("Resultados");
        std::string expresion = argv[1];
        std::cout << "Expresión: " << expresion << '\n';
        resolver(expresion);
    }

    integrantes();
    return EXIT_SUCCESS;
}

void titulo(std::string titulo)
{
    std::cout << "=== " << titulo << " ===\n";
}

void resolver(std::string expresion)
{
    auto compilador = Compilador(expresion);
    auto polinomio = compilador.compilar();
    auto solucion = polinomio.raiz();
    std::cout << "Solución: " << solucion << '\n';
}

void integrantes()
{
    titulo("Integrantes");
    std::cout << "Catalina Ponce Puebla\n";
    std::cout << "David Uribe Fuentes\n";
}
