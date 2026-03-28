#include <iostream>
#include <vector>
#include <set>

#include "ArticuloRevista.h"
#include "Libro.h"
#include "PaginaWeb.h"
#include "Investigador.h"
#include "DTFecha.h"

using namespace std;

int main() {

    // =========================
    // 1. Crear publicaciones
    // =========================

    // Articulos
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

    // Libros
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

    // Pagina web
    Publicacion* p1 = new PaginaWeb(
        "30.3333/web1",
        "Tutorial UML",
        DTFecha(5, 6, 2023),
        "www.uml.com",
        "Contenido sobre UML y diagramas"
    );

    // =========================
    // 2. Guardar en colección
    // =========================

    vector<Publicacion*> publicaciones = {a1, a2, l1, l2, p1};

    // =========================
    // 3. Imprimir getDT()
    // =========================

    cout << "=== PUBLICACIONES ===" << endl;

    for (int i = 0; i < publicaciones.size(); i++) {
        DTRefer dt = publicaciones[i]->getDT();

        cout << dt.getDOI() << " - " << dt.getTitulo() << endl;
    }

    // =========================
    // 4. Crear investigadores
    // =========================

    Investigador* i1 = new Investigador(
        "0000-0001",
        "Carla Oliveri",
        "UTEC"
    );

    Investigador* i2 = new Investigador(
        "0000-0002",
        "Juan Perez",
        "UDELAR"
    );

    // =========================
    // 5. Mostrar investigadores
    // =========================

    cout << "\n=== INVESTIGADORES ===" << endl;
    cout << i1->toString() << endl;
    cout << i2->toString() << endl;

    // =========================
    // 6. Asociaciones
    // =========================

    a1->agregarAutor(i1);
    a2->agregarAutor(i1);
    l1->agregarAutor(i1);

    l2->agregarAutor(i2);
    p1->agregarAutor(i2);

    // =========================
    // 7. Listar publicaciones
    // =========================

    cout << "\n=== FILTRO UML ===" << endl;

    set<string> res = i1->listarPublicaciones(DTFecha(10,12,2023), "UML");

    for (auto it = res.begin(); it != res.end(); it++) {
        cout << *it << endl;
    }

    // =========================
    // 8. Eliminar publicación
    // =========================

    delete a2; // 10.4567/jkl012

    //OJO: esto deja punteros colgando (lo veremos después)

    // =========================
    // 9. Liberar memoria
    // =========================

    delete a1;
    delete l1;
    delete l2;
    delete p1;

    delete i1;
    delete i2;

    return 0;
}