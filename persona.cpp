#include "persona.h"
#include <sstream>

// Constructor
Persona::Persona(const std::string& nombre, const std::string& fechaNacimiento, const std::string& nacionalidad)
    : m_nombre(nombre), m_fechaNacimiento(fechaNacimiento), m_nacionalidad(nacionalidad) {}


// Función para obtener la información de la persona
std::string Persona::obtenerInformacion() const {
    std::ostringstream oss;
    oss << "Nombre: " << m_nombre << "\n"
        << "Fecha de Nacimiento: " << m_fechaNacimiento << "\n"
        << "Nacionalidad: " << m_nacionalidad;
    return oss.str();
}
