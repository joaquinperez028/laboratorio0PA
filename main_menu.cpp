#include <iostream>
#include <vector>
#include <set>

#include "ArticuloRevista.h"
#include "Libro.h"
#include "PaginaWeb.h"
#include "Investigador.h"
#include "DTFecha.h"

using namespace std;

// Prototipos de funciones
void mostrarMenu();
void crearArticuloRevista(vector<Publicacion*>& publicaciones);
void crearLibro(vector<Publicacion*>& publicaciones);
void crearPaginaWeb(vector<Publicacion*>& publicaciones);
void crearInvestigador(vector<Investigador*>& investigadores);
void mostrarPublicaciones(const vector<Publicacion*>& publicaciones);
void mostrarInvestigadores(const vector<Investigador*>& investigadores);
void menuListarPublicaciones(const vector<Publicacion*> listaPublicaciones); 
void menuEliminarPublicacion(const vector<Investigador*> listaInvestigadores);

int main() {
    vector<Publicacion*> publicaciones;
    vector<Investigador*> investigadores;
    int opcion;

    cout << "=== GESTOR DE PUBLICACIONES ===" << endl;

    do {
        mostrarMenu();
        cout << "Ingrese su opcion: ";
        cin >> opcion;
        cin.ignore(); // Limpiar el buffer de entrada

        switch (opcion) {
            case 1:
                crearArticuloRevista(publicaciones);
                break;
            case 2:
                crearLibro(publicaciones);
                break;
            case 3:
                crearPaginaWeb(publicaciones);
                break;
            case 4:
                crearInvestigador(investigadores);
                break;
            case 5:
                mostrarPublicaciones(publicaciones);
                break;
            case 6:
                mostrarInvestigadores(investigadores);
                break;
            case 0:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opcion invalida. Intente de nuevo." << endl;
        }
    } while (opcion != 0);

    // Liberar memoria
    for (auto pub : publicaciones) {
        delete pub;
    }
    for (auto inv : investigadores) {
        delete inv;
    }

    return 0;
}

void mostrarMenu() {
    cout << "\n====== MENU ======" << endl;
    cout << "1. Crear Articulo de Revista" << endl;
    cout << "2. Crear Libro" << endl;
    cout << "3. Crear Pagina Web" << endl;
    cout << "4. Crear Investigador" << endl;
    cout << "5. Ver Publicaciones" << endl;
    cout << "6. Ver Investigadores" << endl;
    cout << "0. Salir" << endl;
    cout << "==================" << endl;
}

void crearArticuloRevista(vector<Publicacion*>& publicaciones) {
    string doi, titulo, revista, extracto;
    int dia, mes, anio;

    cout << "\n--- CREAR ARTICULO DE REVISTA ---" << endl;
    cout << "DOI: ";
    getline(cin, doi);
    cout << "Titulo: ";
    getline(cin, titulo);
    cout << "Revista: ";
    getline(cin, revista);
    cout << "Extracto: ";
    getline(cin, extracto);
    cout << "Fecha (dia mes anio): ";
    cin >> dia >> mes >> anio;

    Publicacion* articulo = new ArticuloRevista(doi, titulo, DTFecha(dia, mes, anio), revista, extracto);
    publicaciones.push_back(articulo);
    cout << "Articulo creado exitosamente." << endl;
}

void crearLibro(vector<Publicacion*>& publicaciones) {
    string doi, titulo, editorial, palabra;
    vector<string> palabrasClave;
    int dia, mes, anio;
    int cantidad;

    cout << "\n--- CREAR LIBRO ---" << endl;
    cout << "DOI: ";
    getline(cin, doi);
    cout << "Titulo: ";
    getline(cin, titulo);
    cout << "Editorial: ";
    getline(cin, editorial);
    cout << "Cantidad de palabras clave: ";
    cin >> cantidad;
    cin.ignore();
    cout << "Ingrese las palabras clave:" << endl;
    for (int i = 0; i < cantidad; i++) {
        cout << "Palabra " << (i + 1) << ": ";
        getline(cin, palabra);
        palabrasClave.push_back(palabra);
    }
    cout << "Fecha (dia mes anio): ";
    cin >> dia >> mes >> anio;

    Publicacion* libro = new Libro(doi, titulo, DTFecha(dia, mes, anio), editorial, palabrasClave);
    publicaciones.push_back(libro);
    cout << "Libro creado exitosamente." << endl;
}

void crearPaginaWeb(vector<Publicacion*>& publicaciones) {
    string doi, titulo, url, contenido;
    int dia, mes, anio;

    cout << "\n--- CREAR PAGINA WEB ---" << endl;
    cout << "DOI: ";
    getline(cin, doi);
    cout << "Titulo: ";
    getline(cin, titulo);
    cout << "URL: ";
    getline(cin, url);
    cout << "Contenido extraido: ";
    getline(cin, contenido);
    cout << "Fecha (dia mes anio): ";
    cin >> dia >> mes >> anio;

    Publicacion* pagina = new PaginaWeb(doi, titulo, DTFecha(dia, mes, anio), url, contenido);
    publicaciones.push_back(pagina);
    cout << "Pagina web creada exitosamente." << endl;
}

void crearInvestigador(vector<Investigador*>& investigadores) {
    string orcid, nombre, institucion;

    cout << "\n--- CREAR INVESTIGADOR ---" << endl;
    cout << "ORCID: ";
    getline(cin, orcid);
    cout << "Nombre: ";
    getline(cin, nombre);
    cout << "Institucion: ";
    getline(cin, institucion);

    Investigador* inv = new Investigador(orcid, nombre, institucion);
    investigadores.push_back(inv);
    cout << "Investigador creado exitosamente." << endl;
}

void mostrarPublicaciones(const vector<Publicacion*>& publicaciones) {
    if (publicaciones.empty()) {
        cout << "\nNo hay publicaciones registradas." << endl;
        return;
    }

    cout << "\n=== PUBLICACIONES ===" << endl;
    for (int i = 0; i < publicaciones.size(); i++) {
        DTRefer dt = publicaciones[i]->getDT();
        cout << (i + 1) << ". " << dt.getDOI() << " - " << dt.getTitulo() << endl;
    }
}

void mostrarInvestigadores(const vector<Investigador*>& investigadores) {
    if (investigadores.empty()) {
        cout << "\nNo hay investigadores registrados." << endl;
        return;
    }

    cout << "\n=== INVESTIGADORES ===" << endl;
    for (int i = 0; i < investigadores.size(); i++) {
        cout << (i + 1) << ". " << investigadores[i]->toString() << endl;
    }
}



void menuListarPublicaciones() {
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

void menuEliminarPublicacion() {
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