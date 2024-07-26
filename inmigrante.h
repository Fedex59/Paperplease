#ifndef INMIGRANTE_H
#define INMIGRANTE_H

#include "persona.h"
#include "documento.h"
#include <memory> // Para std::shared_ptr
#include <vector>
#include <string>

class Inmigrante
{
public:
    Inmigrante(const Persona& persona, std::shared_ptr<Documento> documento);

    std::string obtenerInformacion() const;
    void agregarDocumento(std::shared_ptr<Documento> documento);

    const Persona& persona() const;
    const std::vector<std::shared_ptr<Documento>>& documentos() const;

private:
    Persona m_persona;
    std::vector<std::shared_ptr<Documento>> m_documentos;
};

// función global parsearInmigrantes
std::vector<Inmigrante> parsearInmigrantes(const std::vector<std::string>& listado);

#endif // INMIGRANTE_H
