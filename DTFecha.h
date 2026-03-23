#ifndef DTFECHA_H
#define DTFECHA_H

class DTFecha {
private:
    int dia;
    int mes;
    int anio;

public:
    DTFecha(int d, int m, int a);

    int getDia();
    int getMes();
    int getAnio();
};

#endif