
investigador.o: publicacion.o
	g++ -c investigador.cpp

publicacion.o: investigador.o
	g++ -c publicacion.cpp

paginaWeb.o:
	g++ -c paginaWeb.cpp

libro.o:
	g++ -c libro.cpp

artivuloRevista.o:
	g++ -c artivuloRevista.cpp
