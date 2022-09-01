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
     * Función que calcula el derivado del monomio.
     * @return El derivado del monomio.
     */
    Monomio derivado() const;
};

#endif
