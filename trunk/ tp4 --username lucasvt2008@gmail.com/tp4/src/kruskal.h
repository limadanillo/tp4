#ifndef KRUSKAL_H_
#define KRUSKAL_H_
#define COL_GRAFO 3

/*
 * Procedimento que procura uma árvore geradora mínima segundo Kruskal.
 * Parâmetro 1 = Matriz de adjacência representando o grafo
 * Parâmetro 2 = Número de vértices do grafo
 * Parâmetro 3 = Número de arestas do grafo
 * Imprime na saída padrao a árvore geradora mínima do grafo passado no primeiro parâmetro
 */
void Kruskal(int **matriz,int numVertices, int numArestas, int teste);

/*
 * Procedimento que cria um vetor com os vértices do grafo.
 * Parâmetro 1 = Vetor para alocar os vértices
 * Parâmetro 2 = Número de vértices
 */
void CriaSubConjunto(int U[], int n);

/*
 * Função que analisa se dois números inteiros são iguais.
 * Retorna 1 se são iguais, retorna 0 caso contrário.
 * Recebe dois parâmetros, que são os dois números inteiros para comparação
 */
int Igual(int p, int q);

/*
 * Função procura no vetor passado no primeiro parâmetro a posição do vértice i.
 * Retorna a posição do vértice.
 * Parâmetro 1 = Vetor vértices
 * Parâmetro 2 = Vértice
 */
int ProcuraPosicaoVertice (int U[], int i);

/*
 * Reordena ordem do vetor de vértice
 * Parâmetro 1 = Vetor vértices
 * Parâmetro 2 = Vértice x
 * Parâmetro 3 = Vértice y
 */
void Reordena(int U[], int p, int q);

/*
 * Imprime Árvore Geradora mínima
 * Parâmetro 1 = Arvore geradora mínima. Matriz de n linhas e 3 colunas onde n <= número de vértices
 * Parâmetro 2 = Numero de vertices
 */
void ImprimeArvoreGeradoraMinima(int ArvoreMinima[][COL_GRAFO], int numVertices);









//void AdjacencyMatrix(int a[][100], int n);
//void printArray(int **a, int n);
//int root(int v,int *p);
//void union_ij(int i, int j, int *p);
//void kruskal(int **matriz, int tamanho);

#endif /* KRUSKAL_H_ */
