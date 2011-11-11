#include <stdio.h>
#include <stdlib.h>
#include "kruskal.h"



//void AdjacencyMatrix(int a[][100], int n){
//    int i,j;
//    for(i = 0;i < n; i++)
//    {
//        for(j = 0;j < i; j++)
//        {
//            a[i][j] = a[j][i]= rand()%50;
//            if( a[i][j]>40)a[i][j]=a[j][i]=999;
//
//        }
//    a[i][i] = 999;
//    }
//    printArray(a,n);
//}

void printArray(int **a, int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }
}

int root(int v, int *p)
{

	while(p[v] != v)
    {
    	v = p[v];
    }

    return v;
}

void union_ij(int i, int j, int *p)
{
    if(j > i)
        p[j] = i;
    else
        p[i] = j;
}

void kruskal(int **matriz, int tamanho)
{
    int count, i, min, j, u, v, k, sum;
    int **matrizAux;
    int *vetorAux = (int *)malloc(tamanho * sizeof(int));

	if(vetorAux == NULL)
	{
		printf("Erro para alocar memória ao vetor aux\n");
		exit(1);
	}

    matrizAux = (int **)malloc(tamanho * sizeof(int *)); //Aloca as linhas da matriz
	/*
	 * Tratamento de erro. Verifica se as linhas da matriz são alocadas corretamente e/ou
	 * existe memória suficiente
	 */
	if(matrizAux == NULL)
	{
		printf("Matriz (linha) nao alocada. Verifique memoria\n");
		exit(1);
	}

	for(i=0; i<tamanho; i++)
	{
		matrizAux[i] = (int *)malloc(tamanho * sizeof(int)); //Aloca as colunas da matriz
		/*
		 * Tratamento de erro. Verifica se as colunas da matriz são alocadas corretamente e/ou
		 * existe memória suficiente
		 */
		if(matrizAux[i] == NULL)
		{
			printf("Matriz (coluna) nao alocada. Verifique memoria\n");
			exit(1);
		}

	}

    count = k = sum = 0;
    for(i=0; i<tamanho; i++)
    {
    	vetorAux[i] = i;
    }
    while(count < tamanho)
    {
        min = 999;
        for(i = 0; i < tamanho; i++)
        {
            for(j = 0;j < tamanho; j++)
            {

                if(matriz[i][j] < min)
                {
                    min = matriz[i][j];
                    u = i;
                    v = j;

                }
            }
        }
        if(min != 999)
        {
            i = root(u, vetorAux);
            j = root(v, vetorAux);
            if (i != j)
            {
            	matrizAux[k][0] = u;
            	matrizAux[k][1] = v;

                k++;

                sum += min;
                union_ij(i,j,vetorAux);
            }
        matriz[u][v] = matriz[v][u] = 999;

        }
        count +=1;
    }
    if(count != tamanho)
    {
        printf("spanning tree not exist\n");
    }
    if(count == tamanho)
    {
        printf("Adges Spanning tree is\n");
        for(k=0; k<tamanho-1; k++)
        {
            printf(" %d -> %d ",matrizAux[k][0],matrizAux[k][1]);
        }
    printf("\ncost = %d \n",sum);
    }
}
