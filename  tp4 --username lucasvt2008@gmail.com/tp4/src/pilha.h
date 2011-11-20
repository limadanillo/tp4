#ifndef PILHA_H_
#define PILHA_H_

typedef int Pilha;

void IniciaVetorDistancia(int vetor[], int tamanho);
Pilha *PilhaNova(int tamanho);
int PilhaVazia(Pilha *p, int tamanho);
void PilhaEmpilha(Pilha *p, int *tamanhoPilha, int elemento, int distancia[]);
void PilhaDesempilha(Pilha *p, int *tamanhoPilha, int elemento);
int PesquisaElementoNaPilha(Pilha *p, int elemento);
void CalculaDistanciaPilha(Pilha *p, int *tamanhoPilha, int elemento, int distancia[]);
void PilhaDestroi(Pilha *p);


#endif /* PILHA_H_ */
