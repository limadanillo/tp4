#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

int main(int argc,char *argv[])
{
	ListaGrafo lista;
	InicializaGrafo(&lista);
	LeEntrada(&lista);
	ImprimirEntradas(&lista);
	//ConstroiMatrizDeAdjacencia(lista.primeiro->proximo);
	//LiberaGrafo(&lista);
	//Consegui modificar
	printf("FIM\n");
	return 0;
}
