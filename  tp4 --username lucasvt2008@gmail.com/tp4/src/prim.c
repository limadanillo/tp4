#include <stdlib.h>
#include <stdio.h>
#include "grafo.h"
#include "prim.h"


/*-- Operadores para obter a lista de adjacentes --*/
int ListaAdjVazia(int *Vertice, int **matriz, int numVertice)
{
	int Aux = 0;
	short ListaVazia = VERDADEIRO;
	while (Aux < numVertice && ListaVazia)
    {
		if (matriz[*Vertice][Aux] > 0) ListaVazia = FALSO;
		else Aux++;
    }
  return (ListaVazia == VERDADEIRO);
}

int PrimeiroListaAdj(int *Vertice, int **matriz, int numVertice)
{
	int Result;
	int Aux = 0;
	short Listavazia = VERDADEIRO;
	while (Aux < numVertice && Listavazia)
    {
		if (matriz[*Vertice][Aux] > 0)
		{ 	Result = Aux;
        	Listavazia = FALSO;
		}
		else Aux++;
    }
	if (Aux == numVertice)	printf("Erro: Lista adjacencia vazia (PrimeiroListaAdj)\n");
	return Result;
}


void ProxAdj(int *Vertice, int **matriz, int numVertice, int *Adj, int *Peso, int *Prox, int *FimListaAdj)
{
	/* --Retorna Adj apontado por Prox--*/
	*Adj = *Prox;
	*Peso = matriz[*Vertice][*Prox];
	(*Prox)++;
	while (*Prox < numVertice && matriz[*Vertice][*Prox] == 0) (*Prox)++;
	if (*Prox == numVertice) *FimListaAdj = VERDADEIRO;
}


/* Local variables for AgmPrim: */

void RefazInd(int Esq, int Dir, int *heap, int pesoAresta[], int *posicaoVerticeHeap)
{
	int i = Esq;
	int j = i * 2;
	int x;
	x = heap[i];
	while (j <= Dir)
	{
		if (j < Dir)
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

void Constroi(int *heap, int pesoAresta[], int *posicaoVerticeHeap, int *tamanhoDoHeap)
{
	int Esq;
	Esq = (*tamanhoDoHeap) / (2+1);
	while (Esq > 1)
	{
		Esq--;
		RefazInd(Esq, *tamanhoDoHeap, heap, pesoAresta, posicaoVerticeHeap);
	}
}

int RetiraMinInd(int heap[], int pesoAresta[], int *posicaoVerticeHeap, int *tamanhoDoHeap)
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
	RefazInd(1, *tamanhoDoHeap, heap, pesoAresta, posicaoVerticeHeap );
	return resultado;
}

void DiminuiChaveInd(int i, int chaveNova, int heap[], int pesoAresta[], int *posicaoVerticeHeap)
{
	int x;
	if (chaveNova > pesoAresta[heap[i]])
	{
		printf("Erro: ChaveNova maior que a chave atual\n");
		return;
	}
	pesoAresta[heap[i]] = chaveNova;
	while (i > 1 && pesoAresta[heap[i / 2]] > pesoAresta[heap[i]])
    {
		x = heap[i / 2];
		heap[i / 2] = heap[i];
		posicaoVerticeHeap[heap[i]] = i / 2;
		heap[i] = x;
		posicaoVerticeHeap[x] = i;
		i /= 2;
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
		guarda = RetiraMinInd(heap, pesoAresta, posicaoVerticeHeap, &tamanhoDoHeap);
		u = guarda;
		arrayBooleano[u] = FALSO;
		if (u != verticeInicial)
		{
			printf("%d %d %d\n", verticeAntecessor[u], u, matriz[verticeAntecessor[u]][u]);
		}

		if (!ListaAdjVazia(&u, matriz, numVertice)) //
		{
			proximoVertice = PrimeiroListaAdj(&u, matriz, numVertice); //
			finalListaAdj = FALSO;
			while (!finalListaAdj)
			{
				ProxAdj(&u, matriz, numVertice, &v, &peso, &proximoVertice, &finalListaAdj); //
				if (arrayBooleano[v] && peso < pesoAresta[v])
				{
					verticeAntecessor[v] = u;
					DiminuiChaveInd(posicaoVerticeHeap[v], peso, heap, pesoAresta, posicaoVerticeHeap);
				}
			}
		}
	}
	printf("\n");
}
