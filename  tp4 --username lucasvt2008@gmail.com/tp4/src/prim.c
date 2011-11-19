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

void RefazInd(int Esq, int Dir, int *A, int P[], int *Pos)
{
	int i = Esq;
	int j = i * 2;
	int x;
	x = A[i];
	while (j <= Dir)
	{
		if (j < Dir)
		{
			if (P[A[j]] > P[A[j+1]]) j++;
		}
		if (P[x] <= P[A[j]]) break;
		A[i] = A[j];
		Pos[A[j]] = i;
		i = j;
		j = i * 2;
	}
	A[i] = x;
	Pos[x] = i;
}

void Constroi(int *A, int P[], int *Pos, int *tamanhoDoHeap)
{
	int Esq;
	Esq = (*tamanhoDoHeap) / (2+1);
	while (Esq > 1)
	{
		Esq--;
		RefazInd(Esq, *tamanhoDoHeap, A, P, Pos);
	}
}

int RetiraMinInd(int A[], int P[], int *Pos, int *tamanhoDoHeap)
{
	int Result = 0;
	if (*tamanhoDoHeap < 1)
	{
		printf("Erro: heap vazio\n");
		return Result;
	}
	Result = A[1];
	A[1] = A[*tamanhoDoHeap];
	Pos[A[*tamanhoDoHeap]] = 1;
	(*tamanhoDoHeap) = (*tamanhoDoHeap) - 1 ;
	RefazInd(1, *tamanhoDoHeap, A, P, Pos );
	return Result;
}

void DiminuiChaveInd(int i, int ChaveNova, int A[], int P[], int *Pos)
{
	int x;
	if (ChaveNova > P[A[i]])
	{
		printf("Erro: ChaveNova maior que a chave atual\n");
		return;
	}
	P[A[i]] = ChaveNova;
	while (i > 1 && P[A[i / 2]] > P[A[i]])
    {
		x = A[i / 2];
		A[i / 2] = A[i];
		Pos[A[i]] = i / 2;
		A[i] = x;
		Pos[x] = i;
		i /= 2;
    }
}

void Prim(int **matriz, int numVertice, int numAresta)
{
	int tamanho = MaiorPesoDeAresta(matriz, numVertice);
	int Antecessor[numVertice + 1];
	short Itensheap[numVertice + 1];
	int A[numVertice];
	int tamanhoDoHeap;
	int Aux;
	int FimListaAdj;
	int Peso;
	int verticeInicial = 0;
	int P[numVertice + 1];
	int Pos[numVertice + 1];
	int u, v;
	int TEMP;

	for (u = 0; u <= numVertice; u++)
	{
		/*Constroi o heap com todos os valores igual a INFINITO*/
		Antecessor[u] = -1;
		P[u] = tamanho+1;
		A[u+1] = u;   /*Heap a ser construido*/
		Itensheap[u] = VERDADEIRO;
		Pos[u] = u + 1;
	}
	tamanhoDoHeap = numVertice;
	P[verticeInicial] = 0;
	Constroi(A, P, Pos, &tamanhoDoHeap);
	while (tamanhoDoHeap >= 1)  /*enquanto heap nao vazio*/
	{
		TEMP = RetiraMinInd(A, P, Pos, &tamanhoDoHeap);
		u = TEMP;
		Itensheap[u] = FALSO;
		if (u != verticeInicial)
		{
			printf("%d %d %d\n", Antecessor[u], u, matriz[Antecessor[u]][u]);
		}

		if (!ListaAdjVazia(&u, matriz, numVertice)) //
		{
			Aux = PrimeiroListaAdj(&u, matriz, numVertice); //
			FimListaAdj = FALSO;
			while (!FimListaAdj)
			{
				ProxAdj(&u, matriz, numVertice, &v, &Peso, &Aux, &FimListaAdj); //
				if (Itensheap[v] && Peso < P[v])
				{
					Antecessor[v] = u;
					DiminuiChaveInd(Pos[v], Peso, A, P, Pos);
				}
			}
		}
	}
	printf("\n");
}
