#include <stdio.h>
#include <stdlib.h>
#include "kruskal.h"

/*
Este programa é uma implementação do algoritmo de Kruskal para
determinar uma árvore geradora mínima para um ligado, não-dirigida,
grafo ponderado. Esta aplicação é projetado especificamente
para os dados de teste requeridos pelo projeto. A melhor solução
seria a de implementar o algoritmo para gerar espaço para qualquer
problema de forma dinâmica.
*/


/* function definitions */
void Kruskal(int **matriz, int numVertices, int numArestas)
{
	int U[numVertices];
	int E[numArestas][3];                   /* complete set of edges */
	int F[numVertices-1][3];                 /* set of edges in min. span. tree */
	int aux_NumVertices = 0;             /* num of edges in min. span. tree */
	int proximo_vetice = 0;             /* next edge not yet considered */
	int weight = 0;                /* minimal spanning tree weight */
	int a, b, c, i, j, k;          /* counter/placeholder variables */

	/* Inicializa conjunto de vértices */
	k = 0;
	for (i = 0; i < numVertices; i++)
	{
		for (j = 0; j < numVertices; j++)
		{
			if (j > i)
			{
				E[k][0] = i;          /* first vertex of edge */
				E[k][1] = j;          /* second vertex of edge */
				E[k][2] = matriz[i][j];    /* weight of edge */
				k++;
			}
		}
	}

	for (i=numArestas - 1; i > 0; i--)
	{
		for (j = 0; j < i; j++)
		{
			if (E[j][2] > E[j+1][2])
			{
				a = E[j][0];
				b = E[j][1];
				c = E[j][2];
				E[j][0] = E[j+1][0];
				E[j][1] = E[j+1][1];
				E[j][2] = E[j+1][2];
				E[j+1][0] = a;
				E[j+1][1] = b;
				E[j+1][2] = c;
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
		   F[i][j] = -1;            /* '-1' == Vazio */
	   }
   }

   /* find minimal spanning tree */
   while (aux_NumVertices < numVertices - 1)
   {
	   a = E[proximo_vetice][0];
	   b = E[proximo_vetice][1];

	   i = ProcuraPosicaoVertice(U, a);
	   j = ProcuraPosicaoVertice(U, b);

	   if (!Igual(i, j))
	   {
		   Reordena(U, i, j);
		   F[aux_NumVertices][0] = E[proximo_vetice][0];
		   F[aux_NumVertices][1] = E[proximo_vetice][1];
		   F[aux_NumVertices][2] = E[proximo_vetice][2];
		   aux_NumVertices++;
	   }
	   proximo_vetice++;
	}

/*
 * Imprime a árvore geradora mínima
 */
for (i=0; i<numVertices - 1; i++)
	{
		printf("%d %d %d", F[i][0], F[i][1], F[i][2]);
		if (i < numVertices - 2) printf("\n");
		weight = weight + F[i][2];
	}
	printf("\n\n");

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
