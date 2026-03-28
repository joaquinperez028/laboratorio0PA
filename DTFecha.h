#ifndef DTFECHA_H
#define DTFECHA_H

class DTFecha {
private:
    int dia;
    int mes;
    int anio;

public:
    DTFecha(int dia, int mes, int anio);
    int getDia();
    int getMes();
    int getAnio();
    bool operator>=(const DTFecha& otra); //agrego esta operacion para que funcione el comparador en investigador
};

#endif