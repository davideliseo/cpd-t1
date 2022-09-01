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
Monomio Compilador::evaluarToken() const
{
    return Monomio(0, 0);
}

// @TODO Implementar método.
bool Compilador::valido() const
{
    return true;
}

// @TODO Implementar método.
Polinomio Compilador::compilar() const
{
    if (!this->valido())
    {
        throw std::invalid_argument("La expresión no es válida.");
    }

    auto tokens = tokenizar();
    return Polinomio({});
}
