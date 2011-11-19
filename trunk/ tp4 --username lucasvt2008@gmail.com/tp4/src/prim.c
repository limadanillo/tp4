#include <stdlib.h>
#include <stdio.h>
#include "grafo.h"
#include "prim.h"


/*-- Operadores para obter a lista de adjacentes --*/
int ListaAdjacenciaVazia(int *vertice, int **matriz, int numVertice)
{
	int Aux = 0;
	short ListaVazia = VERDADEIRO;
	while (Aux < numVertice && ListaVazia)
    {
		if (matriz[*vertice][Aux] > 0) ListaVazia = FALSO;
		else Aux++;
    }
  return (ListaVazia == VERDADEIRO);
}

int PrimeiroListaAdjacente(int *vertice, int **matriz, int numVertice)
{
	int result;
	int aux = 0;
	short Listavazia = VERDADEIRO;
	while (aux < numVertice && Listavazia)
    {
		if (matriz[*vertice][aux] > 0)
		{
			result = aux;
        	Listavazia = FALSO;
		}
		else aux++;
    }
	if (aux == numVertice)	printf("Erro: Lista adjacencia vazia\n");
	return result;
}


void ProxAdjacente(int *vertice, int **matriz, int numVertice, int *adjacente, int *peso, int *proximoAdjacente, int *FimListaAdj)
{
	/* --Retorna Adj apontado por Prox--*/
	*adjacente = *proximoAdjacente;
	*peso = matriz[*vertice][*proximoAdjacente];
	(*proximoAdjacente)++;
	while (*proximoAdjacente < numVertice && matriz[*vertice][*proximoAdjacente] == 0) (*proximoAdjacente)++;
	if (*proximoAdjacente == numVertice) *FimListaAdj = VERDADEIRO;
}


/* Local variables for AgmPrim: */

void RefazIndice(int esquerda, int direita, int heap[], int pesoAresta[], int *posicaoVerticeHeap)
{
	int i = esquerda;
	int j = i * 2;
	int x;
	x = heap[i];
	while (j <= direita)
	{
		if (j < direita)
		{
			if (pesoAresta[heap[j]] > pesoAresta[heap[j+1]]) j++;
		}
		if (pesoAresta[x] <= pesoAresta[heap[j]]) break;
		heap[i] = heap[j];
		posicaoVerticeHeap[heap[j]] = i;
		i = j;
		j = i * 2;
	}
	heap[i] = x;
	posicaoVerticeHeap[x] = i;
}

void Constroi(int heap[], int pesoAresta[], int posicaoVerticeHeap[], int *tamanhoDoHeap)
{
	int Esq;
	Esq = (*tamanhoDoHeap) / (2+1);
	while (Esq > 1)
	{
		Esq--;
		RefazIndice(Esq, *tamanhoDoHeap, heap, pesoAresta, posicaoVerticeHeap);
	}
}

int RetiraIndiceMinimo(int heap[], int pesoAresta[], int posicaoVerticeHeap[], int *tamanhoDoHeap)
{
	int resultado = 0;
	if (*tamanhoDoHeap < 1)
	{
		printf("Erro: heap vazio\n");
		return resultado;
	}
	resultado = heap[1];
	heap[1] = heap[*tamanhoDoHeap];
	posicaoVerticeHeap[heap[*tamanhoDoHeap]] = 1;
	(*tamanhoDoHeap) = (*tamanhoDoHeap) - 1 ;
	RefazIndice(1, *tamanhoDoHeap, heap, pesoAresta, posicaoVerticeHeap );
	return resultado;
}

void DiminuiChaveIndice(int indice, int chaveNova, int heap[], int pesoAresta[], int posicaoVerticeHeap[])
{
	int x;
	if (chaveNova > pesoAresta[heap[indice]])
	{
		printf("Erro: ChaveNova maior que a chave atual\n");
		return;
	}
	pesoAresta[heap[indice]] = chaveNova;
	while (indice > 1 && pesoAresta[heap[indice / 2]] > pesoAresta[heap[indice]])
    {
		x = heap[indice / 2];
		heap[indice / 2] = heap[indice];
		posicaoVerticeHeap[heap[indice]] = indice / 2;
		heap[indice] = x;
		posicaoVerticeHeap[x] = indice;
		indice /= 2;
    }
}

void Prim(int **matriz, int numVertice, int numAresta)
{
	int verticeAntecessor[numVertice + 1];
	short arrayBooleano[numVertice + 1]; //Simula um vetor de booleanos com 0=falso e 1=verdadeiro
	int heap[numVertice];
	int tamanhoDoHeap;
	int proximoVertice;
	int finalListaAdj;
	int peso;
	int verticeInicial = 0;
	int pesoAresta[numVertice + 1];
	int posicaoVerticeHeap[numVertice + 1];
	int u, v; //Vértices que compõe uma aresta qualquer
	int guarda;

	for (u = 0; u <= numVertice; u++)
	{
		/*Constroi o heap com todos os valores igual a INFINITO*/
		verticeAntecessor[u] = -1;
		pesoAresta[u] = MaiorPesoDeAresta(matriz, numVertice) +1;
		heap[u+1] = u;   /*Heap a ser construido*/
		arrayBooleano[u] = VERDADEIRO;
		posicaoVerticeHeap[u] = u + 1;
	}
	tamanhoDoHeap = numVertice;
	pesoAresta[verticeInicial] = 0;
	Constroi(heap, pesoAresta, posicaoVerticeHeap, &tamanhoDoHeap);
	while (tamanhoDoHeap >= 1)  /*enquanto heap nao vazio*/
	{
		guarda = RetiraIndiceMinimo(heap, pesoAresta, posicaoVerticeHeap, &tamanhoDoHeap);
		u = guarda;
		arrayBooleano[u] = FALSO;
		if (u != verticeInicial)
		{
			printf("%d %d %d\n", verticeAntecessor[u], u, matriz[verticeAntecessor[u]][u]);
		}

		if (!ListaAdjacenciaVazia(&u, matriz, numVertice))
		{
			proximoVertice = PrimeiroListaAdjacente(&u, matriz, numVertice);
			finalListaAdj = FALSO;
			while (!finalListaAdj)
			{
				ProxAdjacente(&u, matriz, numVertice, &v, &peso, &proximoVertice, &finalListaAdj);
				if (arrayBooleano[v] && peso < pesoAresta[v])
				{
					verticeAntecessor[v] = u;
					DiminuiChaveIndice(posicaoVerticeHeap[v], peso, heap, pesoAresta, posicaoVerticeHeap);
				}
			}
		}
	}
	printf("\n");
}
