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
        vector<Investigador*> autores;
        
    public:
        Publicacion(string, string, DTFecha); //constructor
        virtual bool contienePalabra(string)=0; //definicion de la operacion abstracta
        virtual ~Publicacion(); // lo definí pero falta implementar el destructor
        DTFecha getFecha();
        string getDOI();
        DTRefer getDT();
        void agregarAutor(Investigador* i); //operacion que carga el puntero al investigador, debo llamar cada vez que cargo una nueva publicacion y autor. Igual del otro lado
};



