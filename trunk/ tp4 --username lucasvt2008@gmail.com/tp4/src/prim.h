#ifndef PRIM_H_
#define PRIM_H_

/*
 * Define valores para simular variáveis booleanas.
 * 0 para falso.
 * 1 para verdadeiro.
 */
#define FALSO		0
#define VERDADEIRO  1



void Prim(int **matriz, int numVertice, int numAresta);
void DiminuiChaveInd(int i, int chaveNova, int heap[], int pesoAresta[], int *posicaoVerticeHeap);
int RetiraMinInd(int heap[], int pesoAresta[], int *posicaoVerticeHeap, int *tamanhoDoHeap);
void Constroi(int *heap, int pesoAresta[], int *posicaoVerticeHeap, int *tamanhoDoHeap);
void RefazInd(int Esq, int Dir, int *heap, int pesoAresta[], int *posicaoVerticeHeap);
int ListaAdjVazia(int *Vertice, int **matriz, int numVertice);
int PrimeiroListaAdj(int *Vertice, int **matriz, int numVertice);
void ProxAdj(int *Vertice, int **matriz, int numVertice, int *Adj, int *Peso, int *Prox, int *FimListaAdj);

#endif /* PRIM_H_ */
