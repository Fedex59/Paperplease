#include "documento.h"
#include <sstream>

// Utilidad para formatear fechas
std::string formatDate(const std::tm& date) {
    char buffer[11]; // Buffer para "YYYY-MM-DD" + '\0'
    std::strftime(buffer, sizeof(buffer), "%Y-%m-%d", &date);
    return std::string(buffer);
}

Documento::Documento(const std::string& numero, const std::tm& fechaExpiracion)
    : m_numero(numero), m_fechaExpiracion(fechaExpiracion) {}



bool Documento::esValido() const {
    // Suponemos que un documento es válido si la fecha de expiración es en el futuro
    std::time_t t = std::time(nullptr);
    std::tm* now = std::localtime(&t);

    if (m_fechaExpiracion.tm_year > now->tm_year) return true;
    if (m_fechaExpiracion.tm_year == now->tm_year && m_fechaExpiracion.tm_mon > now->tm_mon) return true;
    if (m_fechaExpiracion.tm_year == now->tm_year && m_fechaExpiracion.tm_mon == now->tm_mon && m_fechaExpiracion.tm_mday > now->tm_mday) return true;

    return false;
}

Pasaporte::Pasaporte(const std::string& numero, const std::tm& fechaExpiracion)
    : Documento(numero, fechaExpiracion) {}

std::string Pasaporte::tipo() const {
    return "Pasaporte";
}

std::string Pasaporte::obtenerInformacion() const {
    std::ostringstream oss;
    oss << "Tipo: " << tipo() << "\n"
        << "Numero: " << m_numero << "\n"
        << "Fecha de Expiracion: " << formatDate(m_fechaExpiracion) << "\n"
        << "Valido: " << (esValido() ? "Si" : "No");
    return oss.str();
}

Visa::Visa(const std::string& numero, const std::tm& fechaExpiracion, const std::string& tipoVisa)
    : Documento(numero, fechaExpiracion), m_tipoVisa(tipoVisa) {}

std::string Visa::tipo() const {
    return "Visa";
}

std::string Visa::obtenerInformacion() const {
    std::ostringstream oss;
    oss << "Tipo: " << tipo() << "\n"
        << "Numero: " << m_numero << "\n"
        << "Fecha de Expiracion: " << formatDate(m_fechaExpiracion) << "\n"
        << "Tipo de Visa: " << m_tipoVisa << "\n"
        << "Valido: " << (esValido() ? "Si" : "No");
    return oss.str();
}
