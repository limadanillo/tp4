#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "kruskal.h"
#include "grafo.h"
#include "pilha.h"

int root(int v,int p[])
{
	while(p[v] != v)
    {
    	v = p[v];
    }

    return v;
}

void union_ij(int i,int j,int p[])
{
	if(j > i) p[j] = i;
    else p[i] = j;
}

void Kruskal(int **matriz, int numVertices, int numArestas, int teste)
{
    int count, i, p[numVertices], min, j, u, v, k, arvoreMinima[numVertices][numVertices];
    int W[100][100];
    count = k = 0;
    for(i = 0; i < numVertices; i++)
    {
        p[i] = i;
    }
    while(count < numVertices)
    {
        min = INT_MAX;
        for(i = 0; i < numVertices; i++)
        {
            for(j = i+1;j < numVertices; j++)
            {

                if(matriz[i][j] < min)
                {
                    min = matriz[i][j];
                    u = i;
                    v = j;

                }
            }
        }
        if(min != INT_MAX)
        {
            i = root(u, p);
            j = root(v, p);
            if (i != j)
            {
                arvoreMinima[k][0] = u;
                arvoreMinima[k][1] = v;

                k++;

                union_ij(i,j,p);
            }
        W[u][v] = W[v][u] = matriz[u][v];
        matriz[u][v] = matriz[v][u] = INT_MAX;

        }
        count +=1;
    }

    if(count != numVertices)
    {
        printf("spanning tree not exist\n");
    }

    if(count == numVertices)
    {
        for(k = 0; k < numVertices-1 ; k++)
        {
            printf("%d %d %d\n", arvoreMinima[k][0], arvoreMinima[k][1], W[arvoreMinima[k][0]][arvoreMinima[k][1]]);
        }
    printf("\n");
    }
}










///*
//Este programa é uma implementação do algoritmo de Kruskal para
//determinar uma árvore geradora mínima para um grafo conectado, não direcionado e
//grafo ponderado. Esta aplicação é projetada especificamente
//para os dados de teste requeridos pelo projeto.
//*/
//
//void Kruskal(int **matriz, int numVertices, int numArestas, int teste)
//{
//	//localidade e referencia
//	Pilha *pilha = PilhaNova(numVertices);
//	int distancia[numVertices];
//	int quantidadeAcesso[numVertices];
//	IniciaVetorComZero(distancia, numVertices);
//	IniciaVetorComZero(quantidadeAcesso, numVertices);
//	int tamanhoPilha = 0;
//
//
//	int U[numVertices];
//	int ConjuntoArestas[numArestas][3]; // Conjunto de arestas
//	int ArvoreMinima[numVertices-1][3];  // Conjunto de arestas da árvore geradora mínima
//	int aux_NumArestas = 0; // Búmero de arestas da árvore geradora mínima
//	int proximo_vetice = 0; // Próxim aresta ainda não considerado
//	//int peso = 0; // Caminho total árvore geradora mínima
//	int a, b, c, i, j, k; // Variáveis contadoras
//
//	/* Inicializa conjunto de arestas */
//	k = 0;
//	for (i = 0; i < numVertices; i++)
//	{
//		for (j = 0; j < numVertices; j++)
//		{
//			if (j > i)
//			{
//				ConjuntoArestas[k][0] = i;          /* first vertex of edge */
//				ConjuntoArestas[k][1] = j;          /* second vertex of edge */
//				ConjuntoArestas[k][2] = matriz[i][j];    /* peso of edge */
//				k++;
//			}
//		}
//	}
//
//	for (i=numArestas - 1; i > 0; i--)
//	{
//		for (j = 0; j < i; j++)
//		{
//			if (ConjuntoArestas[j][2] > ConjuntoArestas[j+1][2])
//			{
//				a = ConjuntoArestas[j][0];
//				b = ConjuntoArestas[j][1];
//				c = ConjuntoArestas[j][2];
//				ConjuntoArestas[j][0] = ConjuntoArestas[j+1][0];
//				ConjuntoArestas[j][1] = ConjuntoArestas[j+1][1];
//				ConjuntoArestas[j][2] = ConjuntoArestas[j+1][2];
//				ConjuntoArestas[j+1][0] = a;
//				ConjuntoArestas[j+1][1] = b;
//				ConjuntoArestas[j+1][2] = c;
//			}
//		}
//	}
//
//
//	/* create n disjoint subsets */
//   CriaSubConjunto(U, numVertices);
//
//   /* initialize set of edges in min. span. tree to empty */
//   for (i = 0; i < numVertices - 1; i++)
//   {
//	   for (j = 0; j < 3; j++)
//	   {
//		   ArvoreMinima[i][j] = -1;            /* '-1' == Vazio */
//	   }
//   }
//
//   /* find minimal spanning tree */
//   while (aux_NumArestas < numVertices - 1)
//   {
//	   a = ConjuntoArestas[proximo_vetice][0];
//	   b = ConjuntoArestas[proximo_vetice][1];
//	   PilhaEmpilha(pilha, &tamanhoPilha, a, distancia, quantidadeAcesso);
//	   PilhaEmpilha(pilha, &tamanhoPilha, b, distancia, quantidadeAcesso);
//
//	   i = ProcuraPosicaoVertice(U, a);
//	   j = ProcuraPosicaoVertice(U, b);
//
//	   if (!Igual(i, j))
//	   {
//		   Reordena(U, i, j);
//		   ArvoreMinima[aux_NumArestas][0] = ConjuntoArestas[proximo_vetice][0];
//		   ArvoreMinima[aux_NumArestas][1] = ConjuntoArestas[proximo_vetice][1];
//		   ArvoreMinima[aux_NumArestas][2] = ConjuntoArestas[proximo_vetice][2];
//		   aux_NumArestas++;
//	   }
//	   proximo_vetice++;
//	}
//   	ImprimeArvoreGeradoraMinima(ArvoreMinima, numVertices);
//   	GeraDistribuicaoEspacial("DistriEspaKruskal", teste, distancia, quantidadeAcesso, numVertices);
//
//}
//
//int ProcuraPosicaoVertice(int U[], int i)
//{
//	int j = i;
//	while (U[j] != j) j = U[j];
//	return j;
//}
//
//void Reordena(int U[], int p, int q)
//{
//	if (p < q) U[q] = p;
//	else U[p] = q;
//}
//
//int Igual(int p, int q)
//{
//	if (p == q) return 1;
//	else return 0;
//}
//
//void CriaSubConjunto(int U[], int n)
//{
//	int i;
//	for (i = 0; i < n; i++) U[i] = i;
//}
//
//void ImprimeArvoreGeradoraMinima(int ArvoreMinima[][COL_GRAFO], int numVertices)
//{
//	int i;
//	for (i=0; i<numVertices - 1; i++)
//	{
//		printf("%d %d %d", ArvoreMinima[i][0], ArvoreMinima[i][1], ArvoreMinima[i][2]);
//		if (i < numVertices - 2) printf("\n");
//		//peso = peso + ArvoreMinima[i][2]; //tamanho do caminho percorrido
//	}
//	printf("\n\n");
//}
