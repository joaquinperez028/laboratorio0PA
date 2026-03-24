#include "Publicacion.h"
#include "Investigador.h"
#include <iostream>

//constructor
Publicacion::Publicacion(string doi, string titulo, DTFecha fecha){
    this->DOI = doi;
    this->titulo = titulo;
    this->fecha = fecha;
}


DTRefer Publicacion::getDT() {
        DTRefer ref;

        ref.DOI = DOI;
        ref.titulo = titulo;
        ref.fecha = fecha;

        for (int i = 0; i < autores.size(); i++) { //con un for "cosecho" solo los nombres de los autores, recorriendo el arreglo
            ref.autores.insert(autores[i]->getNombre());
        }

        return ref;
}

//operacion desde publicacion para asociar un autor a una nueva publicacion 
void Publicacion::agregarAutor(Investigador* i) {
    autores.push_back(i);
    i->agregarPublicacion(this); // este NO vuelve a llamar
}

/*operacion desde investigador, esto va en el cpp de investigador
void Investigador::agregarPublicacion(Publicacion* p) {
    publicaciones.push_back(p);
}*/

