#include <iostream>
#include <stdio.h>

#include <stdlib.h>
#include <string>
#include <ctype.h>
#include "blowfish.h"

#include "mpi.h"

#include <algorithm>

using namespace std;

char* string_hash = "734b76ed5b240aca35f76f9095b9c14ef60adfc642071f286dcf4962dcb9611c27e1189eef842aff20b4bf7495fef6b5c18b206941ab41e6ced09679af49c9b73dc0b05ac9fe05c7d3a4e245c5cbb90c5c65fb1281505b44154ed05d24ef8a4bc6d700960deacb90022b2c4362544bc9cc9c447d88e5e412df841f87843c1ac3";

int main(int argc, char** argv){
    int n = 20;

    int myid, numprocs;
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &numprocs); // devuelve el numero de procesos en este COMM_WORLD
    MPI_Comm_rank(MPI_COMM_WORLD, &myid); // identificate por el myid asignado
    int limiteInferior = ((33/numprocs)*myid);
    int limiteSuperior = ((33/numprocs)*(myid+1));
    // int limiteInferior = ((60/numprocs)*myid)+24;
    // int limiteSuperior = ((60/numprocs)*(myid+1))+24;
    int p;

    char palabra[5];
    char *texto;
    char asciiArray[] = {'!', '"', '#', '$', '%', '&', '\'', '(', ')', '*', '+', ',', '-', '.', '/', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', ':', ';', '<', '=', '>', '?', '@', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '[', '\\', ']', '^', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '{', '|', '}', '~', ' '};
    // Largo arreglo 93
    int indice1, indice2, indice3, indice4, indice5;

    //int limiteInferior = 30;
    //int limiteSuperior = 60;
    cout << "largo array: " << strlen(asciiArray) << endl;

    for (indice1=limiteInferior; indice1<=limiteSuperior; indice1++) {
        palabra[0]=asciiArray[indice1];// (char)indice1;
        for (indice2=0; indice2<=91; indice2++) {
            palabra[1]=asciiArray[indice2];//(char)indice2;
            cout << "[" << indice1 << "][" << indice2 << "][x][x][x]" << endl;
            cout << "clave a probar: " << asciiArray[indice1] << asciiArray[indice2] << endl;
            for (indice3=0; indice3<=91; indice3++) {
                for (indice4=0; indice4<=91; indice4++) {
                    for (indice5=0; indice5<=91; indice5++) {


                        palabra[2]=asciiArray[indice3];//(char)indice3;
                        palabra[3]=asciiArray[indice4];//(char)indice4;
                        palabra[4]=asciiArray[indice5];//(char)indice5;

                        char *buffer = (char *)malloc(sizeof(char) + 1);
                        strncpy(buffer, palabra, 5);

                        string resultado = descifrar(buffer, string_hash);

                        //cout << "[" << indice1 << "][" << indice2 << "][" << indice3 << "][" << indice4 << "][" << indice5 << "]" << endl;
                        //cout << "clave a probar: " << buffer << endl;

                        try{
                            texto = descifrar(buffer, string_hash);
                            //char *texto_copia = (char *)calloc(strlen(texto) + 2, sizeof(byte));
                            //snprintf(texto_copia, 5, "%s", texto);

                            if (resultado.length() > 40){
                                bool valido = true;
                                for (int i = 0; i < resultado.length(); i++){
                                    if (resultado[i] > 127 || resultado[i] < 32 ){
                                        valido = false;
                                    } //else {



                                    //}
                                    //cout << "resultado[" << i << "]: " << resultado[i] << endl;
                                }

                                if (valido){
                                    // cout << "Dentro del rango" << endl;
                                        // cout << "resultado[" << i << "]: " << resultado[i] << endl;

                                    size_t n = std::count(resultado.begin(), resultado.end(), ' ');  // Cuenta espacio
                                    size_t n2 = std::count(resultado.begin(), resultado.end(), 'a'); // Cuenta letra a
                                    size_t n3 = std::count(resultado.begin(), resultado.end(), 'e'); // Cuenta letra e
                                    if ( (n > 5 && (n2 > 3 || n3 > 3)) ){
                                        cout << endl;
                                        cout << "Largo texto resultado: " << resultado.length() << endl;
                                        cout << "clave utilizada: \n" << buffer << endl;
                                        free(buffer);
                                        cout << "Texto obtenido: \n" << resultado << endl;
                                        cout << endl;
                                        cout << "\nEspacios: " << n << endl;
                                        cout << "a: " << n2 << endl;
                                        cout << "e: " << n3 << endl;
                                    } else{
                                        free(buffer);
                                    }
                                }
                                valido = true;

                            }


/*
                            char *cifrado = cifrar(palabra, texto_copia);
                            if (strcmp(cifrado, string_hash) == 0) {
                                cout << "Son iguales!";
                                cout << resultado << endl;

                                size_t n = std::count(resultado.begin(), resultado.end(), ' ');  // Cuenta espacio
                                size_t n2 = std::count(resultado.begin(), resultado.end(), 'a'); // Cuenta letra a
                                size_t n3 = std::count(resultado.begin(), resultado.end(), 'e'); // Cuenta letra e
                                if (resultado.length() <= 200 && n > 5 && (n2 > 3 || n3 > 3) ){
                                    cout << endl;
                                    cout << "Largo texto resultado: " << resultado.length() << endl;
                                    cout << "Texto obtenido: \n" << resultado << endl;
                                    cout << "\nEspacios: " << n << endl;
                                    cout << "a: " << n << endl;
                                    cout << "e: " << n << endl;
                                }
                            }
*/


                            // Hay que retornar la memoria en cada iteracion
                            //memset(subbuff, 0, sizeof subbuff);
                            free(buffer);
                            //free(texto_copia);
                            free(texto);
                            //free(cifrado);
                            resultado.clear();
                        } catch (int e){
                            free(buffer);
                            //free(texto_copia);
                            free(texto);
                            cout << "Se cae: " << e << endl;
                        }
                    }
                }
            }
        }
    }
    MPI_Finalize();
    return 0;
}
/*
int main() {
    // freopen ("test.txt","w",stdout);
    // printf ("This sentence is redirected to a file.");
    crackPassword();
    // fclose (stdout);
    return 0;
}
*/
