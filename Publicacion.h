#ifndef PUBLICACION_H
#define PUBLICACION_H

#include <iostream>
#include <vector>
#include <set>

#include "DTRefer.h"
#include "DTFecha.h"
using namespace std;

class Investigador;

class Publicacion
{
private:
    string DOI;
    string titulo;
    DTFecha fecha;
    vector<Investigador *> autores;

public:
    Publicacion(string, string, DTFecha);
    virtual bool contienePalabra(string) = 0;
    virtual ~Publicacion();
    DTFecha getFecha();
    string getDOI();
    DTRefer getDT();
    void agregarAutor(Investigador *i);
};

#endif
