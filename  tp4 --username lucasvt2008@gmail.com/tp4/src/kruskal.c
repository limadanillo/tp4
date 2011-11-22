#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "kruskal.h"
#include "grafo.h"
#include "pilha.h"

int Raiz(int vertice, int pesoAresta[])
{
	while(pesoAresta[vertice] != vertice)
    {
    	vertice = pesoAresta[vertice];
    }
    return vertice;
}

void Reoderna(int i, int j, int pesoAresta[])
{
	if(j > i) pesoAresta[j] = i;
    else pesoAresta[i] = j;
}

void Kruskal(int **matriz, int numVertices, int numArestas, int teste)
{
	//localidade e referencia
	Pilha *pilha = PilhaNova(numVertices);
	int distancia[numVertices];
	int quantidadeAcesso[numVertices];
	IniciaVetorComZero(distancia, numVertices);
	IniciaVetorComZero(quantidadeAcesso, numVertices);
	int tamanhoPilha = 0;


    int count, i, min, j, u, v, k;
    int arvoreMinima[numVertices][numVertices];
    int pesoAresta[numVertices];
    int matrizPesoAux[numVertices][numVertices];
    count = k = 0;
    for(i = 0; i < numVertices; i++)
    {
        pesoAresta[i] = i;
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
        PilhaEmpilha(pilha, &tamanhoPilha, min, distancia, quantidadeAcesso);
        if(min != INT_MAX)
        {
            i = Raiz(u, pesoAresta);
            j = Raiz(v, pesoAresta);
            if (i != j)
            {
                arvoreMinima[k][0] = u;
                arvoreMinima[k][1] = v;

                k++;

                Reoderna(i,j,pesoAresta);
            }
        matrizPesoAux[u][v] = matrizPesoAux[v][u] = matriz[u][v];
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
            printf("%d %d %d\n", arvoreMinima[k][0], arvoreMinima[k][1], matrizPesoAux[arvoreMinima[k][0]][arvoreMinima[k][1]]);
        }
    printf("\n");
    }
    GeraDistribuicaoEspacial("DistriEspaKruskal", teste, distancia, quantidadeAcesso, numVertices);
}

