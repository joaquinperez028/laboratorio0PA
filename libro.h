#ifndef libro_H
#define libro_H

#include "Publicacion.h"
#include <vector>
#include <string>

using namespace std;

class libro : public Publicacion {
private:
    string editorial;
    vector<string> palabrasClave;

public:
    
    libro(string doi, string titulo, DTFecha fecha, string editorial, vector<string> palabras);

   
    ~libro();

    // Método polimórfico
    bool contienePalabra(string palabra);
};

#endif