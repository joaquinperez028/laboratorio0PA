#ifndef DTREFER_H
#define DTREFER_H

#include <iostream>
#include <string>
#include <set>
#include "DTFecha.h"

using namespace std;

class DTRefer
{
private:
    string DOI;
    string titulo;
    DTFecha fecha;
    set<string> autores;

public:
    DTRefer(string doi, string titulo, DTFecha fecha, set<string> autores);
    string getDOI() const;
    string getTitulo() const;
    DTFecha getFecha() const;
    set<string> getAutores() const;
};

ostream &operator<<(std::ostream &os, const DTRefer &dt);

#endif