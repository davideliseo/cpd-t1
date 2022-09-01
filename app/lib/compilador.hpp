#ifndef COMPILADOR_HPP
#define COMPILADOR_HPP

#include <string>
#include "polinomio.hpp"

class Compilador
{
public:
    using token_t = std::string;
    using tokens_t = std::vector<token_t>;

    std::string expresion;

    /**
     * Constructor de la clase Compilador.
     */
    Compilador(std::string expresion);

    /**
     * Función que determina si la expresión es válida.
     * @return Verdadero si la expresión es válida, falso en caso contrario.
     */
    bool valido() const;

    /**
     * Función que compila la expresión en un polinomio.
     * @return El polinomio compilado a partir de la expresión.
     */
    Polinomio compilar() const;

private:
    /**
     * Función que separa la expresión en tokens.
     * @return Los tokens extraídos de la expresión.
     */
    tokens_t tokenizar() const;

    /**
     * Función que convierte un token a monomio.
     * @return El monomio convertido a partir del token.
     */
    Monomio evaluarToken() const;
};

#endif
