#include <iostream>
#include <vector>
#include <set>

#include "DTRefer.h"
#include "DTFecha.h"

using namespace std;

class Investigador{
    private:
        string ORCID;
        string nombre;
        string institucion;
        vector<Publicacion*> publicaciones;
    public:
        Investigador(string, string, string); 
     //destructor   investigador();
        string toString();
        set<string> listarPublicaciones(DTFecha, string); //Retorna set<string> en lugar de string (un conjunto de DOIs)
        void agregarPublicacion(Publicacion*);
        string getORCID();
        string getNombre();
        string getInstitucion();
};