#include "compilador.hpp"
#include "monomio.hpp"

Compilador::Compilador(std::string expresion) : expresion(expresion)
{
}

// @TODO Implementar método.
Compilador::tokens_t Compilador::tokenizar() const
{
    return {};
}

// @TODO Implementar método.
Monomio Compilador::evaluar_token() const
{
    return {0.0, 0};
}

// @TODO Implementar método.
bool Compilador::es_valido() const
{
    return true;
}

// @TODO Implementar método.
Polinomio Compilador::compilar() const
{
    if (!this->es_valido())
        throw std::invalid_argument("La expresión no es válida.");

    auto tokens = tokenizar();
    return {{}};
}
