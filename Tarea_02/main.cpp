#include <iostream>
#include "Docente.h"
#include "Sala.h"
#include <fstream>
#include <vector>


using namespace std;

int docenteConmenorDisponibiliad(vector<Docente> docentes) {
    int menor = 9999;
    int retornar;
    for (vector<Docente>::iterator profesores = docentes.begin(); profesores != docentes.end(); profesores++) {
        if (profesores->getTotalClases() < menor && profesores->getTotalClases() > 0) {
            menor = profesores->getTotalClases();
            retornar = profesores->getIdentificador();
        }
    }
    return retornar;
}


int cantidadDeDocentes(vector<Docente> docentes) {
    int contador = 0;
    for (vector<Docente>::iterator profesores = docentes.begin(); profesores != docentes.end(); profesores++) {
        contador++;
    }
    return contador;
}

string docenteIntegerToString(int numero) {
    string salida;
    if (numero == 1) {
        salida = "Sherlock";
    }
    if (numero == 2) {
        salida = "Hercules";
    }
    if (numero == 3) {
        salida = "Charles";
    }
    if (numero == 4) {
        salida = "Jane";
    }
    if (numero == 5) {
        salida = "Pepe";
    }
    if(numero == 0){
        salida = "Docente No asignado";
    }
    return salida;
}

int valorDia(int numero, Docente profesor) {
    int salida = 0;

    if (numero == 0)
        salida = profesor.getLunes();

    if (numero == 1)
        salida = profesor.getMartes();

    if (numero == 2)
        salida = profesor.getMiercoles();

    if (numero == 3)
        salida = profesor.getJueves();

    if (numero == 4)
        salida = profesor.getViernes();

    if (numero == 5)
        salida = profesor.getSabado();
    return salida;
}

int docentesAsignado(vector<Docente> docentes, int dia) {
    vector<Docente> nuevos;
    for (vector<Docente>::iterator profesores = docentes.begin(); profesores != docentes.end(); profesores++) {
        if (dia == 0) {
            if (profesores->getLunes() == 1) {
                nuevos.push_back(*profesores);
            }
        }
        if (dia == 1) {
            if (profesores->getMartes() == 1) {
                nuevos.push_back(*profesores);
            }
        }
        if (dia == 2) {
            if (profesores->getMiercoles() == 1) {
                nuevos.push_back(*profesores);
            }
        }
        if (dia == 3) {
            if (profesores->getJueves() == 1) {
                nuevos.push_back(*profesores);
            }
        }
        if (dia == 4) {
            if (profesores->getViernes() == 1) {
                nuevos.push_back(*profesores);
            }
        }
        if (dia == 5) {
            if (profesores->getSabado() == 1) {
                nuevos.push_back(*profesores);
            }
        }
    }
    int disponinble = docenteConmenorDisponibiliad(nuevos);


    return disponinble;
}

void descontarBloqueEnUnDia(Sala &sala, int dia, int docente) {

    if (dia == 0) {
        sala.setLunes(docente);
    }
    if (dia == 1) {
        sala.setMartes(docente);
    }
    if (dia == 2) {
        sala.setMiercoles(docente);
    }
    if (dia == 3) {
        sala.setJueves(docente);
    }
    if (dia == 4) {
        sala.setViernes(docente);
    }
    if (dia == 5) {
        sala.setSabado(docente);
    }

}

int horasNoUsadasAun(vector<Docente> docentes) {
    int suma = 0;
    for (vector<Docente>::iterator profesores = docentes.begin(); profesores != docentes.end(); profesores++) {
        suma += profesores->getTotalClases();
    }
    return suma;
}

int main() {


    vector<Docente> profesores;
    Docente sherlock = Docente();
    Docente hercules = Docente();
    Docente charles = Docente();
    Docente jane = Docente();
    Docente pepe = Docente();
    int holmes[6] = {1, 1, 1, 1, 1, 1};  //DIAS DISPONIBLES
    int poirot[6] = {1, 0, 1, 0, 1, 0};
    int auguste[6] = {1, 1, 1, 0, 0, 0};
    int marple[6] = {0, 1, 0, 1, 0, 1};
    int carvalho[6] = {1, 1, 1, 1, 1, 1}; //DIAS DISPONILBES

    int holmesRamo[4] = {3, 3, 3, 3}; //RAMOS Y SUS HORAS PERTINENETES
    int herculesRamo[4] = {3, 3, 3, 0};
    int charlesRamo[4] = {3, 3, 3, 0};
    int janeRamo[4] = {3, 3, 0, 0};
    int pepeRamo[4] = {3, 3, 3, 0}; // RAMOS Y SUS HORAS


    sherlock.setDias(holmes);
    hercules.setDias(poirot);
    charles.setDias(auguste);
    jane.setDias(marple);
    pepe.setDias(carvalho);

    sherlock.setClase(holmesRamo);
    hercules.setClase(herculesRamo);
    charles.setClase(charlesRamo);
    jane.setClase(janeRamo);
    pepe.setClase(pepeRamo);

    sherlock.setIdentificador(1);
    hercules.setIdentificador(2);
    charles.setIdentificador(3);
    jane.setIdentificador(4);
    pepe.setIdentificador(5);

    profesores.push_back(sherlock);
    profesores.push_back(hercules);
    profesores.push_back(charles);
    profesores.push_back(jane);
    profesores.push_back(pepe);

    Sala sala = Sala();
    vector<Docente>::iterator docentes = profesores.begin();
    int dia = sala.diaConMasBloquesLibre();
    int horasRestantes = horasNoUsadasAun(profesores);
    while (dia != 9 && horasRestantes > 1) {
        int docente = docentesAsignado(profesores, dia);
        descontarBloqueEnUnDia(sala, dia, docente);
        docentes[docente - 1].descontarHora();
        horasRestantes = horasNoUsadasAun(profesores);
        dia = sala.diaConMasBloquesLibre();

    }

    int lunes[8];
    int martes[8];
    int miercoles[8];
    int jueves[8];
    int viernes[8];
    int sabado[6];
    sala.getLunes(lunes);
    sala.getMartes(martes);
    sala.getMiercoles(miercoles);
    sala.getJueves(jueves);
    sala.getViernes(viernes);
    sala.getSabado(sabado);

    ofstream horario;
    horario.open("horario.csv");
    horario << "horario" << endl;
    horario << "Lunes ; Martes ; Miercoles ; Jueves ; Viernes ; Sabado" << endl;

    for (int i = 0; i < 8; i++) {
        horario << docenteIntegerToString(lunes[i]) << ";" << docenteIntegerToString(martes[i]) << ";" << docenteIntegerToString(miercoles[i]) << ";" << docenteIntegerToString(jueves[i]) << ";" << docenteIntegerToString(viernes[i]);
        if (i < 6) {
            horario << ";" << docenteIntegerToString(sabado[i]);
        }
        horario << endl;
    }
    horario.close();

    return 0;


}