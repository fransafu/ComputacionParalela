/**
 * @file main.c
 * @author Sebastián Salazar Molina <sebasalazar@gmail.com>
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "blowfish.h"

/**
 * Muestra la pantalla de ayuda.
 * @param programa Nombre del programa
 */
void error(char* programa);

/**
 * Pequeño programa para ocupar Blowfish en C usando la librería OpenSSL.
 * @param argc Cantidad de Argumentos recibidos por la línea de comandos.
 * @param argv Arreglo con los parámetros pasados por la línea de comandos.
 * @return 0 en caso de éxito y 1 ante un error.
 */
int main(int argc, char** argv) {

    char* opcion = NULL;
    char* llave = NULL;
    char* mensaje = NULL;
    char *texto = NULL;
    int salida = EXIT_SUCCESS;


    if (argc < 3) {
        error(argv[0]);
    } else {
        opcion = (char *) calloc(strlen(argv[1]) + 2, sizeof (byte));
        snprintf(opcion, strlen(argv[1]) + 1, "%s", argv[1]);

        llave = (char *) calloc(strlen(argv[2]) + 2, sizeof (byte));
        snprintf(llave, strlen(argv[2]) + 1, "%s", argv[2]);

        mensaje = (char *) calloc(strlen(argv[3]) + 2, sizeof (byte));
        snprintf(mensaje, strlen(argv[3]) + 1, "%s", argv[3]);

        if (strcmp("enc", opcion) == 0) {
            fprintf(stdout, "\nLlave         : %s", llave);
            fprintf(stdout, "\nMensaje       : %s", mensaje);
            texto = cifrar(llave, mensaje);
            fprintf(stdout, "\nTexto cifrado : %s\n", texto);
        } else if (strcmp("dec", opcion) == 0) {
            texto = descifrar(llave, mensaje);
            fprintf(stdout, "\n%s\n", texto);
        } else {
            error(argv[0]);
            salida = EXIT_FAILURE;
        }


        // Libero la memoria
        free(opcion);
        free(llave);
        free(mensaje);
    }

    return salida;
}

void error(char* programa) {
    fprintf(stdout, "\n === Error parametros insuficientes === \n");
    fprintf(stdout, "%s [opcion] [llave] [mensaje] \n", programa);
    fprintf(stdout, "[opcion] puede ser [enc] => cifrar y [dec] => descifrar \n");
    fprintf(stdout, "[llave] es una secuencia de caracteres usadas como llave simetrica \n");
    fprintf(stdout, "[mensaje] texto a cifrar/descifrar \n");
    fprintf(stdout, "\n === Ejemplo para cifrar CIFRADO === \n");
    fprintf(stdout, "%s enc asdf \"Hola curso...\" \n", programa);
    fprintf(stdout, "\n === Ejemplo para cifrar CIFRADO === \n");
    fprintf(stdout, "%s dec asdf \"37727ac53c8dea90d386ebd2b763eb0b\" \n", programa);
}
