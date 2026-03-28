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
void cargarPublicaciones(vector<Publicacion*>& publicaciones);
void mostrarMenu(vector<Publicacion*>& publicaciones);

void esperar() {
    cout << "Presione Enter para continuar...";
    cin.ignore(10000, '\n');
    cin.get();
}

void mostrarMenu(vector<Publicacion*>& publicaciones) {
    int opcion;

    do {
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

        switch (opcion) {
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
                break;
            case 7:
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

void cargarPublicaciones(vector<Publicacion*>& publicaciones) {
    if (!publicaciones.empty()) {
        cout << "Las publicaciones ya fueron cargadas." << endl;
        esperar();
        return;
    }

    Publicacion* a1 = new ArticuloRevista(
        "10.1234/abc123",
        "Importancia de la investigacion",
        DTFecha(1, 5, 2022),
        "Revista Cientifica",
        "Este articulo trata sobre la investigacion en sistemas"
    );

    Publicacion* a2 = new ArticuloRevista(
        "10.4567/jkl012",
        "Utilidad de diagramas UML",
        DTFecha(10, 12, 2023),
        "Revista Software",
        "Los diagramas UML ayudan al modelado de sistemas"
    );

    vector<string> kw1 = {"programacion", "c++"};
    vector<string> kw2 = {"uml", "modelado"};

    Publicacion* l1 = new Libro(
        "20.1111/libro1",
        "Programacion avanzada",
        DTFecha(15, 3, 2020),
        "Editorial A",
        kw1
    );

    Publicacion* l2 = new Libro(
        "20.2222/libro2",
        "Modelado UML",
        DTFecha(20, 8, 2021),
        "Editorial B",
        kw2
    );

    Publicacion* p1 = new PaginaWeb(
        "30.3333/web1",
        "Tutorial UML",
        DTFecha(5, 6, 2023),
        "www.uml.com",
        "Contenido sobre UML y diagramas"
    );

    publicaciones.push_back(a1);
    publicaciones.push_back(a2);
    publicaciones.push_back(l1);
    publicaciones.push_back(l2);
    publicaciones.push_back(p1);

    cout << "Publicaciones cargadas con exito." << endl;
    esperar();
}

int main() {
    vector<Publicacion*> publicaciones;
    vector<Investigador*> investigadores;

    mostrarMenu(publicaciones, investigadores);
}