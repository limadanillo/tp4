#include <stdio.h>
#include <stdlib.h>
#include "kruskal.h"


/*
Programmer: Gregory A. Perkins
Program:    kruskal.c
Class:      CS 2215
Due:        November 16, 1998

This program is an implementation of Kruskal's Algorithm for
determining a minimal spanning tree for a connected, non-directed,
weighted graph.  This implementation is designed specifically
for the test data required by the project.  The optimum solution
would be to implement the algorithm to generate space for ANY
problem dynamically.
*/

#include <stdio.h>

#define N 6                       /* number of vertices */
#define M 15                      /* number of edges in graph */

int U[N];


/* function definitions */
void kruskal(int **matriz, int numVertices, int numArestas)
{
//{  int W[N][N] = {0,2,4,1,3,2,    /* weighted graph */
//                  2,0,6,4,5,1,
//                  4,6,0,4,2,1,
//                  1,4,4,0,5,4,
//                  3,5,2,5,0,6,
//                  2,1,1,4,6,0};
   int E[numArestas][3];                   /* complete set of edges */
   int F[numVertices-1][3];                 /* set of edges in min. span. tree */
   int num_edges = 0;             /* num of edges in min. span. tree */
   int next_edge = 0;             /* next edge not yet considered */
   int weight = 0;                /* minimal spanning tree weight */
   int a, b, c, i, j, k;          /* counter/placeholder variables */

/* initialize set of edges */
   k = 0;
   for (i = 0; i < numVertices; i++)
      for (j = 0; j < numVertices; j++)
         if (j > i)
         {  E[k][0] = i;          /* first vertex of edge */
            E[k][1] = j;          /* second vertex of edge */
            E[k][2] = matriz[i][j];    /* weight of edge */
            k++;
         }

/* display set of edges - before sort
   for (i = 0; i < M; i++)
   {  for (j = 0; j < 3; j++)
         printf(" %3d", E[i][j]);
      printf("\n");
   }

   pause();*/

/* sort set of edges in non-decreasing order by weight - bubblesort */

   for (i=numArestas - 1; i > 0; i--)
      for (j = 0; j < i; j++)
         if (E[j][2] > E[j+1][2])
         {  a = E[j][0];
            b = E[j][1];
            c = E[j][2];
            E[j][0] = E[j+1][0];
            E[j][1] = E[j+1][1];
            E[j][2] = E[j+1][2];
            E[j+1][0] = a;
            E[j+1][1] = b;
            E[j+1][2] = c;
         }

/* display set of edges - after sort */
   for (i = 0; i < numArestas; i++)
   {  for (j = 0; j < 3; j++)
         printf(" %3d", E[i][j]);
      printf("\n");
   }

/* create n disjoint subsets */
   initial (numVertices);

/* initialize set of edges in min. span. tree to empty */
   for (i = 0; i < numVertices - 1; i++)
      for (j = 0; j < 3; j++)
         F[i][j] = -1;            /* '-1' denotes 'empty' */

   //test_univ();

/* find minimal spanning tree */
   while (num_edges < numVertices - 1)
   {  a = E[next_edge][0];
      b = E[next_edge][1];

      i = find(a);
      j = find(b);

      if (!equal(i, j))
      {  merge (i, j);
         F[num_edges][0] = E[next_edge][0];
         F[num_edges][1] = E[next_edge][1];
         F[num_edges][2] = E[next_edge][2];
         num_edges++;

         //test_univ();
      }

      next_edge++;
   }

/* display edges comprising minimal spanning tree */
   printf("\nMinimal Spanning Tree Edges:\n");
   printf("F = (");
   for (i = 0; i < numVertices - 1; i++)
   {  printf("(V%d,V%d)", F[i][0], F[i][1]);
      if (i < numVertices - 2)
         printf(", ");
      weight = weight + F[i][2];
   }
   printf(")\n");
   printf("Minimal Spanning Tree Weight = %d\n", weight);


}

/*************** makeset() ***************/
void makeset (int i)
{  U[i] = i;
}

/*************** find() ***************/
int find (int i)
{  int j;

   j = i;
   while (U[j] != j)
      j = U[j];
   return (j);
}

/*************** merge() ***************/
void merge (int p, int q)
{  if (p < q)
      U[q] = p;
   else
      U[p] = q;
}

/*************** equal() ***************/
int equal (int p, int q)
{  if (p == q)
      return (1);
   else
      return (0);
}

/*************** initial() ***************/
void initial (int n)
{  int i;

   for (i = 0; i < n; i++)
      makeset(i);
}





































////void AdjacencyMatrix(int a[][100], int n){
////    int i,j;
////    for(i = 0;i < n; i++)
////    {
////        for(j = 0;j < i; j++)
////        {
////            a[i][j] = a[j][i]= rand()%50;
////            if( a[i][j]>40)a[i][j]=a[j][i]=999;
////
////        }
////    a[i][i] = 999;
////    }
////    printArray(a,n);
////}
//
//void printArray(int **a, int n)
//{
//    int i,j;
//    for(i=0;i<n;i++)
//    {
//        for(j=0;j<n;j++)
//        {
//            printf("%d\t",a[i][j]);
//        }
//        printf("\n");
//    }
//}
//
//int root(int v, int *p)
//{
//
//	while(p[v] != v)
//    {
//    	v = p[v];
//    }
//
//    return v;
//}
//
//void union_ij(int i, int j, int *p)
//{
//    if(j > i)
//        p[j] = i;
//    else
//        p[i] = j;
//}
//
//void kruskal(int **matriz, int tamanho)
//{
//    int count, i, min, j, u, v, k, sum;
//    int **matrizAux;
//    int *vetorAux = (int *)malloc(tamanho * sizeof(int));
//
//	if(vetorAux == NULL)
//	{
//		printf("Erro para alocar memória ao vetor aux\n");
//		exit(1);
//	}
//
//    matrizAux = (int **)malloc(tamanho * sizeof(int *)); //Aloca as linhas da matriz
//	/*
//	 * Tratamento de erro. Verifica se as linhas da matriz são alocadas corretamente e/ou
//	 * existe memória suficiente
//	 */
//	if(matrizAux == NULL)
//	{
//		printf("Matriz (linha) nao alocada. Verifique memoria\n");
//		exit(1);
//	}
//
//	for(i=0; i<tamanho; i++)
//	{
//		matrizAux[i] = (int *)malloc(tamanho * sizeof(int)); //Aloca as colunas da matriz
//		/*
//		 * Tratamento de erro. Verifica se as colunas da matriz são alocadas corretamente e/ou
//		 * existe memória suficiente
//		 */
//		if(matrizAux[i] == NULL)
//		{
//			printf("Matriz (coluna) nao alocada. Verifique memoria\n");
//			exit(1);
//		}
//
//	}
//
//    count = k = sum = 0;
//    for(i=0; i<tamanho; i++)
//    {
//    	vetorAux[i] = i;
//    }
//    while(count < tamanho)
//    {
//        min = 999;
//        for(i = 0; i < tamanho; i++)
//        {
//            for(j = 0;j < tamanho; j++)
//            {
//
//                if(matriz[i][j] < min)
//                {
//                    min = matriz[i][j];
//                    u = i;
//                    v = j;
//
//                }
//            }
//        }
//        if(min != 999)
//        {
//            i = root(u, vetorAux);
//            j = root(v, vetorAux);
//            if (i != j)
//            {
//            	matrizAux[k][0] = u;
//            	matrizAux[k][1] = v;
//
//                k++;
//
//                sum += min;
//                union_ij(i,j,vetorAux);
//            }
//        matriz[u][v] = matriz[v][u] = 999;
//
//        }
//        count +=1;
//    }
//    if(count != tamanho)
//    {
//        printf("spanning tree not exist\n");
//    }
//    if(count == tamanho)
//    {
//        printf("Adges Spanning tree is\n");
//        for(k=0; k<tamanho-1; k++)
//        {
//            printf(" %d -> %d ",matrizAux[k][0],matrizAux[k][1]);
//        }
//    printf("\ncost = %d \n",sum);
//    }
//}
