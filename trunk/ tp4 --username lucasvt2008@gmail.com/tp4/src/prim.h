#ifndef PRIM_H_
#define PRIM_H_

/*
 * Define valores para simular variáveis booleanas.
 * 0 para falso.
 * 1 para verdadeiro.
 */
#define FALSO		0
#define VERDADEIRO  1


/*
 * Procedimento que procura uma árvore geradora mínima segundo Prim.
 * Parâmetro 1 = Matriz de adjacência representando o grafo
 * Parâmetro 2 = Número de vértices do grafo
 * Parâmetro 3 = Número de arestas do grafo
 * Imprime na saída padrao a árvore geradora mínima do grafo passado no primeiro parâmetro
 */
void Prim(int **matriz, int numVertice, int numAresta);

/*
 * Procedimento que diminui chave do indice do heap.
 * Parâmetro 1 = Indice do heap
 * Parâmetro 2 = Nova chave que deverá ser aplicada no inidce do heap
 * Parâmetro 3 = Vetor de inteiros simulando o heap dos vértices
 * Parâmetro 4 = Vetor de inteiro que contem os pesos das arestas do Grafo
 * Parâmetro 5 = Posição de um determinado vértice no heap
 */
void DiminuiChaveIndice(int indice, int chaveNova, int heap[], int pesoAresta[], int posicaoVerticeHeap[]);

/*
 * Funçao que retorna o indice minimo do heap.
 * Parâmetro 1 = Vetor de inteiros simulando o heap dos vértices
 * Parâmetro 2 = Vetor de inteiro que contem os pesos das arestas do Grafo
 * Parâmetro 3 = Posição de um determinado vértice no heap
 * Parâmetro 4 = Inteiro com tamanho do heap
 * Retorna um inteiro: O indice minimo do heap
 */
int RetiraIndiceMinimo(int heap[], int pesoAresta[], int posicaoVerticeHeap[], int *tamanhoDoHeap);

/*
 * Procedimento que retira o indice minimo do heap passado no primeiro parâmetro.
 * Parâmetro 1 = Vetor de inteiros simulando o heap dos vértices
 * Parâmetro 2 = Vetor de inteiro que contem os pesos das arestas do Grafo
 * Parâmetro 3 = Posição de um determinado vértice no heap
 * Parâmetro 4 = Inteiro com tamanho do heap
 */
void Constroi(int heap[], int pesoAresta[], int *posicaoVerticeHeap, int *tamanhoDoHeap);

/*
 * Procedimento Que refaz o indice do heap passado no terceiro parâmetro.
 * Parâmetro 1 = Vertice a direita
 * Parâmetro 2 = Vertice a esquerda
 * Parâmetro 3 = Vetor de inteiros simulando o heap dos vértices
 * Parâmetro 4 = Vetor de inteiro que contem os pesos das arestas do Grafo
 * Parâmetro 5 = Posição de um determinado vértice no heap
 */
void RefazIndice(int esquerda, int direita, int heap[], int pesoAresta[], int posicaoVerticeHeap[]);

/*
 * Funçao que simula um retorno booleano ao analisar se a lista de vértices adjacentes está vazia.
 * Parâmetro 1 = Inteiro representando o vértice
 * Parâmetro 2 = Matriz de inteiros representando uma matriz de adjacencia (grafo)
 * Parâmetro 3 = Quantidade de vértices no grafo
 * Retorna um inteiro: 1 para verdadeiro, 0 para falso.
 */
int ListaAdjacenciaVazia(int *vertice, int **matriz, int numVertice);

/*
 * Funçao que procura o primeiro vértice adjacente passado no primeiro parâmetro.
 * Parâmetro 1 = Inteiro representando o vértice
 * Parâmetro 2 = Matriz de inteiros representando uma matriz de adjacência (grafo)
 * Parâmetro 3 = Quantidade de vértices no grafo
 * Retorna um inteiro: O primeiro vértice adjacente ao vértice do primeiro parâmetro. Em caso
 * 					   de erro, retorna 0.
 */
int PrimeiroListaAdjacencia(int *vertice, int **matriz, int numVertice);

/*
 * Procedimento que atribui a variável "proximoAdjacente", o próximo vértice adjacente do
 * vértice do primeiro parâmetro no grafo.
 * Parâmetro 1 = Inteiro representando o vértice
 * Parâmetro 2 = Matriz de inteiros representando uma matriz de adjacência (grafo)
 * Parâmetro 3 = Quantidade de vértices no grafo
 * Parâmetro 4 = Parâmetro inteiro que receberá a atribuição do vértice adjacente antes da pesquisa
 * Parâmetro 5 = Inteiro que representa o peso da aresta
 * Parâmetro 6 = Parâmetro inteiro que receberá a atribuição do próximo vértice adjacente
 * Parâmetro 7 = Flag para simular valores booleanos, no qual detecta o final da lista de adjacentes
 */
void ProxAdjacente(int *vertice, int **matriz, int numVertice, int *adjacente, int *peso, int *proximoAdjacente, int *FimListaAdj);

#endif /* PRIM_H_ */
