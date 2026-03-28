#include "paginaWeb.h"

PaginaWeb ::PaginaWeb(string DOI, string titulo, DTFecha fecha,
                      string url, string contenido) : Publicacion(DOI, titulo, fecha)
{
    this->url = url;
    this->contenidoExtraido = contenido;
}

bool PaginaWeb ::contienePalabra(string palabra)
{
    return contenidoExtraido.find(palabra) != string::npos;
}
