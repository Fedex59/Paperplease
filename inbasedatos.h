#ifndef INBASEDATOS_H
#define INBASEDATOS_H
#include <iostream>
#include <vector>
#include <string>
#include <QString>

using namespace std;

class inbasedatos
{
public:
    vector<QString> datos1;
    string vericidad1;
    vector<QString> datos2;
    string vericidad2;
    vector<QString> datos3;
    string vericidad3;

    void copiar_datos(vector<QString> text, int tamanio);
    void leer_archivo(int niv);

    inbasedatos();

};

#endif // INBASEDATOS_H
