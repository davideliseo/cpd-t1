#ifndef COMPILADOR_HPP
#define COMPILADOR_HPP

#include <string>
#include <regex>
#include "token.hpp"
#include "polinomio.hpp"

/**
 * Tipos de tokens que se pueden encontrar en una expresión de monomio.
 */
enum TipoToken
{
    EXPRESION = 0,
    SIGNO,
    COEFICIENTE,
    VARIABLE,
    GRADO,
};

class Compilador
{
public:
    using tokens_t = std::vector<Token>;

    std::string expresion;

    /**
     * Patrón de un monomio.
     */
    static const std::regex patron_monomio;

    /**
     * Patrón de un polinomio.
     */
    static const std::regex patron_polinomio;

    /**
     * Constructor de la clase Compilador.
     */
    Compilador(const std::string &expresion);

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
    tokens_t separar() const;

    /**
     * Función que adapta la expresión para ser tokenizada.
     * @return La expresión adaptada.
     */
    std::string procesar() const;
};

#endif
