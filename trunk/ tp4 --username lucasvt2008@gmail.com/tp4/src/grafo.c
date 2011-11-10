#include <stdio.h>
#include <stdlib.h>
#include "grafo.h"

void InicializaGrafo(ListaGrafo *lista)
{
	lista->primeiro = (Apontador)malloc(sizeof(Grafo));
	lista->ultimo = lista->primeiro;
	lista->primeiro->matrizAdjacencia = NULL;
	lista->primeiro->numArestas = 0;
	lista->primeiro->numVertices = 0;
	lista->primeiro->proximo = NULL;

}

void LeEntrada(ListaGrafo *lista)
{
	int numArestas, numVertices;

	/*
	 * origem = Vértice de origem
	 * destino = Vértice de destino
	 * peso = peso da aresta do vértice de origem ao vértice de destino
	 */
	int origem, destino, peso;
	scanf("%d %d", &numVertices, &numArestas);

	if(numVertices <= 0 && numArestas <= 0)
	{
		printf("Erro ao inserir quantidade de vértices e arestas");
	}
	else
	{
		InsereGrafo(lista, numArestas, numVertices);
		while(numArestas != 0)
		{
			scanf("%d %d %d", &origem, &destino, &peso);
			InsereAresta(lista->ultimo->matrizAdjacencia, origem, destino, peso);
			numArestas--;
			if(numArestas == 0)
			{
				scanf("%d %d", &numVertices, &numArestas);
				if(numArestas == 0)
				{
					break;
				}
				InsereGrafo(lista, numArestas, numVertices);
			}
		}
	}
}

int **CriaMatrizDeAdjacencia(int tamanho)
{
	int **matriz;
	int i, j;
	matriz = (int **)malloc(tamanho * sizeof(int *)); //Aloca as linhas da matriz

	for(i=0; i<tamanho; i++)
	{
		matriz[i] = (int *)malloc(tamanho * sizeof(int)); //Aloca as colunas da matriz
	}

	for(i=0; i<tamanho; i++)
	{
		for(j=0; j<tamanho; j++)
		{
			matriz[i][j] = 0;
		}
	}

	return matriz;
}

void InsereGrafo(ListaGrafo *lista, int numArestas, int numVertices)
{
	Apontador aux = lista->ultimo;
	aux->proximo = (Apontador)malloc(sizeof(Grafo));
	aux = aux->proximo;
	aux->numArestas = numArestas;
	aux->numVertices = numVertices;
	aux->matrizAdjacencia = CriaMatrizDeAdjacencia(numVertices);
	aux->proximo = NULL;
	lista->ultimo = aux;
}

void InsereAresta(int **matriz, int origem, int destino, int peso)
{
	/*
	 * Grafo não direcionado. Devemos alocar a aresta A para os vértices (u,v) e para
	 * os vértices (v,u)
	 */
	matriz[origem][destino] = peso;
	matriz[destino][origem] = peso;
}


void LiberaGrafo(ListaGrafo *lista)
{
	Apontador aux, apaga;
	aux = lista->primeiro;

	while(aux != NULL)
	{
		apaga = aux;
		aux = aux->proximo;
		free(apaga);
	}
}

void ImprimirEntradas(ListaGrafo *lista)
{
	Apontador aux = lista->primeiro->proximo;

	while(aux != NULL)
	{
		printf("%d %d\n", aux->numVertices, aux->numArestas);
		ImprimirMatriz(aux->matrizAdjacencia, aux->numVertices);
		aux = aux->proximo;
	}
}

void ImprimirMatriz(int **matriz, int tamanho)
{
	int i, j;
	for(i=0; i<tamanho; i++)
	{
		for(j=0; j<tamanho; j++)
		{
			printf("%d ", matriz[i][j]);
		}
		printf("\n");
	}
}

