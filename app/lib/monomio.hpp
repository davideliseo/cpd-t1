#ifndef MONOMIO_HPP
#define MONOMIO_HPP

#include <cstddef>

class Monomio
{
public:
    using coeficiente_t = double;
    using grado_t = size_t;

    coeficiente_t coeficiente;
    grado_t grado;

    /**
     * Constructor de la clase Monomio.
     */
    Monomio(coeficiente_t coeficiente, grado_t grado);

    /**
     * Función que indica si el monomio es cero.
     * @return true si el monomio es cero, false en caso contrario.
     */
    bool esCero() const;

    /**
     * Función que determina si el monomio es constante.
     * @return true si el monomio es constante, false en caso contrario.
     */
    bool esConstante() const;

    /**
     * Función que calcula el derivado del monomio.
     * @return El derivado del monomio.
     */
    Monomio derivado() const;
};

#endif
