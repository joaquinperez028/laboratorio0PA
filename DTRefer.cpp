#include "DTRefer.h"
using namespace std;

DTRefer::DTRefer(string doi, string titulo, DTFecha fecha, set<string> autores) 
                     : DOI(doi), titulo(titulo), fecha(fecha), autores(autores) {
}

string DTRefer::getDOI() {
    return DOI;
}

string DTRefer::getTitulo() {
    return titulo;
}

DTFecha DTRefer::getFecha() {
    return fecha;
}

set<string> DTRefer::getAutores() {
    return autores;
}