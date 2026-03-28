#include "ArticuloRevista.h"
#include "DTFecha.h"

ArticuloRevista::ArticuloRevista(string DOI, string titulo, DTFecha fecha, string revista, string extracto):Publicacion(DOI, titulo, fecha){
    this->revista = revista;
    this->extracto = extracto;
}

bool ArticuloRevista::contienePalabra(string palabra){
    if(this->extracto.find(palabra) != string::npos)
        return true;
    else    
        return false;
}