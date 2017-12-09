#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "blowfish.h"
#include "mpi.h"


int main(int argc, char **argv) {

    char *llave = "";
    char *mensaje = "";
    char *texto ="";
    int salida = EXIT_SUCCESS;
    char asciiArray[] = {'!', '"', '#', '$', '%', '&', '\'', '(', ')', '*', '+', ',', '-', '.', '/', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', ':', ';', '<', '=', '>', '?', '@', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '[', '\\', ']', '^', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '{', '|', '}', '~', ' '};

    unsigned char buf[100000];
    comb(5,3, buf);

    int c;
    FILE *file;
    file = fopen("texto.txt", "r");
    if (file) {
        while ((c = getc(file)) != EOF)
            putchar(c);
        fclose(file);
    }



    printf("%s", texto);

    // Libero la memoria
    free(llave);
    free(mensaje);


    return salida;
}

