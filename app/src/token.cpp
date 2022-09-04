#include <regex>
#include "token.hpp"
#include "compilador.hpp"

Token::Token(const std::string &token) : token(token)
{
}

std::smatch Token::extraer() const
{
    return *std::sregex_iterator(this->token.begin(), this->token.end(),
                                 Compilador::patron_monomio);
}

Monomio Token::evaluar() const
{
    if (!this->es_valido())
        throw std::invalid_argument("El token no es válido: " + this->token);

    auto match = this->extraer();

    auto coeficiente = this->parse_coeficiente(match[TipoToken::SIGNO],
                                               match[TipoToken::COEFICIENTE]);

    auto grado = this->parse_grado(match[TipoToken::VARIABLE],
                                   match[TipoToken::GRADO]);

    return {coeficiente, grado};
}

Monomio::coeficiente_t
Token::parse_coeficiente(const std::string &signo,
                         const std::string &coeficiente) const
{
    // Si el token del coeficiente está vacío, el coeficiente es 1.0.
    auto coeficiente_explicito = coeficiente.empty() ? "1.0" : coeficiente;
    return std::stod(signo + coeficiente_explicito);
}

Monomio::grado_t
Token::parse_grado(const std::string &variable,
                   const std::string &grado) const
{
    // Si el token del grado está vacío, el grado es 0 si, a su vez, el token de
    // la variable está vacío, y 1 en caso contrario.
    // Ej: "2" -> grado 0, "2x" -> grado 1.
    if (grado.empty())
        return !variable.empty();

    return std::stoul(grado);
}

bool Token::es_valido() const
{
    return std::regex_match(token, Compilador::patron_monomio);
}
