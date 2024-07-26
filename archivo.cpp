#include "archivo.h"
#include <iostream>
#include <fstream>
#include <filesystem>
#include <regex>

Archivo::Archivo() {}

// Funcion para procesar archivos

std::vector<std::string> Archivo::leer(const std::string& nombreArchivo) {
    std::vector<std::string> miArchivo;

    std::string rutaAbsolutaStr = procesarRuta(nombreArchivo);

    std::ifstream archivo(rutaAbsolutaStr);
    if (archivo.is_open()) {
        std::cout << "Leyendo archivo: " << nombreArchivo << std::endl;
        std::string linea;
        while (std::getline(archivo, linea)) {
            miArchivo.push_back(linea);
        }
        archivo.close();
    } else {
        std::cerr << "No se pudo abrir el archivo: " << nombreArchivo << std::endl;
    }
    return miArchivo;
}

void Archivo::guardar(const std::string& nombreArchivo, const std::vector<std::string>& contenido) {
    std::string rutaAbsolutaStr = procesarRuta(nombreArchivo);

    std::ofstream archivo(rutaAbsolutaStr);
    if (archivo.is_open()) {
        std::cout << "Guardando en archivo: " << nombreArchivo << std::endl;
        for (const auto& linea : contenido) {
            archivo << linea << std::endl;
        }
        archivo.close();
    } else {
        std::cerr << "No se pudo abrir el archivo para escribir: " << nombreArchivo << std::endl;
    }
}


// Eliminar luego de configurar la carpeta build correctamente
std::string Archivo::procesarRuta(const std::string& nombreArchivo) {
    std::filesystem::path rutaBase = std::filesystem::current_path();
    std::filesystem::path rutaAbsoluta = rutaBase / nombreArchivo;

    std::cout << "Leyendo archivo preeee: " << rutaBase << std::endl;

    std::string rutaAbsolutaStr = rutaAbsoluta.string();
    std::replace(rutaAbsolutaStr.begin(), rutaAbsolutaStr.end(), '\\', '/');

    // Eliminar la parte de build si existe
    std::regex re("/build/[^/]+");
    rutaAbsolutaStr = std::regex_replace(rutaAbsolutaStr, re, "");

    // Volver a convertir las barras normales a barras invertidas para Windows
    std::replace(rutaAbsolutaStr.begin(), rutaAbsolutaStr.end(), '/', '\\');

    std::cout << "Ruta absoluta del archivo: " << rutaAbsolutaStr << std::endl;
    return rutaAbsolutaStr;
}
