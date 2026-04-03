#include <iostream>
#include "DTRefer.h"

DTRefer::DTRefer(string doi, string titulo, DTFecha fecha, set<string> autores)
    : DOI(doi), titulo(titulo), fecha(fecha), autores(autores)
{
}

string DTRefer::getDOI() const
{
    return DOI;
}

string DTRefer::getTitulo() const
{
    return titulo;
}

DTFecha DTRefer::getFecha() const
{
    return fecha;
}

set<string> DTRefer::getAutores() const
{
    return autores;
}

ostream &operator<<(ostream &os, const DTRefer &dt)
{
    os << dt.getDOI() << " -> "
       << dt.getTitulo() << " ("
       << dt.getFecha().getDia() << "/"
       << dt.getFecha().getMes() << "/"
       << dt.getFecha().getAnio() << ") / ";

    set<string> autores = dt.getAutores();

    bool primero = true;
    for (const string &a : autores)
    {
        if (!primero)
            os << ", ";
        os << a;
        primero = false;
    }

    return os;
}