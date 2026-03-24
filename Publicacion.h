#include <iostream>
#include <vector>
#include <set>

#include "DTRefer.h"
#include "DTFecha.h"
using namespace std;

class Investigador;

class Publicacion{
    private:
        string DOI;
        string titulo;
        DTFecha fecha;
        vector<Investigador*> autores; //hacer lo mismo pero con los investigadores
        // falta la declaracion de la variable polimorfica
    public:
        Publicacion(string, string, DTFecha); //constructor
        // falta el destructor
        // falta getFecha operacion agregada para poder hacer la comparacion desde listarPublicaciones
        // falta getDOI
        DTRefer getDT();
        void agregarAutor(Investigador* i); //operacion que carga el puntero al investigador, debo llamar cada vez que cargo una nueva publicacion y autor. Igual del otro lado

};



