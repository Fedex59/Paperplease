#ifndef ARCHIVO_H
#define ARCHIVO_H

#include <vector>
#include <string>

class Archivo
{
public:
    Archivo();
    std::string procesarRuta(const std::string& nombreArchivo);
    std::vector<std::string> leer(const std::string& nombreArchivo);
    void guardar(const std::string& nombreArchivo, const std::vector<std::string>& contenido);
};

#endif // ARCHIVO_H
