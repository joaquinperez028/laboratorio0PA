all: Investigador.o Publicacion.o PaginaWeb.o Libro.o ArticuloRevista.o DTFecha.o \
	DTRefer.o main.o
	g++ Investigador.o Publicacion.o PaginaWeb.o Libro.o ArticuloRevista.o DTFecha.o \
	DTRefer.o main.o -o programa

Investigador.o:
	g++ -c Investigador.cpp

Publicacion.o:
	g++ -c Publicacion.cpp

PaginaWeb.o:
	g++ -c PaginaWeb.cpp

Libro.o:
	g++ -c Libro.cpp

ArticuloRevista.o:
	g++ -c ArticuloRevista.cpp

DTFecha.o:
	g++ -c DTFecha.cpp

DTRefer.o:
	g++ -c DTRefer.cpp

main.o:
	g++ -c main.cpp

clean:
	rm -f Investigador.o Publicacion.o PaginaWeb.o Libro.o ArticuloRevista.o DTFecha.o \
	DTRefer.o main.o programa

run:
	make clean
	clear
	make
	./programa

