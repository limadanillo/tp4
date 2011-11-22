#ifndef KRUSKAL_H_
#define KRUSKAL_H_
#define COL_GRAFO 3

/*
 * Procedimento que procura uma árvore geradora mínima segundo Kruskal.
 * Parâmetro 1 = Matriz de adjacência representando o grafo
 * Parâmetro 2 = Número de vértices do grafo
 * Parâmetro 3 = Número de arestas do grafo
 * Parâmetro 4 = Número do teste que corresponde a entrada que está sendo analisada
 * Imprime na saída padrao a árvore geradora mínima do grafo passado no primeiro parâmetro
 */
void Kruskal(int **matriz, int numVertices, int numArestas, int teste);

/*
 * Função que retorna o peso do vértice
 * Parâmetro 1 = Número do vértice
 * Parâmetro 2 = Vetor de pesos
 * Retorna o vértice que possui o peso na posíção vértice do vetor pesoAresta
 */
int Raiz(int vertice, int pesoAresta[]);

/*
 * Reordena ordem do vetor de vértice
 * Parâmetro 1 = Vértice i
 * Parâmetro 2 = Vértice j
 * Parâmetro 3 = Vetor com o peso das Arestas
 */
void Reoderna(int i, int j,int pesoAresta[]);


#endif /* KRUSKAL_H_ */
