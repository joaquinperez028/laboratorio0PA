#include "Libro.h"


Libro::Libro(string doi, string titulo, DTFecha fecha, string editorial, vector<string> palabras)
    : Publicacion(doi, titulo, fecha) {

    this->editorial = editorial;
    this->palabrasClave = palabras;
}

Libro::~Libro() {}

bool Libro::contienePalabra(string palabra) {
    for (int i = 0; i < palabrasClave.size(); i++) {
        if (palabrasClave[i] == palabra) {
            return true;
        }
    }
    return false;
}