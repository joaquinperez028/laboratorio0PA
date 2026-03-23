#ifndef DTREFER_H
#define DTREFER_H

#include <string>
#include <set>
#include "DTFecha.h"

using namespace std;

class DTRefer {
private:
    string DOI;
    string titulo;
    DTFecha fecha;
    set<string> autores;

public:
    DTRefer(string doi, string titulo, DTFecha fecha, set<string> autores);

    string getDOI();
    string getTitulo();
    DTFecha getFecha();
    set<string> getAutores();
};

#endif