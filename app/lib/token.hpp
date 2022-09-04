#ifndef TOKEN_HPP
#define TOKEN_HPP

#include <string>
#include <regex>
#include "monomio.hpp"

class Token
{
public:
    std::string token;

    /**
     * Constructor de la clase Token.
     */
    Token(const std::string &token);

    /**
     * Función que extrae componentes de un token.
     * @param token El token a extraer.
     * @return El resultado de la extracción de componentes.
     */
    std::smatch extraer() const;

    /**
     * Función que convierte un token a monomio.
     * @return El monomio convertido a partir del token.
     */
    Monomio evaluar() const;

    /**
     * Función que determina si la expresión es válida.
     * @return true si la expresión es válida, false en caso contrario.
     */
    bool es_valido() const;

private:
    /**
     * Función que parsea el coeficiente de un monomio.
     * @param signo El token del signo del monomio.
     * @param coeficiente El token del coeficiente del monomio.
     * @return El coeficiente del monomio.
     */
    Monomio::coeficiente_t
    parse_coeficiente(const std::string &signo,
                      const std::string &coeficiente) const;

    /**
     * Función que parsea el grado de un monomio.
     * @param signo El token de la variable del monomio.
     * @param coeficiente El token del grado del monomio.
     * @return El grado del monomio.
     */
    Monomio::grado_t
    parse_grado(const std::string &variable,
                const std::string &grado) const;
};

#endif
