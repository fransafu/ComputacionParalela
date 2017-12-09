//
// Created by frubilar on 05-05-17.
//

#ifndef UNTITLED2_SALA_H
#define UNTITLED2_SALA_H


class Sala {

    int identificador;
    int lunes[8];
    int martes[8];
    int miercoles[8];
    int jueves[8];
    int viernes[8];
    int sabado[6];

private:
public:
    Sala();

    void getLunes(int lunes[8]) ;

    void getMartes(int martes[8]) ;

    void getMiercoles(int miercoles[8]) ;

    void getJueves(int jueves[8]) ;

    void getViernes(int viernes[8]) ;

    void getSabado(int sabado[6]) ;

    void setLunes(int lunes) ;

    void setMartes(int martes) ;

    void setMiercoles(int miercoles) ;

    void setJueves(int jueves) ;

    void setViernes(int viernes) ;

    void setSabado(int sabado) ;

    int diaConMasBloquesLibre();

};


#endif //UNTITLED2_SALA_H
