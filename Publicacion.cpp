#include "Publicacion.h"
#include "Investigador.h"
#include <iostream>

//constructor
Publicacion::Publicacion(string doi, string titulo, DTFecha fecha)
                          : DOI(doi), titulo(titulo), fecha(fecha) {
    this->DOI = doi;
    this->titulo = titulo;
    this->fecha = fecha;
}

Publicacion::~Publicacion() {
    //pendiente implementar
}

DTFecha Publicacion::getFecha() {
    return this->fecha;
}

string Publicacion::getDOI() {
    return this->DOI;

}

DTRefer Publicacion::getDT() {
        set<string> nombresAutores;

        for (int i = 0; i < autores.size(); i++) {
            nombresAutores.insert(autores[i]->getNombre());
        }

        DTRefer ref(DOI, titulo, fecha, nombresAutores);
        return ref;
}

//operacion desde publicacion para asociar un autor a una nueva publicacion 
void Publicacion::agregarAutor(Investigador* i) {
    autores.push_back(i);
    i->agregarPublicacion(this); // este NO vuelve a llamar
}


