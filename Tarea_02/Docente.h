//
// Created by frubilar on 29-04-17.
//

#ifndef UNTITLED2_DOCENTE_H
#define UNTITLED2_DOCENTE_H

#include <vector>
#include <string>

using namespace std;
class Docente{

    int identificador;
    int dias[6];
    int clases[4];

public:

    Docente();
    void getDias(int numero[6]);
    void getclase(int disponible[4]);
    int getIdentificador();
    void setDias(int numero[6]);
    void setClase(int clase[4]);
    void setIdentificador(int identificador);
    int getTotalClases();
    int getDiasDisponible();
    int getLunes();
    int getMartes();
    int getMiercoles();
    int getJueves();
    int getViernes();
    int getSabado();
    void descontarHora();
};



#endif //UNTITLED2_DOCENTE_H
