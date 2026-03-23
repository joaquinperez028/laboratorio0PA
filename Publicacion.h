#include <iostream>
#include <vector>
#include <set>
using namespace std;

#include "Investigador.h"

class Investigador;

class Publicacion{
    private:
        string DOI;
        string titulo;
        DTFecha fecha;
        vector<Investigador*> autores; //hacer lo mismo pero con los investigadores

    public:
        Publicacion(string, string, DTFecha); //constructor
        DTRefer getDT();
        void agregarAutor(Investigador* i); //operacion que carga el puntero al investigador, debo llamar cada vez que cargo una nueva publicacion y autor. Igual del otro lado

};



