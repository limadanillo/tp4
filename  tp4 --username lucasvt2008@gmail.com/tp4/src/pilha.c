#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

void IniciaVetorComZero(int vetor[], int tamanho)
{
	int i;
	for(i=0; i<tamanho; i++) vetor[i] = 0;
}

Pilha *PilhaNova(int tamanho)
{
	Pilha *pilha = (Pilha *)malloc(tamanho * sizeof(Pilha));
	int i;
	for(i=0; i<tamanho; i++)
	{
		pilha[i] = -1;
	}
	return pilha;
}

int PilhaVazia(Pilha *p, int tamanho)
{
	int i = 0;
	while(i < tamanho)
	{
		if(p[i] != -1) return 0;
	}
	return 1;
}

void PilhaEmpilha(Pilha *p, int *tamanhoPilha, int elemento, int distancia[], int quantidadeDeAcessos[])
{
	if(PesquisaElementoNaPilha(p, elemento))
	{
		CalculaDistanciaPilha(p, tamanhoPilha, elemento, distancia, quantidadeDeAcessos);
		PilhaDesempilha(p, tamanhoPilha, elemento);
	}
	(*tamanhoPilha)++;
	p[elemento] = (*tamanhoPilha);
}

void PilhaDesempilha(Pilha *p, int *tamanhoPilha, int elemento)
{
	int aux = p[elemento];
	p[elemento] = -1;
	int i = 0;
	while(i < *tamanhoPilha)
	{
		if(aux < p[i]) p[i]--;
		i++;
	}
	(*tamanhoPilha)--;
}

int PesquisaElementoNaPilha(Pilha *p, int elemento)
{
	if(p[elemento] != -1) return 1;
	else return 0;
}

void CalculaDistanciaPilha(Pilha *p, int *tamanhoPilha, int elemento, int distancia[], int quantidadeDeAcessos[])
{
	distancia[elemento] = distancia[elemento] + ((*tamanhoPilha) - p[elemento]);
	quantidadeDeAcessos[elemento]++;
}

void PilhaDestroi(Pilha *p)
{
	free(p);
}
