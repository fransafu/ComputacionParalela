//
// Created by frubilar on 05-05-17.
//

#include "Sala.h"

Sala::Sala() {
    for (int i = 0; i < 8; i++) {
        lunes[i] = 0;
        martes[i] = 0;
        miercoles[i] = 0;
        jueves[i] = 0;
        viernes[i] = 0;
        if (i < 6) {
            sabado[i] = 0;
        }
    }
}

void Sala::getLunes(int *lunes) {
    for (int i = 0; i < 8; i++) {
        lunes[i] = this->lunes[i];
    }
}

void Sala::getMartes(int *martes) {
    for (int i = 0; i < 8; i++) {
        martes[i] = this->martes[i];
    }
}

void Sala::getMiercoles(int *miercoles) {
    for (int i = 0; i < 8; i++) {
        miercoles[i] = this->miercoles[i];
    }
}

void Sala::getJueves(int *jueves) {
    for (int i = 0; i < 8; i++) {
        jueves[i] = this->jueves[i];
    }
}

void Sala::getViernes(int *viernes) {
    for (int i = 0; i < 8; i++) {
        viernes[i] = this->viernes[i];
    }
}

void Sala::getSabado(int *sabado) {
    for (int i = 0; i < 8; i++) {
        sabado[i] = this->sabado[i];
    }
}

void Sala::setLunes(int lunes) {
    for (int i = 0; i < 8; i++) {
        if (this->lunes[i] == 0) {
            this->lunes[i] = lunes;
            break;
        }
    }
}

void Sala::setMartes(int martes) {
    for (int i = 0; i < 8; i++) {
        if (this->martes[i] == 0) {
            this->martes[i] = martes;
            break;
        }
    }
}

void Sala::setMiercoles(int miercoles) {
    for (int i = 0; i < 8; i++) {
        if (this->miercoles[i] == 0) {
            this->miercoles[i] = miercoles;
            break;
        }
    }
}

void Sala::setJueves(int jueves) {
    for (int i = 0; i < 8; i++) {
        if (this->jueves[i] == 0) {
            this->jueves[i] = jueves;
            break;
        }
    }
}

void Sala::setViernes(int viernes) {
    for (int i = 0; i < 8; i++) {
        if (this->viernes[i] == 0) {
            this->viernes[i] = viernes;
            break;
        }
    }
}

void Sala::setSabado(int sabado) {
    for (int i = 0; i < 6; i++) {
        if (this->sabado[i] == 0) {
            this->sabado[i] = sabado;
            break;
        }
    }
}

int Sala::diaConMasBloquesLibre() {

    int dia;
    int l = 0, m = 0, x = 0, j = 0, v = 0, s = 0;
    int menor;
    int dias[6];
    for (int i = 0; i < 8; i++) {
        if (lunes[i] == 0) {
            l++;
        }
        if (martes[i] == 0) {
            m++;
        }
        if (miercoles[i] == 0) {
            x++;
        }
        if (jueves[i] == 0) {
            j++;
        }
        if (viernes[i] == 0) {
            v++;
        }
        if (sabado[i] == 0 && i < 6) {
            s++;
        }
    }
    dias[0] = l, dias[1] = m, dias[2] = x, dias[3] = j, dias[4] = v, dias[5] = s;
    menor = 999999;
    dia = 9;
    for (int i = 0; i < 6; i++) {
        if (dias[i] < menor && dias[i] != 0) {
            menor = dias[i];
            dia = i;
        }
    }
    return dia;
}