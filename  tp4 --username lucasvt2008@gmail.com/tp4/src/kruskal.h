/*
 * kruskal.h
 *
 *  Created on: 10/11/2011
 *      Author: lucas
 */

#ifndef KRUSKAL_H_
#define KRUSKAL_H_

//void AdjacencyMatrix(int a[][100], int n);
void printArray(int **a, int n);
int root(int v,int *p);
void union_ij(int i, int j, int *p);
void kruskal(int **matriz, int tamanho);

#endif /* KRUSKAL_H_ */