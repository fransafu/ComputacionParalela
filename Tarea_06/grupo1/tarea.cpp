#include <iostream>
#include <stdio.h>

#include <stdlib.h>
#include <string>
#include <ctype.h>
#include "blowfish.h"
#include "mpi.h"
#include <algorithm>

using namespace std;

char *string_hash = "734b76ed5b240aca35f76f9095b9c14ef60adfc642071f286dcf4962dcb9611c27e1189eef842aff20b4bf7495fef6b5c18b206941ab41e6ced09679af49c9b73dc0b05ac9fe05c7d3a4e245c5cbb90c5c65fb1281505b44154ed05d24ef8a4bc6d700960deacb90022b2c4362544bc9cc9c447d88e5e412df841f87843c1ac3";
char asciiArray[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't',
                     'u', 'v', 'w', 'x', 'y', 'z',
                     'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
                     'U', 'V', 'W', 'X', 'Y', 'Z',
                     '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
                     '!', '"', '#', '$', '%', '&', '\'', '(', ')', '*', '+', ',', '-', '.', '/', ':', ';', '<', '=',
                     '>', '?', '@', '[', '\\', ']', '^', '{', '|', '}', '~', ' '};

int contar(char *valor, char caracter) {
    int contador = 0;
    for (int i = 0; i < strlen(valor); i++) {
        if (valor[i] == caracter) {
            contador++;
        }
    }
    return contador;
}


void comb(int N, int K) {
    int contador = 0;
    std::string bitmask(K, 1); // K leading 1's
    bitmask.resize(N, 0); // N-K trailing 0's
    char *resultado = NULL;
    char prueba[5];
    int j = 0;
    bool salida = false;
    // print integers and permute bitmask
    do {
        for (int i = 0; i < N; ++i) // [0..N-1] integers
        {
            if (bitmask[i]) {
                //std::cout << " " << i;
                prueba[j] = asciiArray[i];
                j++;
            }
        }
        j = 0;
        if (contador % 1000000 == 0) {
            std::cout << contador << std::endl;

        }
        contador++;
        resultado = descifrar(prueba, string_hash);
//        string resultado(descifrar(prueba, string_hash));

        if (strlen(resultado) > 40) {
            bool valido = true;
            int contador_caracteres = 0;
            for (int i = 0; i < strlen(resultado); i++) {
                int32_t valor = (int32_t) resultado[i];
                if (valor > 19 && valor < 127) {
                    contador_caracteres++;
                }
            }

            if (contador_caracteres <= strlen(resultado) && contador_caracteres >= strlen(resultado) - 10) {
                cout << endl;
                std::cout << "Largo texto resultado: " << strlen(resultado) << std::endl;
                std::cout << "clave utilizada: \n" << prueba << std::endl;
                std::cout << "Texto obtenido: \n" << resultado << std::endl;
                std::cout << endl;
                salida = true;
            }
            valido = true;
        }
        free(resultado);
        if (salida) {
            std::cout << "toda actividad se vera interrumpitda" << endl;
            break;
        }
    } while (std::prev_permutation(bitmask.begin(), bitmask.end()));
}

int main(int argc, char **argv) {
    int n = 20;

    int myid, numprocs;
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &numprocs); // devuelve el numero de procesos en este COMM_WORLD
    MPI_Comm_rank(MPI_COMM_WORLD, &myid); // identificate por el myid asignado
    int limiteInferior = ((33 / numprocs) * myid);
    int limiteSuperior = ((33 / numprocs) * (myid + 1));
    // int limiteInferior = ((60/numprocs)*myid)+24;
    // int limiteSuperior = ((60/numprocs)*(myid+1))+24;
    int p;

    char palabra[5];
    char *texto;

    cout << "largo array: " << strlen(asciiArray) << endl;

    MPI_Finalize();
    comb(93, 5);
    return 0;
}
