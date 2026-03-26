#include "libro.h"


libro::libro(string doi, string titulo, DTFecha fecha, string editorial, vector<string> palabras)
    : Publicacion(doi, titulo, fecha) {

    this->editorial = editorial;
    this->palabrasClave = palabras;
}

libro::~libro() {}

bool libro::contienePalabra(string palabra) {
    for (int i = 0; i < palabrasClave.size(); i++) {
        if (palabrasClave[i] == palabra) {
            return true;
        }
    }
    return false;
}