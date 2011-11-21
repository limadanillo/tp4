#ifndef PILHA_H_
#define PILHA_H_

typedef int Pilha;

/*
 * Procedimento que inicia todas as posições do vetor passado no primeiro parâmetro
 * com um inteiro 0
 * Parâmetro 1 = Vetor de inteiros
 * Parâmetro 2 = Tamanho do vetor
 */
void IniciaVetorComZero(int vetor[], int tamanho);

/*
 * Funçao que, dado um tamanho, retorna um ponteiro para uma região de memória alocada
 * para o tipo pilha de tamanho "tamanho".
 * Parâmetro 1 = Tamanho da estrutura pilha.
 */
Pilha *PilhaNova(int tamanho);

/*
 * Função que verifica se a pilha está vaiza.
 * Parâmetro 1 = Ponteiro para uma variável do tipo pilha.
 * Parâmetro 2 = Tamanho da pilha.
 * Retorna 1 para pilha vazia, 0 para pilha contendo algum elemento
 */
int PilhaVazia(Pilha *p, int tamanho);

/*
 * Procedimento que empilha um elemento na pilha
 * Parâmetro 1 = Ponteiro para uma variável do tipo pilha.
 * Parâmetro 2 = Tamanho da pilha.
 * Parâmetro 3 = Elemento a ser empilhado
 * Parâmetro 4 = Vetor para contem distancia total de cada vertice.
 * Parâmetro 5 = Vetor que contem a quantidade de acessos de cada vértice
 */
void PilhaEmpilha(Pilha *p, int *tamanhoPilha, int elemento, int distancia[], int quantidadeDeAcessos[]);

/*
 * Procedimento que desempilha um elemento na pilha
 * Parâmetro 1 = Ponteiro para uma variável do tipo pilha.
 * Parâmetro 2 = Tamanho da pilha.
 * Parâmetro 3 = Elemento a ser desempilhado
 */
void PilhaDesempilha(Pilha *p, int *tamanhoPilha, int elemento);

/*
 * Função que pesquisa um elemento na pilha
 * Parâmetro 1 = Ponteiro para uma variável do tipo pilha.
 * Parâmetro 2 = Elemento a ser procurado.
 * Retorna 1 se existe elemento, 0 se não existe
 */
int PesquisaElementoNaPilha(Pilha *p, int elemento);

/*
 * Procedimento que calcula distância de acesso a um elemento da pilha
 * Parâmetro 1 = Ponteiro para uma variável do tipo pilha.
 * Parâmetro 2 = Tamanho da pilha.
 * Parâmetro 3 = Elemento a ser empilhado
 * Parâmetro 4 = Vetor para contem distancia total de cada vertice.
 * Parâmetro 5 = Vetor que contem a quantidade de acessos de cada vértice
 */
void CalculaDistanciaPilha(Pilha *p, int *tamanhoPilha, int elemento, int distancia[], int quantidadeDeAcessos[]);

/*
 * Procedimento que libera memória amarzenada na estrutura do tipo pilha.
 * Parâmetro 1 = Ponteiro para uma variável do tipo pilha.
 */
void PilhaDestroi(Pilha *p);


#endif /* PILHA_H_ */
