#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "/usr/include/mpich/mpi.h"
#include "blowfish.h"

int main(int argc, char** argv){
    //freopen ("output4.txt","w",stdout);
    printf ("Inicia programa.");
  
    int id, numprocs;
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &numprocs);
    MPI_Comm_rank(MPI_COMM_WORLD, &id); 
// --------------------------------------------------------------------------------------------------------------------------------------------
    int limiteInferior = (4*id) + 1;
    int limiteSuperior = limiteInferior + 1;
    int valido=1;

    char* mensaje = "734b76ed5b240aca35f76f9095b9c14ef60adfc642071f286dcf4962dcb9611c27e1189eef842aff20b4bf7495fef6b5c18b206941ab41e6ced09679af49c9b73dc0b05ac9fe05c7d3a4e245c5cbb90c5c65fb1281505b44154ed05d24ef8a4bc6d700960deacb90022b2c4362544bc9cc9c447d88e5e412df841f87843c1ac3";
    char* intento   = NULL;
    int   sizeMessage;

    char asciiArray[] = {'!', '"', '#', '$', '%', '&', '\'', '(', ')', '*', '+', ',', '-', '.', '/', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', ':', ';', '<', '=', '>', '?', '@', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '[', '\\', ']', '^', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '{', '|', '}', '~', ' '};
    //char asciiArray[] = {'!"#$%&\'(', ')', '*', '+', ',', '-', '.', '/', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', ':', ';', '<', '=', '>', '?', '@', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '[', '\\', ']', '^', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '{', '|', '}', '~', ' '};
    char clave[5];
    
    for(int indice1 = limiteInferior; indice1 < limiteSuperior; indice1++) {
        for(int indice2 = 0; indice2 < 92; indice2++) {
            for(int indice3 = 0; indice3 < 92; indice3++) {
                for(int indice4 = 0; indice4 < 92; indice4++) {
                    for(int indice5 = 0; indice5 < 92; indice5++) {
                        free(intento);
                        clave[0] = asciiArray[indice1];
                        clave[1] = asciiArray[indice2];
                        clave[2] = asciiArray[indice3];
                        clave[3] = asciiArray[indice4];
                        clave[4] = asciiArray[indice5];
                        intento  = descifrar(clave, mensaje);
                        sizeMessage = strlen(intento);
                        
                        valido = 1;
                        if( sizeMessage != 0 ){
                            for(int i=0; i < sizeMessage; i++){
                                if(intento[i] < 32 || intento[i] > 127 ){
                                    valido = 0;
                                    break;
                                }
                            }
                            if ( (sizeMessage > 8) && (valido == 1) ){
                                fprintf(stdout, "\nClave: %c%c%c%c%c\n",asciiArray[indice1], asciiArray[indice2], asciiArray[indice3], asciiArray[indice4], asciiArray[indice5]);
                                fprintf(stdout, "\nTexto: %s\n", intento);
                            }
                        }
                    }
                }
            }
        }
    }
// --------------------------------------------------------------------------------------------------------------------------------------------
    MPI_Finalize();
    //fclose (stdout);
    return 0;
}
