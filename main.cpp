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
void imprimirInvestigadores(vector<Investigador *> &investigadores);
void relacionar(vector<Publicacion *> &publicaciones, vector<Investigador *> &investigadores);
void menuListarPublicaciones(const vector<Publicacion *> &listaPublicaciones, const vector<Investigador *> &listaInvestigadores);
void menuEliminarPublicacion(vector<Publicacion *> &listaPublicaciones);

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
            imprimirInvestigadores(investigadores);
            break;
        case 5:
            relacionar(publicaciones, investigadores);
            break;
        case 6:
            menuListarPublicaciones(publicaciones, investigadores);
            break;
        case 7:
            menuEliminarPublicacion(publicaciones);
            break;
        case 0:
            cout << "Saliendo del programa.." << endl;
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
        "Fundamentos de POO",
        DTFecha(15, 5, 2023),
        "Revista Programación Avanzada",
        "Introduccion a los principios fundamentales de la programacion orientada a objetos, explicando sus conceptos clave como clases, objetos, herencia y polimorfismo");

    Publicacion *a2 = new ArticuloRevista(
        "10.4567/jkl012",
        "Utilidad de diagramas UML",
        DTFecha(10, 2, 2024),
        "Revista Modelado de Software",
        "Ejercicio empirico de como los diagramas UML pueden ayudar en el proceso y documentacion de software, cubriendo los tipos mas importantes utilizados, como clases.");

    vector<string> kw1 = {"Diseno", "OOP", "Class"};
    vector<string> kw2 = {"Diagramas", "UML", "Modelado", "Software"};

    Publicacion *l1 = new Libro(
        "10.2345/def456",
        "Patrones de Diseno en c++",
        DTFecha(20, 8, 2022),
        "Editorial Software Design",
        kw1);

    Publicacion *l2 = new Libro(
        "10.5678/mno345",
        "Guia de UML",
        DTFecha(20, 8, 2022),
        "Editorial IEE",
        kw2);

    Publicacion *p1 = new PaginaWeb(
        "10.3456/ghi789",
        "Diagramas para Principiantes",
        DTFecha(20, 10, 2024),
        "www.umlparaprincipiantes.com",
        "En esta pagina web se presenta una gui completa sobre los diagramas UML, abordando los diagramas de casos de uso, de clases, de secuencia y de actividades");

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

void imprimirInvestigadores(vector<Investigador *> &investigadores)
{
    if (investigadores.empty())
    {
        cout << "No hay investigadores cargados\n";
    }
    else
    {
        for (int i = 0; i < investigadores.size(); i++)
        {
            cout << investigadores[i]->toString() << endl;
        }
    }
    esperar();
}
void relacionar(vector<Publicacion *> &publicaciones, vector<Investigador *> &investigadores)
{

    if (publicaciones.empty())
    {
        cout << "No hay publicaciones cargadas" << endl;
        esperar();
        return;
    }

    if (investigadores.empty())
    {
        cout << "No hay investigadores cargados" << endl;
        esperar();
        return;
    }

    for (int i = 0; i < investigadores.size(); i++)
    {

        string orcid = investigadores[i]->getORCID();

        // CARLA OLIVERI
        if (orcid == "0000-0003-1234-5678")
        {
            for (int j = 0; j < publicaciones.size(); j++)
            {
                string doi = publicaciones[j]->getDOI();

                if (doi == "10.1234/abc123" ||
                    doi == "10.4567/jkl012" ||
                    doi == "10.5678/mno345" ||
                    doi == "10.3456/ghi789")
                {

                    publicaciones[j]->agregarAutor(investigadores[i]);
                }
            }
        }

        // ALBERTO SANTOS
        if (orcid == "0000-0001-8765-4321")
        {
            for (int j = 0; j < publicaciones.size(); j++)
            {
                string doi = publicaciones[j]->getDOI();

                if (doi == "10.1234/abc123" ||
                    doi == "10.2345/def456" ||
                    doi == "10.4567/jkl012")
                {

                    publicaciones[j]->agregarAutor(investigadores[i]);
                }
            }
        }
    }

    cout << "Relaciones cargadas correctamente" << endl;
    esperar();
}

void menuListarPublicaciones(const vector<Publicacion *> &listaPublicaciones, const vector<Investigador *> &listaInvestigadores)
{
    string orcid, palabra;
    int d, m, a;

    cout << "Ingrese ORCID del investigador: ";
    cin >> orcid;
    cout << "Ingrese fecha (Ej. 5 6 2023): ";
    cin >> d >> m >> a;
    DTFecha fecha(d, m, a);
    cout << "Ingrese palabra clave a buscar: ";
    cin >> palabra;

    // Buscar al investigador
    Investigador *inv = nullptr;
    for (Investigador *i : listaInvestigadores)
    {
        if (i->getORCID() == orcid)
        {
            inv = i;
            break;
        }
    }

    if (inv != nullptr)
    {
        //  Llama a la función que ya definiste en la clase Investigador
        set<string> resultados = inv->listarPublicaciones(fecha, palabra);

        if (resultados.empty())
        {
            cout << "No se encontraron publicaciones con esos criterios." << endl;
            esperar();
        }
        else
        {
            cout << "DOIs de publicaciones encontradas:" << endl;
            for (string doi : resultados)
            {
                cout << "- " << doi << endl;
            }
            esperar();
        }
    }
    else
    {
        cout << "Error: Investigador no encontrado." << endl;
        esperar();
    }
}

void menuEliminarPublicacion(vector<Publicacion *> &listaPublicaciones)
{
    string doi;
    cout << "Ingrese el DOI de la publicacion que desea eliminar: ";
    cin >> doi;

    bool encontrada = false;

    for (auto it = listaPublicaciones.begin(); it != listaPublicaciones.end(); ++it)
    {
        if ((*it)->getDOI() == doi)
        {
            // delete llama al destructor ~Publicacion(): ahí cada autor hace removerPublicacion(this),
            // así los Investigador dejan de guardar un puntero a esta publicación (sin tocar el main)
            delete *it;
            listaPublicaciones.erase(it);

            encontrada = true;
            cout << "Publicacion con DOI " << doi << " eliminada con éxito." << endl;
            esperar();
            break;
        }
    }

    if (!encontrada)
    {
        cout << "Error: No existe una publicación con ese DOI." << endl;
        esperar();
    }
}

int main()
{
    vector<Publicacion *> publicaciones;
    vector<Investigador *> investigadores;

    mostrarMenu(publicaciones, investigadores);
}