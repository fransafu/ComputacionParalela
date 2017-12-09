//
// Created by frubilar on 29-04-17.
//

#include "Docente.h"
#include <vector>
#include <string>

using namespace std;

Docente::Docente() {
    identificador = 0;
    for (int i = 0; i<6;i++){
        dias[i]=0;
        if(i<4){
            clases[i]=0;
        }
    }
}


void Docente::getDias(int *numero) {
    for (int i = 0; i < 6; i++) {
        numero[i] = dias[i];
    }
}

void Docente::getclase(int *disponible) {
    for (int i = 0; i < 4; i++) {
        disponible[i] = clases[i];
    }
}

void Docente::setClase(int *clase) {
    for (int i = 0; i < 4; i++) {
        clases[i] = clase[i];
    }
}

void Docente::setDias(int *numero) {
    for (int i = 0; i < 6; i++) {
        dias[i] = numero[i];
    }
}


int Docente::getDiasDisponible() {
    int contador = 0;
    for (int i = 0; i < 6; i++) {
        if (dias[i] > 0) {
            contador++;
        }
    }
    return contador;
}

int Docente::getLunes() {
    return dias[0];
}

int Docente::getMartes() {
    return dias[1];
}

int Docente::getMiercoles() {
    return dias[2];
}

int Docente::getJueves() {
    return dias[3];
}

int Docente::getViernes() {
    return dias[4];
}

int Docente::getSabado() {
    return dias[5];
}

int Docente::getTotalClases() {
    int suma = 0;
    suma = clases[0] + clases[1] + clases[2] + clases[3];
    return suma;
}

void Docente::descontarHora() {

    for (int i = 0; i<4; i++){
        if (clases[i]!=0){
            clases[i]= clases[i]-1;
            break;
        }
    }
}

int Docente::getIdentificador() {
    return identificador;
}

void Docente::setIdentificador(int identificador) {
    this->identificador = identificador;
}