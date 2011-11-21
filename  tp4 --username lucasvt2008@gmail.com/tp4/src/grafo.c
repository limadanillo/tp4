#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "grafo.h"
#include "kruskal.h"
#include "prim.h"

void InicializaGrafo(ListaGrafo *lista)
{
	lista->primeiro = (Apontador)malloc(sizeof(Grafo));
	lista->ultimo = lista->primeiro;
	lista->primeiro->matrizAdjacencia = NULL;
	lista->primeiro->numArestas = 0;
	lista->primeiro->numVertices = 0;
	lista->primeiro->proximo = NULL;

}

void LeEntrada(ListaGrafo *lista, int algoritmo)
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
		InsereGrafo(lista, numArestas, numVertices, algoritmo);
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
				InsereGrafo(lista, numArestas, numVertices, algoritmo);
			}
		}
	}
}

int **CriaMatrizDeAdjacencia(int tamanho, int algoritmo)
{
	int **matriz;
	int i, j;
	matriz = (int **)malloc(tamanho * sizeof(int *)); //Aloca as linhas da matriz

	/*
	 * Tratamento de erro. Verifica se as linhas da matriz são alocadas corretamente e/ou
	 * existe memória suficiente
	 */
	if(matriz == NULL)
	{
		printf("Matriz (linha) nao alocada. Verifique memoria\n");
		exit(1);
	}

	for(i=0; i<tamanho; i++)
	{
		matriz[i] = (int *)malloc(tamanho * sizeof(int)); //Aloca as colunas da matriz
		/*
		 * Tratamento de erro. Verifica se as colunas da matriz são alocadas corretamente e/ou
		 * existe memória suficiente
		 */
		if(matriz[i] == NULL)
		{
			printf("Matriz (coluna) nao alocada. Verifique memoria\n");
			exit(1);
		}

	}

	for(i=0; i<tamanho; i++)
	{
		for(j=0; j<tamanho; j++)
		{
			if(algoritmo == 1) matriz[i][j] = 0;
			else if (algoritmo == 2) matriz[i][j] = INT_MAX;
		}
	}

	return matriz;
}

void InsereGrafo(ListaGrafo *lista, int numArestas, int numVertices, int algoritmo)
{
	Apontador aux = lista->ultimo;
	aux->proximo = (Apontador)malloc(sizeof(Grafo));
	aux = aux->proximo;
	aux->numArestas = numArestas;
	aux->numVertices = numVertices;
	aux->matrizAdjacencia = CriaMatrizDeAdjacencia(numVertices, algoritmo);
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

int MaiorPesoDeAresta(int **matriz, int numVertice)
{
	int tamanho = 0; //Inicializando com um valor sem peso
	int i, j;

	/*
	 * Matriz de adjacência sempre será quadrada, e seu lado terá o tamanho de
	 * (unidades) do número de vértices.
	 */
	for(i=0; i<numVertice; i++)
	{
		for(j=0; j<numVertice; j++)
		{
			if(tamanho < matriz[i][j]) tamanho = matriz[i][j];
		}
	}

	return tamanho;
}

void GeraSaidaPadrao(ListaGrafo *lista, int algoritmo)
{
	Apontador aux = lista->primeiro->proximo;
	int cont = 1;

	while(aux != NULL)
	{
		printf("Teste %d\n", cont);
		if(algoritmo == 1) Prim(aux->matrizAdjacencia, aux->numVertices, aux->numArestas, cont);
		else if(algoritmo == 2) Kruskal(aux->matrizAdjacencia, aux->numVertices, aux->numArestas, cont);
		else
		{
			printf("Erro no parametro para escolha do algoritmo\n");
			exit(1);
		}
		aux = aux->proximo;
		cont++;
	}
}


void LiberaGrafo(ListaGrafo *lista)
{
	Apontador aux, apaga;
	aux = lista->primeiro;

	while(aux != NULL)
	{
		apaga = aux;
		aux = aux->proximo;
		apaga->matrizAdjacencia = LiberaMatrizDeAdjacencia(apaga->matrizAdjacencia, apaga->numVertices);
		free(apaga);
	}
}

int **LiberaMatrizDeAdjacencia(int **matriz, int tamanho)
{
	  int  i;
	  if(matriz == NULL) return (NULL);

	  for(i=0; i<tamanho; i++)
	  {
		  free(matriz[i]);
	  }
	  free (matriz);
	  return (NULL);
}

void GeraDistribuicaoEspacial(char *nomeDoArquivo, int teste, int distancia[], int quantidadeAcesso[], int tamanho)
{
	char numero[2];
	char saida[30];
	strcpy(saida, nomeDoArquivo);
	sprintf(numero, "%d", teste);
	strcat(saida, numero);
	FILE *arq = fopen(saida, "w");
	if(arq == NULL)
	{
		printf("Erro na abertura do arquvio DistribuiEspaKruskal.txt\n");
		exit(1);
	}
	int i;
	float media;
	for(i=0; i<tamanho; i++)
	{
		if((distancia[i] != 0) && (quantidadeAcesso[i] != 0)) media = (distancia[i] / quantidadeAcesso[i]);
		else media = 0;
		fprintf(arq,"%.2f\n", media);
	}
	fclose(arq);
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


