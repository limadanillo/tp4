#ifndef GRAFO_H_
#define GRAFO_H_

//Aresta dos vértices da posição 0 a posição 1, com o peso da aresta na posição 2
//typedef int Aresta[3];

typedef struct Grafo *Apontador;

/*
 * Estrutura de um grafo, contendo:
 * - Número de arestas
 * - Número de vértices
 * - Array do tipo Aresta
 */
typedef struct Grafo {
	int numVertices;
	int numArestas;
	int **matrizAdjacencia;
	Apontador proximo;
}Grafo;

//Lista de grafos - Múltiplas entradas
typedef struct ListaGrafo {
	Apontador primeiro, ultimo;
}ListaGrafo;

/*
 * Procedimento que inicializa o grafo
 * Possui um parâmetro, do tipo ponteiro para a esturutra ListaGrafo
 */
void InicializaGrafo(ListaGrafo *lista);

/*
 * Procedimento para captar da entrada padrão o(s) grafo(s) com seus respectivos
 * vértices, arestas e peso. Possui um parâmetro, do tipo ListaGrafo
 */
void LeEntrada(ListaGrafo *lista);

/*
 * Função que retorna uma matriz de adjacencia, preenchidas em todas posições aij
 * com o valor 0. Recebe como parâmetro um tamanho, já que esta matriz é quadrada.
 * Este tamanho nada mais é do que o número de vértices.
 */
int **CriaMatrizDeAdjacencia(int tamanho);
/*
 * Procedimento para inserir uma estrutura do tipo grafo
 * na lista passada no primeiro parâmetro. O segundo e o terceiro
 * parâmetro são as quantidade de arestas e vértices respectivamente
 */
void InsereGrafo(ListaGrafo *lista, int numArestas, int numVertices);

/*
 * Procedimento que Insere uma aresta com seus respectivos vértices, com um determinado peso
 * Parâmetro 1: matriz (matriz de adjacência que deve ser previamente criada)
 * Parâmetro 2: vértive origem
 * Parâmetro 3: vértive destino
 * Parâmetro 4: peso da aresta
 */
void InsereAresta(int **matriz, int origem, int destino, int peso);

/*
 * Gera saída do programa que serão as árvores geradoras mínimas de
 * acordo com o algoritmo de Prim ou Kruscal.
 * Recebe no primeiro parâmetro uma lista encadeada do tipo ListaGrafo
 * que conterá as entradas (grafos). No segundo parametro, um número inteiro (1 ou 2)
 * que representa o algoritmo escolhido de acordo com a linha de comando: 1 - Prim
 * 2 - Kruscal
 */
void GeraSaidaPadrao(ListaGrafo *lista, int algoritmo);

/*
 * Libera memória alocada para os grafos. Possui um parâmetro do tipo ListaGrafo
 */
void LiberaGrafo(ListaGrafo *lista);

/*
 * Libera memória alocada para as matrizes de adjacencia. Possui dois parâmetros, o primeiro,
 * um ponteiro de ponteiro (tipo inteiro) que será a matriz. O segundo parâmetro, o tamanho do lado
 * da matriz de adjacencia (lembrando que ela é uma matriz quadrada).
 */
int **LiberaMatrizDeAdjacencia(int **matriz, int tamanho);



void ImprimirEntradas(ListaGrafo *lista);
void ImprimirMatriz(int **v, int tamanho);

#endif /* GRAFO_H_ */
