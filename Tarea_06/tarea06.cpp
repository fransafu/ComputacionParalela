#include <iostream>
#include <stdio.h>

#include <stdlib.h>
#include <string>
#include <ctype.h>
#include "blowfish.h"

#include "omp.h"

using namespace std;

int crackPassword(){

    int n = 20;
    int i, nth;

    char palabra[5];

//#pragma omp parallel
  //  nth = omp_get_num_threads();
    //cout << "Hilos  maximos : " << nth << endl; //Numero de hilos que aguanta el procer

    // char *textoCrifrado = "734b76ed5b240aca35f76f9095b9c14ef60adfc642071f286dcf4962dcb9611c27e1189eef842aff20b4bf7495fef6b5c18b206941ab41e6ced09679af49c9b73dc0b05ac9fe05c7d3a4e245c5cbb90c5c65fb1281505b44154ed05d24ef8a4bc6d700960deacb90022b2c4362544bc9cc9c447d88e5e412df841f87843c1ac3";

    char asciiArray[] = {'!', '"', '#', '$', '%', '&', '\'', '(', ')', '*', '+', ',', '-', '.', '/', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', ':', ';', '<', '=', '>', '?', '@', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', '[', '\\', ']', '^', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '{', '|', '}', '~', ' '};

    int indice1;
    int indice2;
    int indice3;
    int indice4;
    int indice5;

    int limiteInferior = 0;
    int limiteSuperior = 92;
#pragma omp parallel for
    for (indice1=limiteInferior; indice1<=limiteSuperior; indice1++) {

        palabra[0]=asciiArray[indice1];// (char)indice1;

        for (indice2=0; indice2<=92; indice2++) {

            palabra[1]=asciiArray[indice2];//(char)indice2;

            for (indice3=0; indice3<=92; indice3++) {

                palabra[2]=asciiArray[indice3];//(char)indice3;


                for (indice4=0; indice4<=92; indice4++) {

                    palabra[3]=asciiArray[indice4];//(char)indice4;

                    for (indice5=0; indice5<=92; indice5++) {

                        palabra[4]=asciiArray[indice5];//(char)indice5;

                        //cout << descifrar(palabra, "734b76ed5b240aca35f76f9095b9c14ef60adfc642071f286dcf4962dcb9611c27e1189eef842aff20b4bf7495fef6b5c18b206941ab41e6ced09679af49c9b73dc0b05ac9fe05c7d3a4e245c5cbb90c5c65fb1281505b44154ed05d24ef8a4bc6d700960deacb90022b2c4362544bc9cc9c447d88e5e412df841f87843c1ac3") << endl;

                        string resultado = descifrar(palabra, "734b76ed5b240aca35f76f9095b9c14ef60adfc642071f286dcf4962dcb9611c27e1189eef842aff20b4bf7495fef6b5c18b206941ab41e6ced09679af49c9b73dc0b05ac9fe05c7d3a4e245c5cbb90c5c65fb1281505b44154ed05d24ef8a4bc6d700960deacb90022b2c4362544bc9cc9c447d88e5e412df841f87843c1ac3");
                        //if (resultado.find("a") || resultado.find("e") || resultado.find("i") || resultado.find("o") || resultado.find("u")){
                        //    cout << descifrar(palabra, "734b76ed5b240aca35f76f9095b9c14ef60adfc642071f286dcf4962dcb9611c27e1189eef842aff20b4bf7495fef6b5c18b206941ab41e6ced09679af49c9b73dc0b05ac9fe05c7d3a4e245c5cbb90c5c65fb1281505b44154ed05d24ef8a4bc6d700960deacb90022b2c4362544bc9cc9c447d88e5e412df841f87843c1ac3") << endl;
                        //} else
                        cout << indice1 << " " << indice2 << " " << indice3 << " " << indice4 << " " << indice5 << endl;
                        cout << "clave a probar: " << palabra << endl;


                        if (!resultado.find("�")){
                            // cout <<  << endl;
                            cout << resultado.length() << endl;
                            cout << resultado << endl;
                            break;
                        }

                        // try{
                        //     if (cifrar(palabra, descifrar(palabra, "734b76ed5b240aca35f76f9095b9c14ef60adfc642071f286dcf4962dcb9611c27e1189eef842aff20b4bf7495fef6b5c18b206941ab41e6ced09679af49c9b73dc0b05ac9fe05c7d3a4e245c5cbb90c5c65fb1281505b44154ed05d24ef8a4bc6d700960deacb90022b2c4362544bc9cc9c447d88e5e412df841f87843c1ac3")) == "734b76ed5b240aca35f76f9095b9c14ef60adfc642071f286dcf4962dcb9611c27e1189eef842aff20b4bf7495fef6b5c18b206941ab41e6ced09679af49c9b73dc0b05ac9fe05c7d3a4e245c5cbb90c5c65fb1281505b44154ed05d24ef8a4bc6d700960deacb90022b2c4362544bc9cc9c447d88e5e412df841f87843c1ac3"){
                        //         cout << descifrar(palabra, "734b76ed5b240aca35f76f9095b9c14ef60adfc642071f286dcf4962dcb9611c27e1189eef842aff20b4bf7495fef6b5c18b206941ab41e6ced09679af49c9b73dc0b05ac9fe05c7d3a4e245c5cbb90c5c65fb1281505b44154ed05d24ef8a4bc6d700960deacb90022b2c4362544bc9cc9c447d88e5e412df841f87843c1ac3") << endl;
                        //     }
                        // } catch (int e){
                        //     cout << "Se cae: " << e << endl;
                        // }

                    }
                }
            }
        }
    }

}


int main() {


    crackPassword();


    return 0;
}
