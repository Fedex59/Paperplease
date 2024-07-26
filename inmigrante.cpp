#include "inmigrante.h"
#include <sstream>
#include <iomanip> // Para std::get_time
#include <string>
#include <memory>
#include <vector>
#include "persona.h"
#include "documento.h"

// Constructor
Inmigrante::Inmigrante(const Persona& persona, std::shared_ptr<Documento> documento)
    : m_persona(persona) {
    m_documentos.push_back(documento);
}

std::string Inmigrante::obtenerInformacion() const {
    std::ostringstream oss;
    oss << "Informacion del Inmigrante:\n";
    oss << m_persona.obtenerInformacion() << "\n";

    for (const auto& doc : m_documentos) {
        oss << doc->obtenerInformacion() << "\n";
    }

    return oss.str();
}

// Método para agregar un documento al inmigrante
void Inmigrante::agregarDocumento(std::shared_ptr<Documento> documento) {
    m_documentos.push_back(documento);
}

// Getters
const Persona& Inmigrante::persona() const {
    return m_persona;
}

const std::vector<std::shared_ptr<Documento>>& Inmigrante::documentos() const {
    return m_documentos;
}


std::tm parseDate(const std::string& dateStr) {
    std::tm date = {};
    std::istringstream ss(dateStr);
    ss >> std::get_time(&date, "%Y-%m-%d");
    return date;
}


std::vector<Inmigrante> parsearInmigrantes(const std::vector<std::string>& listado) {
    std::vector<Inmigrante> inmigrantes;
    std::string nombre, nacionalidad, fechaNacimiento, tipoVisa, duracionEstancia, estadoCivil;
    std::vector<std::shared_ptr<Documento>> documentos;

    for (size_t i = 0; i < listado.size(); ++i) {
        std::string linea = listado[i];
        std::istringstream iss(linea);
        std::string clave, valor;

        // Si la línea está vacía, se asume que es el final de un inmigrante
        if (linea.empty()) {
            if (!nombre.empty()) {
                Persona persona(nombre, fechaNacimiento, nacionalidad);
                Inmigrante inmigrante(persona, documentos[0]);
                for (size_t j = 1; j < documentos.size(); ++j) {
                    inmigrante.agregarDocumento(documentos[j]);
                }
                inmigrantes.push_back(inmigrante);
                documentos.clear(); // Limpiar documentos para el siguiente inmigrante
                // Reiniciar variables para el siguiente inmigrante
                nombre = nacionalidad = fechaNacimiento = tipoVisa = duracionEstancia = estadoCivil = "";
            }
        } else if (std::getline(iss, clave, ':') && std::getline(iss, valor)) {
            valor = valor.substr(valor.find_first_not_of(" \t")); // Eliminar espacios iniciales

            if (clave == "nombre") {
                nombre = valor;
            } else if (clave == "nacionalidad") {
                nacionalidad = valor;
            } else if (clave == "fecha_nacimiento") {
                fechaNacimiento = valor;
            } else if (clave == "tipo_visa") {
                tipoVisa = valor;
            } else if (clave == "duración_estancia") {
                duracionEstancia = valor;
            } else if (clave == "e_cicil") {
                estadoCivil = valor;
            } else if (clave == "documento_tipo") {
                std::string docTipo = valor;
                std::string docNumero, docFechaExpiracion, docProposito;

                // Leer las siguientes líneas para obtener la información del documento
                while (i + 1 < listado.size() && !listado[i + 1].empty()) {
                    i++;
                    std::istringstream subIss(listado[i]);
                    std::string subClave, subValor;
                    if (std::getline(subIss, subClave, ':') && std::getline(subIss, subValor)) {
                        subValor = subValor.substr(subValor.find_first_not_of(" \t"));
                        if (subClave == "documento_numero") {
                            docNumero = subValor;
                        } else if (subClave == "documento_fechaExpiracion") {
                            docFechaExpiracion = subValor;
                        } else if (subClave == "documento_proposito") {
                            docProposito = subValor;
                        }
                    }
                }

                // Crear el documento correspondiente
                if (docTipo == "pasaporte") {
                    documentos.push_back(std::make_shared<Pasaporte>(docNumero, parseDate(docFechaExpiracion)));
                } else if (docTipo == "visa") {
                    documentos.push_back(std::make_shared<Visa>(docNumero, parseDate(docFechaExpiracion), docProposito));
                }
            }
        }
    }

    // Añadir el último inmigrante si existe
    if (!nombre.empty()) {
        Persona persona(nombre, fechaNacimiento, nacionalidad);
        Inmigrante inmigrante(persona, documentos[0]);
        for (size_t j = 1; j < documentos.size(); ++j) {
            inmigrante.agregarDocumento(documentos[j]);
        }
        inmigrantes.push_back(inmigrante);
    }

    return inmigrantes;
}
