#ifndef PERSONA_H
#define PERSONA_H

#include <string>


class Persona
{
public:
    Persona(const std::string& nombre, const std::string& fechaNacimiento, const std::string& nacionalidad);

    virtual std::string obtenerInformacion() const;

protected:
    std::string m_nombre;
    std::string m_fechaNacimiento;
    std::string m_nacionalidad;
};

#endif // PERSONA_H
