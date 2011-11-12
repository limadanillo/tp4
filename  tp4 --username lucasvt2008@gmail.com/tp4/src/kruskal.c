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

	int E[numArestas][3];                   /* complete set of edges */
	int F[numVertices-1][3];                 /* set of edges in min. span. tree */
	int num_edges = 0;             /* num of edges in min. span. tree */
	int next_edge = 0;             /* next edge not yet considered */
	int weight = 0;                /* minimal spanning tree weight */
	int a, b, c, i, j, k;          /* counter/placeholder variables */

/* initialize set of edges */
   k = 0;
   for (i = 0; i < numVertices; i++)
   {
	   for (j = 0; j < numVertices; j++)
	   {
		   if (j > i)
		   {
			   E[k][0] = i;          /* first vertex of edge */
			   E[k][1] = j;          /* second vertex of edge */
			   E[k][2] = matriz[i][j];    /* weight of edge */
			   k++;
		   }
	   }
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
   {
	   for (j = 0; j < i; j++)
	   {
		   if (E[j][2] > E[j+1][2])
		   {
			   a = E[j][0];
			   b = E[j][1];
			   c = E[j][2];
			   E[j][0] = E[j+1][0];
			   E[j][1] = E[j+1][1];
			   E[j][2] = E[j+1][2];
			   E[j+1][0] = a;
			   E[j+1][1] = b;
			   E[j+1][2] = c;
		   }
	   }
   }

/* display set of edges - after sort */
   /*for (i = 0; i < numArestas; i++)
   {  for (j = 0; j < 3; j++)
         printf(" %3d", E[i][j]);
      printf("\n");
   }*/

/* create n disjoint subsets */
   initial (numVertices);

/* initialize set of edges in min. span. tree to empty */
   for (i = 0; i < numVertices - 1; i++)
   {
	   for (j = 0; j < 3; j++)
	   {
		   F[i][j] = -1;            /* '-1' denotes 'empty' */
	   }
   }

   //test_univ();

/* find minimal spanning tree */
   while (num_edges < numVertices - 1)
   {
	   a = E[next_edge][0];
	   b = E[next_edge][1];

	   i = find(a);
	   j = find(b);

	   if (!equal(i, j))
	   {
		   merge (i, j);
		   F[num_edges][0] = E[next_edge][0];
		   F[num_edges][1] = E[next_edge][1];
		   F[num_edges][2] = E[next_edge][2];
		   num_edges++;
	   }
	   next_edge++;
	}

/* display edges comprising minimal spanning tree */
for (i=0; i<numVertices - 1; i++)
	{
		printf("%d %d %d", F[i][0], F[i][1], F[i][2]);
		if (i < numVertices - 2) printf("\n");
		weight = weight + F[i][2];
	}
	printf("\n\n");

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
