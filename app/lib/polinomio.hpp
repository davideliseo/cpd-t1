#ifndef POLINOMIO_HPP
#define POLINOMIO_HPP

#include <vector>
#include <compare>
#include "monomio.hpp"

class Polinomio
{
public:
    using terminos_t = std::vector<Monomio>;
    terminos_t terminos;

    /**
     * Constructor de la clase Polinomio.
     */
    Polinomio(terminos_t terminos);

    /**
     * Función que calcula la raíz del polinomio utilizando el método Newton-Raphson.
     * @return La raíz del polinomio.
     */
    double resolver() const;

    /**
     * Función que calcula el derivado del polinomio.
     * @return El derivado del polinomio.
     */
    Polinomio derivado() const;

    /**
     * Operador de comparaciones de ordenamiento.
     * @param otro El polinomio comparado.
     */
    auto operator<=>(const Polinomio &otro) const {
        if (terminos < otro.terminos) return -1;
        if (terminos > otro.terminos) return 1;
        return 0;
    }

    /**
     * Operador de comparaciones de igualdad.
     * @param otro El polinomio comparado.
     */
    bool operator==(const Polinomio &otro) const = default;
};

#endif
