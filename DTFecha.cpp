#include "DTFecha.h"

DTFecha::DTFecha(int dia, int mes, int anio) {
    this->dia = dia;
    this->mes = mes;
    this->anio = anio;
}

int DTFecha::getDia() {
    return dia;
}

int DTFecha::getMes() {
    return mes;
}

int DTFecha::getAnio() {
    return anio;
}

bool DTFecha::operator>=(const DTFecha& otra) {
    if (anio > otra.anio) return true;
    if (anio < otra.anio) return false;

    if (mes > otra.mes) return true;
    if (mes < otra.mes) return false;

    return dia >= otra.dia;
}