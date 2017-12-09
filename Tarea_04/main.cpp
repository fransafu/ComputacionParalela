/*
* Tarea Numero 4
*
* Programa que agrupa los codigos de las peticiones por codigo de respuesta
*
*/

#include <iostream>
#include <fstream>
#include <cstring>
#include <regex>
#include "mpi.h"

using namespace std;

string getCodigoFromStrLine(string str) {
    regex rgx("\".*\" [0-9]+");
    smatch match;
    string strcopy;

    if (regex_search(str, match, rgx)) {
        string tmp = match[0];
        strcopy = tmp.substr(strlen(tmp.c_str()) - 3, strlen(tmp.c_str()) - 1);
    }
    return strcopy;
}

int main(int argc, char *argv[]) {
    string ruta = argv[0];
    int estadosInt[1001153];
    MPI_Status status;
    int arregloContador[15] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int arregloResultado[15] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int contadorLineas = 0;


    int rank, size, len;

    MPI::Init(); // inicializa en mpi
    rank = MPI::COMM_WORLD.Get_rank(); // se trae el rank en el que se esta ejecutando
    size = MPI::COMM_WORLD.Get_size(); // el tamaño que trae desde terminal


    if (rank == 0) {
        ifstream file("../accesss.log");
        int resultado[15];
        if (file.is_open() && !(file.peek() == std::ifstream::traits_type::eof())) {
            int i = 0;
            string str;
            while (getline(file, str)) {
                estadosInt[i] = stoi(getCodigoFromStrLine(str));
                i++;
                contadorLineas += 1;
            }
        }
    }

    MPI_Bcast(&contadorLineas, 1, MPI_INT, 0, MPI_COMM_WORLD); // le envio el contador a todos los rank
    int receptor[contadorLineas / size + 1];
    MPI_Scatter(estadosInt, (contadorLineas / size) + 1, MPI_INT, receptor, (contadorLineas / size) + 1, MPI_INT, 0,
                MPI_COMM_WORLD);

    for (int i = 0; i < contadorLineas / size + 1; i++) {
        if (200 == receptor[i]) {
            arregloContador[0] += 1;
        }
        if (206 == receptor[i]) {
            arregloContador[1] += 1;
        }
        if (404 == receptor[i]) {
            arregloContador[2] += 1;
        }
        if (408 == receptor[i]) {
            arregloContador[3] += 1;
        }
        if (304 == receptor[i]) {
            arregloContador[4] += 1;
        }
        if (302 == receptor[i]) {
            arregloContador[5] += 1;
        }
        if (301 == receptor[i]) {
            arregloContador[6] += 1;
        }
        if (400 == receptor[i]) {
            arregloContador[7] += 1;
        }
        if (401 == receptor[i]) {
            arregloContador[8] += 1;
        }
        if (403 == receptor[i]) {
            arregloContador[9] += 1;
        }
        if (416 == receptor[i]) {
            arregloContador[10] += 1;
        }
        if (405 == receptor[i]) {
            arregloContador[11] += 1;
        }
        if (417 == receptor[i]) {
            arregloContador[12] += 1;
        }
        if (501 == receptor[i]) {
            arregloContador[13] += 1;
        }
        if (406 == receptor[i]) {
            arregloContador[14] += 1;
        }
    }

    cout << "total de 200 en el rank " << rank << "  " << arregloContador[0] << endl;
    cout << "total de 206 en el rank " << rank << "  " << arregloContador[1] << endl;
    cout << "total de 404 en el rank " << rank << "  " << arregloContador[2] << endl;
    cout << "total de 408 en el rank " << rank << "  " << arregloContador[3] << endl;
    cout << "total de 304 en el rank " << rank << "  " << arregloContador[4] << endl;
    cout << "total de 302 en el rank " << rank << "  " << arregloContador[5] << endl;
    cout << "total de 301 en el rank " << rank << "  " << arregloContador[6] << endl;
    cout << "total de 400 en el rank " << rank << "  " << arregloContador[7] << endl;
    cout << "total de 401 en el rank " << rank << "  " << arregloContador[8] << endl;
    cout << "total de 403 en el rank " << rank << "  " << arregloContador[9] << endl;
    cout << "total de 416 en el rank " << rank << "  " << arregloContador[10] << endl;
    cout << "total de 405 en el rank " << rank << "  " << arregloContador[11] << endl;
    cout << "total de 417 en el rank " << rank << "  " << arregloContador[12] << endl;
    cout << "total de 501 en el rank " << rank << "  " << arregloContador[13] << endl;
    cout << "total de 406 en el rank " << rank << "  " << arregloContador[14] << endl;

    /*
    if (rank > 0) {
        MPI_Recv(arregloResultado, (contadorLineas / size) + 1, MPI_INT, rank, 0, MPI_COMM_WORLD, &status);
    }
    for (int j = 0; j < 15; j++) {
        arregloResultado[j] = arregloContador[j] + arregloResultado[j];
    }
    if (rank < size) {
        MPI_Send(arregloResultado, 1, MPI_INT, rank + 1, 10, MPI_COMM_WORLD);
    }

    */

    MPI::Finalize(); // cierra el proceso MPI

//    cout << "contador Lineas: " << contadorLineas << endl;
    //  cout << "Programa terminado" << endl;

    return 0;

}
