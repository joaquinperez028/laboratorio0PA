#include "Investigador.h"
#include "Publicacion.h"

Investigador::Investigador(string ORCID, string nombre, string institucion){
    this->ORCID = ORCID;
    this->nombre = nombre;
    this->institucion = institucion;
}

void Investigador::agregarPublicacion(Publicacion* p) {
    publicaciones.push_back(p);
}

void Investigador::removerPublicacion(Publicacion* p) {
    for (int i = (int)publicaciones.size() - 1; i >= 0; i--) {
        if (publicaciones[i] == p) {
            publicaciones.erase(publicaciones.begin() + i);
        }
    }
}

string Investigador::toString(){
    return this->ORCID + "->" + this->nombre + "/" + this->institucion;
}

string Investigador::getORCID(){
    return this->ORCID;
}

string Investigador::getNombre(){
    return this->nombre;
}

string Investigador::getInstitucion(){
    return this->institucion;
}

set<string> Investigador::listarPublicaciones(DTFecha fecha, string palabra){
    set<string> resultado;
    
    for(int i = 0; i < publicaciones.size(); i++){
        if(publicaciones[i]->getFecha() >= fecha){ 
            if(publicaciones[i]->contienePalabra(palabra)){
                resultado.insert(publicaciones[i]->getDOI()); // Obtener el DOI y agregarlo al conjunto
            }
        }
    }
    
    return resultado;
}
