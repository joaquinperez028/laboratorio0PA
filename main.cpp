#include <iostream>
#include <vector>
#include "Publicacion.h"
#include "Investigador.h"
#include "ArticuloRevista.h"
#include "Libro.h"
#include "PaginaWeb.h"

using namespace std;

// funciones auxiliares
void esperar();
void cargarPublicaciones(vector<Publicacion *> &publicaciones);
void mostrarMenu(vector<Publicacion *> &publicaciones, vector<Investigador *> &investigadores);
void cargarInvestigadores(vector<Investigador *> &investigadores);
void imprimirPublicaciones(vector<Publicacion *> &publicaciones); // necesita de la sobrecarga para funcionar

//agrego &publicaciones porque pateaba en la llamada a la funcion
// Sin el 'const', porque vamos a modificar las listas
void menuListarPublicaciones(const vector<Publicacion*> listaPublicaciones); 
void menuEliminarPublicacion(vector<Publicacion*>& listaPublicaciones, vector<Investigador*>& listaInvestigadores);

void esperar()
{
    cout << "Presione Enter para continuar...";
    cin.ignore(10000, '\n');
    cin.get();
}

void mostrarMenu(vector<Publicacion *> &publicaciones, vector<Investigador *> &investigadores)
{
    int opcion;

    do
    {
        system("clear");

        cout << " ***** MENU PRINCIPAL ***** " << endl;
        cout << "1. CARGAR PUBLICACIONES " << endl;
        cout << "2. CARGAR INVESTIGADORES " << endl;
        cout << "3. IMPRIMIR TODAS LAS PUBLICACIONES " << endl;
        cout << "4. IMPRIMIR TODOS LOS INVESTIGADORES " << endl;
        cout << "5. REGISTRAR RELACIONES INVESTIGADORES/PUBLICACIONES " << endl;
        cout << "6. MOSTRAR UNA PUBLICACION " << endl;
        cout << "7. ELIMINAR UNA PUBLICACION " << endl;
        cout << "0. Salir" << endl;
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            cargarPublicaciones(publicaciones);
            break;
        case 2:
            cargarInvestigadores(investigadores);
            break;
        case 3:
            imprimirPublicaciones(publicaciones);
            break;
        case 4:
            //imprimirInvestigadores(investigadores);
            break;
        case 5:
            //relacionar(publicaciones, investigadores);
            break;
        case 6:
            menuListarPublicaciones(publicaciones, investigadores);
             break;
            break;
        case 7:
            menuEliminarPublicacion(publicaciones, investigadores);
            break;
        case 0:
            cout << "Saliendo del programa..." << endl;
            break;
        default:
            cout << "Opcion no valida. Intente nuevamente." << endl;
            esperar();
        }
    } while (opcion != 0);
}

void cargarPublicaciones(vector<Publicacion *> &publicaciones)
{
    if (!publicaciones.empty())
    {
        cout << "Las publicaciones ya fueron cargadas." << endl;
        esperar();
        return;
    }

    Publicacion *a1 = new ArticuloRevista(
        "10.1234/abc123",
        "Importancia de la investigacion",
        DTFecha(1, 5, 2022),
        "Revista Cientifica",
        "Este articulo trata sobre la investigacion en sistemas");

    Publicacion *a2 = new ArticuloRevista(
        "10.4567/jkl012",
        "Utilidad de diagramas UML",
        DTFecha(10, 12, 2023),
        "Revista Software",
        "Los diagramas UML ayudan al modelado de sistemas");

    vector<string> kw1 = {"programacion", "c++"};
    vector<string> kw2 = {"uml", "modelado"};

    Publicacion *l1 = new Libro(
        "20.1111/libro1",
        "Programacion avanzada",
        DTFecha(15, 3, 2020),
        "Editorial A",
        kw1);

    Publicacion *l2 = new Libro(
        "20.2222/libro2",
        "Modelado UML",
        DTFecha(20, 8, 2021),
        "Editorial B",
        kw2);

    Publicacion *p1 = new PaginaWeb(
        "30.3333/web1",
        "Tutorial UML",
        DTFecha(5, 6, 2023),
        "www.uml.com",
        "Contenido sobre UML y diagramas");

    publicaciones.push_back(a1);
    publicaciones.push_back(a2);
    publicaciones.push_back(l1);
    publicaciones.push_back(l2);
    publicaciones.push_back(p1);

    cout << "Publicaciones cargadas con exito." << endl;
    esperar();
}

void cargarInvestigadores(vector<Investigador *> &i)
{
    if (!i.empty()) 
    {
        cout << "Los investigadores ya fueron cargados" << endl;
        esperar();
        return;
    }
    else
    {
        Investigador *i1 = new Investigador(
            "0000-0003-1234-5678",
            "Carla Oliveri",
            "Universidad de la Republica");
        Investigador *i2 = new Investigador(
            "0000-0001-8765-4321",
            "Alberto Santos",
            "Instituto Tecnico");

        i.push_back(i1);
        i.push_back(i2);
        cout << "Investigadores cargados con exito" << endl;
        esperar();
    }
}

void imprimirPublicaciones(vector<Publicacion *> &p)
{
    if (p.empty())
    {
        cout << "No existen publicaciones cargadas" << endl;
        esperar();
        return;
    }
    else
    {
        vector<DTRefer> impPubli;
        for (size_t i = 0; i < p.size(); i++)
        {
            impPubli.push_back(p[i]->getDT());
        }
        for (size_t i = 0; i < impPubli.size(); i++)
        {
            cout << impPubli[i] << endl;
        }
        esperar();
        return;
    }
}

void menuListarPublicaciones(const vector<Publicacion*>& listaPublicaciones, const vector<Investigador*>& listaInvestigadores)
{
    string orcid, palabra;
    int d, m, a;

    cout << "Ingrese ORCID del investigador: ";
    cin >> orcid;
    cout << "Ingrese fecha límite (día mes año): ";
    cin >> d >> m >> a;
    DTFecha fechaLimite(d, m, a);
    cout << "Ingrese palabra clave a buscar: ";
    cin >> palabra;

    // Buscar al investigador
    Investigador* inv = nullptr;
    for (Investigador* i : listaInvestigadores) {
        if (i->getORCID() == orcid) {
            inv = i;
            break;
        }
    }

    if (inv != nullptr) {
        // 2. Llamar a la función que ya definiste en la clase Investigador
        set<string> resultados = inv->listarPublicaciones(fechaLimite, palabra);

        if (resultados.empty()) {
            cout << "No se encontraron publicaciones con esos criterios." << endl;
        } else {
            cout << "DOIs de publicaciones encontradas:" << endl;
            for (string doi : resultados) {
                cout << "- " << doi << endl;
            }
        }
    } else {
        cout << "Error: Investigador no encontrado." << endl;
    }
}

void menuEliminarPublicacion(vector<Publicacion*>& listaPublicaciones, vector<Investigador*>& listaInvestigadores)
{
    string doi;
    cout << "Ingrese el DOI de la publicación a eliminar: ";
    cin >> doi;

    bool encontrada = false;
    
    // 1. Buscar en el vector global de publicaciones
    for (auto it = listaPublicaciones.begin(); it != listaPublicaciones.end(); ++it) {
        if ((*it)->getDOI() == doi) {
            
            // 2. Liberar memoria del objeto (Importante si usaste 'new')
            delete *it; 
            
            // 3. Quitar del vector
            listaPublicaciones.erase(it);
            
            encontrada = true;
            cout << "Publicación con DOI " << doi << " eliminada con éxito." << endl;
            break;
        }
    }

    if (!encontrada) {
        cout << "Error: No existe una publicación con ese DOI." << endl;
    }

}

int main()
{
    vector<Publicacion *> publicaciones;
    vector<Investigador *> investigadores;

    mostrarMenu(publicaciones, investigadores);
}