#include <stdio.h>
#include <stdlib.h>
#include "kruskal.h"

/*
Este programa é uma implementação do algoritmo de Kruskal para
determinar uma árvore geradora mínima para um grafo conectado, não direcionado e
grafo ponderado. Esta aplicação é projetada especificamente
para os dados de teste requeridos pelo projeto.
*/

void Kruskal(int **matriz, int numVertices, int numArestas)
{
	int U[numVertices];
	int ConjuntoArestas[numArestas][3]; // Conjunto de arestas
	int ArvoreMinima[numVertices-1][3];  // Conjunto de arestas da árvore geradora mínima
	int aux_NumArestas = 0; // Búmero de arestas da árvore geradora mínima
	int proximo_vetice = 0; // Próxim aresta ainda não considerado
	//int peso = 0; // Caminho total árvore geradora mínima
	int a, b, c, i, j, k; // Variáveis contado0ras

	/* Inicializa conjunto de arestas */
	k = 0;
	for (i = 0; i < numVertices; i++)
	{
		for (j = 0; j < numVertices; j++)
		{
			if (j > i)
			{
				ConjuntoArestas[k][0] = i;          /* first vertex of edge */
				ConjuntoArestas[k][1] = j;          /* second vertex of edge */
				ConjuntoArestas[k][2] = matriz[i][j];    /* peso of edge */
				k++;
			}
		}
	}

	for (i=numArestas - 1; i > 0; i--)
	{
		for (j = 0; j < i; j++)
		{
			if (ConjuntoArestas[j][2] > ConjuntoArestas[j+1][2])
			{
				a = ConjuntoArestas[j][0];
				b = ConjuntoArestas[j][1];
				c = ConjuntoArestas[j][2];
				ConjuntoArestas[j][0] = ConjuntoArestas[j+1][0];
				ConjuntoArestas[j][1] = ConjuntoArestas[j+1][1];
				ConjuntoArestas[j][2] = ConjuntoArestas[j+1][2];
				ConjuntoArestas[j+1][0] = a;
				ConjuntoArestas[j+1][1] = b;
				ConjuntoArestas[j+1][2] = c;
			}
		}
	}


	/* create n disjoint subsets */
   CriaSubConjunto(U, numVertices);

   /* initialize set of edges in min. span. tree to empty */
   for (i = 0; i < numVertices - 1; i++)
   {
	   for (j = 0; j < 3; j++)
	   {
		   ArvoreMinima[i][j] = -1;            /* '-1' == Vazio */
	   }
   }

   /* find minimal spanning tree */
   while (aux_NumArestas < numVertices - 1)
   {
	   a = ConjuntoArestas[proximo_vetice][0];
	   b = ConjuntoArestas[proximo_vetice][1];

	   i = ProcuraPosicaoVertice(U, a);
	   j = ProcuraPosicaoVertice(U, b);

	   if (!Igual(i, j))
	   {
		   Reordena(U, i, j);
		   ArvoreMinima[aux_NumArestas][0] = ConjuntoArestas[proximo_vetice][0];
		   ArvoreMinima[aux_NumArestas][1] = ConjuntoArestas[proximo_vetice][1];
		   ArvoreMinima[aux_NumArestas][2] = ConjuntoArestas[proximo_vetice][2];
		   aux_NumArestas++;
	   }
	   proximo_vetice++;
	}

   /*
    * Imprime a árvore geradora mínima
    */
//   for (i=0; i<numVertices - 1; i++)
//   {
//		printf("%d %d %d", ArvoreMinima[i][0], ArvoreMinima[i][1], ArvoreMinima[i][2]);
//		if (i < numVertices - 2) printf("\n");
//		//peso = peso + ArvoreMinima[i][2]; //tamanho do caminho percorrido
//	}
//	printf("\n\n");
   ImprimeArvoreGeradoraMinima(ArvoreMinima, numVertices);
}

int ProcuraPosicaoVertice(int U[], int i)
{
	int j = i;
	while (U[j] != j) j = U[j];
	return j;
}

void Reordena(int U[], int p, int q)
{
	if (p < q) U[q] = p;
	else U[p] = q;
}

int Igual(int p, int q)
{
	if (p == q) return 1;
	else return 0;
}

void CriaSubConjunto(int U[], int n)
{
	int i;
	for (i = 0; i < n; i++) U[i] = i;
}

void ImprimeArvoreGeradoraMinima(int ArvoreMinima[][COL_GRAFO], int numVertices)
{
	int i;
	for (i=0; i<numVertices - 1; i++)
	{
		printf("%d %d %d", ArvoreMinima[i][0], ArvoreMinima[i][1], ArvoreMinima[i][2]);
		if (i < numVertices - 2) printf("\n");
		//peso = peso + ArvoreMinima[i][2]; //tamanho do caminho percorrido
	}
	printf("\n\n");
}
