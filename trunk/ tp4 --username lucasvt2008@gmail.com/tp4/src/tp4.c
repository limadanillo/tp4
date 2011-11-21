#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

int main(int argc,char *argv[])
{
	ListaGrafo lista;
	InicializaGrafo(&lista);
	LeEntrada(&lista, 2);
	GeraSaidaPadrao(&lista, 2);
	LiberaGrafo(&lista);
	printf("FIM\n");
	return 0;
}
