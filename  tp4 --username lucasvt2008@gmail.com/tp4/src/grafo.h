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
 * Parâmetro 1 = Parâmetro tipo ponteiro para a esturutra ListaGrafo
 */
void InicializaGrafo(ListaGrafo *lista);

/*
 * Procedimento para captar da entrada padrão o(s) grafo(s) com seus respectivos
 * vértices, arestas e peso.
 * Parâmetro 1 = Parâmetro do tipo ponteiro para a estrutura ListaGrafo
 * Parâmetro 2 = Representa o algoritmo que será utilizado (e como será preenchida a matriz de adjacencia).
 * 				 1 Prim / 2  Kruskal
 */
void LeEntrada(ListaGrafo *lista, int algoritmo);

/*
 * Função que cria uma matriz quadrada de tamanho "tamanho"
 * Parâmetro 1 = Tamanho da matriz
 * Parâmetro 2 = Representa o algoritmo que será utilizado (e como será preenchida a matriz de adjacencia).
 * 				 1 Prim / 2  Kruskal
 * Retorna ponteiro para matriz.
 */
int **CriaMatrizDeAdjacencia(int tamanho, int algoritmo);

/*
 * Procedimento para inserir uma estrutura do tipo grafo
 * na lista passada no primeiro parâmetro.
 * Parâmetro 1: Parâmetro do tipo ponteiro para a estrutura ListaGrafo
 * Parâmetro 2: Número de Arestas
 * Parâmetro 3: Número de Vértices
 * Parâmetro 4: Representa o algoritmo que será utilizado (e como será preenchida a matriz de adjacencia).
 * 				1 Prim / 2  Kruskal
 */
void InsereGrafo(ListaGrafo *lista, int numArestas, int numVertices, int algoritmo);

/*
 * Procedimento que Insere uma aresta com seus respectivos vértices, com um determinado peso
 * Parâmetro 1: matriz (matriz de adjacência que deve ser previamente criada)
 * Parâmetro 2: vértive origem
 * Parâmetro 3: vértive destino
 * Parâmetro 4: peso da aresta
 */
void InsereAresta(int **matriz, int origem, int destino, int peso);

/*
 * Função que pesquisa em uma matriz de adjacência, o maior peso de aresta existente.
 * Retorna um inteiro contendo o maior peso.
 * Parâmetro 1: matriz (matriz de adjacência que deve ser previamente criada)
 * Parâmetro 2: Número de vértice
 */
int MaiorPesoDeAresta(int **matriz, int numVertice);

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

/*
 * Imprime no arquivo a distância média de acessos dos vértices do grafo
 * Parâmetro 1: Vetor de caracteres que contem o nome do arquivo de saída
 * Parâmetro 2: Vetor de caracteres que contem o numero do teste
 * Parâmetro 3: vetor de distancia total dos vértices
 * Parâmetro 4: vetor de quantidades de acessos do vértice
 * Parâmetro 5: Tamanho dos vetores.
 */
void GeraDistribuicaoEspacial(char *nomeDoArquivo, int teste, int distancia[], int quantidadeAcesso[], int tamanho);


void ImprimirEntradas(ListaGrafo *lista);
void ImprimirMatriz(int **v, int tamanho);

#endif /* GRAFO_H_ */
