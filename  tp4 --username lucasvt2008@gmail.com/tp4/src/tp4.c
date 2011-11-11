#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

int main(int argc,char *argv[])
{
	ListaGrafo lista;
	InicializaGrafo(&lista);
	LeEntrada(&lista);
	//GeraSaidaPadrao(&lista, 1);
	//ImprimirEntradas(&lista);
	LiberaGrafo(&lista);
	printf("FIM\n");
	return 0;
}
