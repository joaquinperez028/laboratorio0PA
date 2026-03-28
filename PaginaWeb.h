#ifndef PAGINAWEB_H
#define PAGINAWEB_H

#include <string>
#include "Publicacion.h"
#include "DTFecha.h"

class PaginaWeb : public Publicacion
{
private:
    std::string url;
    std::string contenidoExtraido;

public:
    PaginaWeb(std::string DOI, std::string titulo, DTFecha fecha,
              std::string url, std::string contenidoExtraido);

    bool contienePalabra(std::string palabra);
};

#endif