#ifndef DTREFER_H
#define DTREFER_H

#include <string>
#include <set>
#include "DTFecha.h"

using namespace std;

class DTRefer {
public:
    string DOI;
    string titulo;
    DTFecha fecha;
    set<string> autores;
};

#endif