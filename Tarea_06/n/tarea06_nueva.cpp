/*
	Este archivo lo ocupe mas que nada para encontrar que funciones me generaban errores y leaks de memoria.
*/

#include <iostream>
#include <cstring>
#include <algorithm>

#include "blowfish.h"
#include "omp.h"

using namespace std;

char* hash_mensaje = "734b76ed5b240aca35f76f9095b9c14ef60adfc642071f286dcf4962dcb9611c27e1189eef842aff20b4bf7495fef6b5c18b206941ab41e6ced09679af49c9b73dc0b05ac9fe05c7d3a4e245c5cbb90c5c65fb1281505b44154ed05d24ef8a4bc6d700960deacb90022b2c4362544bc9cc9c447d88e5e412df841f87843c1ac3";

char asciiArray[] = {'!', '"', '#', '$', '%', '&', '\'', '(', ')', '*', '+', ',', '-', '.', '/', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', ':', ';', '<', '=', '>', '?', '@', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '[', '\\', ']', '^', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '{', '|', '}', '~', ' '};


int main(int argc, char **argv) {
  for (int i = 0; i <= 91; i++) {
    for (int j = 0; j <= 91; j++) {
      for (int k = 0; k <= 91; k++) {
	for (int l = 0; l <= 91; l++) {
	  for (int m = 0; m <= 91; m++) {

	    char *llave = (char *)calloc(5 + 2, sizeof(byte));

	    llave[0] = asciiArray[i];
	    llave[1] = asciiArray[j];
	    llave[2] = asciiArray[k];
	    llave[3] = asciiArray[l];
	    llave[4] = asciiArray[m];

	    cout << "Llave a probar: " << llave << endl;

	    char *texto = descifrar(llave, hash_mensaje);

	    cout << "Texto decifrado: " << texto << endl;

	    // Tengo que pasar una copia del mensaje o sino me tira un error
	    // de malloc que dice que la memoria esta corrupta xd
	    char *texto_copia = (char *)calloc(strlen(texto) + 2, sizeof(byte));
	    snprintf(texto_copia, 5, "%s", texto);

	    char *texto_cifrado = cifrar(llave, texto_copia);

	    free((void *)llave);
	    free((void *)texto);
	    free((void *)texto_copia);
	    free((void *)texto_cifrado);
	  }
	}
      }
    }
  }

  return 0;
}
