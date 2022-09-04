#include <iostream>
#include <charconv>
#include <regex>
#include <algorithm>
#include "token.hpp"
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
        tokens.push_back({match->str()});

    return tokens;
}

Polinomio Compilador::compilar() const
{
    Polinomio::terminos_t terminos;
    auto separado = this->separar();

    std::transform(separado.begin(), separado.end(),
                   std::back_inserter(terminos),
                   [](const Token &token)
                   { return token.evaluar(); });

    return {terminos};
}
