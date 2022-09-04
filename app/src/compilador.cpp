#include <iostream>
#include <charconv>
#include <regex>
#include <algorithm>
#include "compilador.hpp"
#include "monomio.hpp"

#define PATRON_MONOMIO "^([\\-\\+])?\\s*(\\d*\\.?\\d+)?(?:(x)(?:(?:\\*\\*)([0-9]))?)?\\s*$"
#define PATRON_POLINOMIO "([\\+\\-]?[^\\-\\+]+)"

const std::regex Compilador::patron_monomio(PATRON_MONOMIO);
const std::regex Compilador::patron_polinomio(PATRON_POLINOMIO);

Compilador::Compilador(const std::string &expresion) : expresion(expresion)
{
}

Compilador::tokens_t Compilador::separar() const
{
    Compilador::tokens_t tokens;
    auto inicio = std::sregex_iterator(this->expresion.begin(), this->expresion.end(),
                                       Compilador::patron_polinomio);
    auto fin = std::sregex_iterator();

    for (auto match = inicio; match != fin; ++match)
        tokens.push_back(match->str());

    return tokens;
}

std::smatch Compilador::extraer_token(const std::string &token) const
{
    return *std::sregex_iterator(token.begin(), token.end(),
                                 Compilador::patron_monomio);
}

// @TODO Implementar método.
Monomio Compilador::evaluar_token(const std::string &token) const
{
    if (!this->es_token_valido(token))
        throw std::invalid_argument("El token no es válido: " + token);

    auto match = this->extraer_token(token);

    auto coeficiente = this->parse_coeficiente(match[TipoToken::SIGNO],
                                               match[TipoToken::COEFICIENTE]);

    auto grado = this->parse_grado(match[TipoToken::VARIABLE],
                                   match[TipoToken::GRADO]);

    return {coeficiente, grado};
}

Monomio::coeficiente_t
Compilador::parse_coeficiente(const std::string &token_signo,
                              const std::string &token_coeficiente) const
{
    // Si el token del coeficiente está vacío, el coeficiente es 1.0.
    auto token_coeficiente_explicito = token_coeficiente.empty() ? "1.0" : token_coeficiente;
    return std::stod(token_signo + token_coeficiente_explicito);
}

Monomio::grado_t
Compilador::parse_grado(const std::string &token_variable,
                        const std::string &token_grado) const
{
    // Si el token del grado está vacío, el grado es 0 si, a su vez, el token de
    // la variable está vacío, y 1 en caso contrario.
    // Ej: "2" -> grado 0, "2x" -> grado 1.
    if (token_grado.empty())
        return !token_variable.empty();

    return std::stoul(token_grado);
}

bool Compilador::es_token_valido(const std::string &token) const
{
    return std::regex_match(token, Compilador::patron_monomio);
}

Polinomio Compilador::compilar() const
{
    Polinomio::terminos_t terminos;
    auto separado = this->separar();

    std::transform(separado.begin(), separado.end(),
                   std::back_inserter(terminos),
                   [this](const std::string &token)
                   { return this->evaluar_token(token); });

    return {terminos};
}
