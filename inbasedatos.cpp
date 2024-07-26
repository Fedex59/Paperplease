#include "inbasedatos.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <QString>

using namespace std;

inbasedatos::inbasedatos()
{

}

void inbasedatos::copiar_datos(vector<QString> text, int tamanio){
    for(int i=0; i<tamanio; i++){

        //copiar
        for(int j=i+1; j<9; j++){
            if(text[j].contains("vericidad: ") != 0){
                vericidad1 = text[j].toStdString();
            }else{
                datos1.push_back(text[j]);
            }

        }
        i = i+10;
        for(int j=i+1; j<9; j++){
            if(text[j].contains("vericidad: ") != 0){
                vericidad2 = text[j].toStdString();
            }else{
                datos2.push_back(text[j]);
            }
        }
        i = i+10;
        for(int j=i+1; j<9; j++){
            if(text[j].contains("vericidad: ") != 0){
                vericidad3 = text[j].toStdString();
            }else{
                datos3.push_back(text[j]);
            }
        }
        i = i+10;

    }
}

void inbasedatos::leer_archivo(int niv){
    ifstream inbase_file;
    inbase_file.open("datbase1.txt");

    if(inbase_file.fail()){
        cout << "fallo al abrir datos file" << endl;
    }else{
        cout << "abrio datos" << endl;

        vector<QString> texto;
        int c=0;
        while(!inbase_file.eof()){
            string aux;
            getline(inbase_file, aux);
            texto.push_back(QString::fromStdString(aux));
            c++;
        }

        copiar_datos(texto, c);

        inbase_file.close();
    }

    return;
}
