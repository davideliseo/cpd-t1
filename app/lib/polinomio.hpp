#ifndef POLINOMIO_HPP
#define POLINOMIO_HPP

#include <vector>
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
};

#endif
