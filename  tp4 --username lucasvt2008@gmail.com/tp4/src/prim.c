/*-- 24/mai/2003 --*/
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include "prim.h"
void FGVazio(TipoGrafo *Grafo)
{
	int  i, j;
	for (i = 0; i <= Grafo->NumVertices; i++)
    {
		for (j = 0; j <= Grafo->NumVertices; j++)
			Grafo->Mat[i][j] = 0;
    }
}

//void InsereAresta(TipoValorVertice *V1, TipoValorVertice *V2, TipoPeso *Peso, TipoGrafo *Grafo)
//{
//	Grafo->Mat[*V1][*V2] = *Peso;
//}

short  ExisteAresta(TipoValorVertice Vertice1, TipoValorVertice Vertice2, TipoGrafo *Grafo)
{
	return (Grafo->Mat[Vertice1][Vertice2] > 0);
}


/*-- Operadores para obter a lista de adjacentes --*/
short  ListaAdjVazia(TipoValorVertice *Vertice, int **matriz, int numVertice, TipoGrafo *Grafo)
{
	TipoApontador Aux = 0;
	short ListaVazia = TRUE;
	while (Aux < numVertice && ListaVazia)
    {
		if (matriz[*Vertice][Aux] > 0) ListaVazia = FALSE;
		else Aux++;
    }
  return (ListaVazia == TRUE);
}

TipoApontador PrimeiroListaAdj(TipoValorVertice *Vertice, int **matriz, int numVertice, TipoGrafo *Grafo)
{
	TipoValorVertice Result;
	TipoApontador Aux = 0;
	short Listavazia = TRUE;
	while (Aux < numVertice && Listavazia)
    {
		if (matriz[*Vertice][Aux] > 0)
		{ 	Result = Aux;
        	Listavazia = FALSE;
		}
		else Aux++;
    }
	if (Aux == numVertice)	printf("Erro: Lista adjacencia vazia (PrimeiroListaAdj)\n");
	return Result;
}


void ProxAdj(TipoValorVertice *Vertice, int **matriz, int numVertice, TipoGrafo *Grafo, TipoValorVertice *Adj, TipoPeso *Peso, TipoApontador *Prox, short *FimListaAdj)
{
	/* --Retorna Adj apontado por Prox--*/
	*Adj = *Prox;
	*Peso = matriz[*Vertice][*Prox];
	(*Prox)++;
	while (*Prox < numVertice && matriz[*Vertice][*Prox] == 0) (*Prox)++;
	if (*Prox == numVertice) *FimListaAdj = TRUE;
}

void ImprimeGrafo(TipoGrafo *Grafo, int **matriz, int numVertice)
{
//	int i, j;
//
//	printf("   ");
//
//	for (i = 0; i < Grafo->NumVertices; i++) printf(" %3d", i);
//  putchar('\n');
//  for (i = 0; i < Grafo->NumVertices; i++)
//    { printf("%3d", i);
//      for (j = 0; j < Grafo->NumVertices; j++)
//        printf("%4d", Grafo->Mat[i][j]);
//      putchar('\n');
//    }
}

/* Local variables for AgmPrim: */

void RefazInd(TipoIndice Esq, TipoIndice Dir, TipoItem *A, TipoPeso *P, TipoValorVertice *Pos)
{
	TipoIndice i = Esq;
  int j = i * 2;
  TipoItem x;
  x = A[i];
  while (j <= Dir)
  { if (j < Dir)
    { if (P[A[j].Chave] > P[A[j+1].Chave]) j++; }
    if (P[x.Chave] <= P[A[j].Chave]) goto L999;
    A[i] = A[j]; Pos[A[j].Chave] = i;
    i = j; j = i * 2;
  }
  L999: A[i] = x;
  Pos[x.Chave] = i;
}

void Constroi(TipoItem *A, TipoPeso *P, TipoValorVertice *Pos)
{ TipoIndice Esq;
  Esq = n / 2 + 1;
  while (Esq > 1) { Esq--; RefazInd(Esq, n, A, P, Pos); }
}

TipoItem RetiraMinInd(TipoItem *A, TipoPeso *P, TipoValorVertice *Pos)
{ TipoItem Result;
  if (n < 1) { printf("Erro: heap vazio\n"); return Result; }
  Result = A[1]; A[1] = A[n];
  Pos[A[n].Chave] = 1; n--;
  RefazInd(1, n, A, P, Pos );
  return Result;
}

void DiminuiChaveInd(TipoIndice i, TipoPeso ChaveNova, TipoItem *A,
                     TipoPeso *P, TipoValorVertice *Pos)
{ TipoItem x;
  if (ChaveNova > P[A[i].Chave])
  { printf("Erro: ChaveNova maior que a chave atual\n");
    return;
  }
  P[A[i].Chave] = ChaveNova;
  while (i > 1 && P[A[i / 2].Chave] > P[A[i].Chave])
    { x = A[i / 2]; A[i / 2] = A[i];
      Pos[A[i].Chave] = i / 2; A[i] = x;
      Pos[x.Chave] = i; i /= 2;
    }
}

void Prim(int **matriz, int numVertice, int numAresta, int *Raiz)
{
	int Antecessor[MAXNUMVERTICES + 1];
	short Itensheap[MAXNUMVERTICES + 1];
	Vetor A;
	TipoPeso P[MAXNUMVERTICES + 1];
	TipoValorVertice Pos[MAXNUMVERTICES + 1];
	TipoValorVertice u, v;
	TipoItem TEMP;
	TipoGrafo Grafo;
	for (u = 0; u <= numVertice; u++)
	{
		/*Constroi o heap com todos os valores igual a INFINITO*/
		Antecessor[u] = -1;
		P[u] = INFINITO;
		A[u+1].Chave = u;   /*Heap a ser construido*/
		Itensheap[u] = TRUE;
		Pos[u] = u + 1;
	}
	n = numVertice;
	P[*Raiz] = 0;
	Constroi(A, P, Pos);
	while (n >= 1)  /*enquanto heap nao vazio*/
	{
		TEMP = RetiraMinInd(A, P, Pos);
		u = TEMP.Chave; Itensheap[u] = FALSE;
		if (u != *Raiz)
		{
			printf("%d %d %d\n", Antecessor[u], u, matriz[Antecessor[u]][u]);
		}

		if (!ListaAdjVazia(&u, matriz, numVertice, &Grafo)) //
		{
			Aux = PrimeiroListaAdj(&u, matriz, numVertice, &Grafo); //
			FimListaAdj = FALSE;
			while (!FimListaAdj)
			{
				ProxAdj(&u, matriz, numVertice, &Grafo, &v, &Peso, &Aux, &FimListaAdj); //
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
