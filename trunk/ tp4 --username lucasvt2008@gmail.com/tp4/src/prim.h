#ifndef PRIM_H_
#define PRIM_H_

#define MAXNUMVERTICES  100
#define MAXNUMARESTAS   4500
#define FALSE           0
#define TRUE            1
#define INFINITO        INT_MAX

typedef int TipoValorVertice;
typedef int TipoPeso;
typedef struct TipoGrafo {
  TipoPeso Mat[MAXNUMVERTICES + 1][MAXNUMVERTICES + 1];
  int  NumVertices;
  int  NumArestas;
} TipoGrafo;

typedef int  TipoApontador;

typedef int  TipoIndice;

typedef struct TipoItem {
  TipoPeso Chave;
} TipoItem;

typedef TipoItem Vetor[MAXNUMVERTICES + 1];


TipoApontador Aux;
int  i, NArestas;
short  FimListaAdj;
TipoValorVertice V1, V2, Adj;
TipoPeso Peso;

TipoValorVertice NVertices;
TipoIndice n;   /*Tamanho do heap*/
TipoValorVertice Raiz;



struct LOC_AgmPrim {
  TipoPeso P[MAXNUMVERTICES + 1];
  TipoValorVertice Pos[MAXNUMVERTICES + 1];
} ;

void Prim(int **matriz, int numVertice, int numAresta, int *Raiz);
void DiminuiChaveInd(TipoIndice i, TipoPeso ChaveNova, TipoItem *A, TipoPeso *P, TipoValorVertice *Pos);
TipoItem RetiraMinInd(TipoItem *A, TipoPeso *P, TipoValorVertice *Pos);
void Constroi(TipoItem *A, TipoPeso *P, TipoValorVertice *Pos);
void RefazInd(TipoIndice Esq, TipoIndice Dir, TipoItem *A, TipoPeso *P, TipoValorVertice *Pos);
void FGVazio(TipoGrafo *Grafo);
//void InsereAresta(TipoValorVertice *V1, TipoValorVertice *V2, TipoPeso *Peso, TipoGrafo *Grafo);
short  ExisteAresta(TipoValorVertice Vertice1, TipoValorVertice Vertice2, TipoGrafo *Grafo);
short  ListaAdjVazia(TipoValorVertice *Vertice, int **matriz, int numVertice, TipoGrafo *Grafo);
TipoApontador PrimeiroListaAdj(TipoValorVertice *Vertice, int **matriz, int numVertice, TipoGrafo *Grafo);
void ProxAdj(TipoValorVertice *Vertice, int **matriz, int numVertice, TipoGrafo *Grafo, TipoValorVertice *Adj, TipoPeso *Peso, TipoApontador *Prox, short *FimListaAdj);
void ImprimeGrafo(TipoGrafo *Grafo, int **matriz, int numVertice);
#endif /* PRIM_H_ */
