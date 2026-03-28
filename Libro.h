#ifndef libro_H
#define libro_H

#include "Publicacion.h"
#include "DTFecha.h"
#include <vector>
#include <string>

using namespace std;

class Libro : public Publicacion
{
private:
    string editorial;
    vector<string> palabrasClave;

public:
    Libro(string doi, string titulo, DTFecha fecha, string editorial, vector<string> palabras);

    ~Libro();

    // Método polimórfico
    bool contienePalabra(string palabra);
};

#endif