#ifndef MONOMIO_HPP
#define MONOMIO_HPP

#include <cstddef>
#include <compare>

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

    /**
     * Operador de comparaciones de igualdad y ordenamiento.
     * @param otro El monomio comparado.
     */
    auto operator<=>(const Monomio &otro) const
    {
        if (grado < otro.grado) return -1;
        if (grado > otro.grado) return 1;
        return 0;
    }

    /**
     * Operador de comparaciones de igualdad.
     * @param otro El polinomio comparado.
     */
    bool operator==(const Monomio &otro) const = default;
};

#endif
