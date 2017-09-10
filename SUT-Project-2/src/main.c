/*
 * In The Name Of God
 * ========================================
 * [] File Name : main.c
 *
 * [] Creation Date : 16-03-2015
 *
 * [] Last Modified : Mon 16 Mar 2015 11:44:02 PM IRST
 *
 * [] Created By : Tara Tandel (Tara.tandel.94@gmail.com)
 * =======================================
*/
#include <stdio.h>
#include <stdlib.h>

int diameter = -1;

int DFS(int root, int **const V)
{
	int max1 = 0;
	int max2 = 0;
	int i;

	for (i = 1; i <= V[root][0]; i++) {
		int height = DFS(V[root][i], V);
		
		height++;
		if (max1 <= height) {
			max2 = max1;
			max1 = height;
		}
	}

	if (max1 && max2)
		diameter = (max1 + max2 > diameter) ?
			max1 + max2 : diameter;
	else
		diameter = (max1 > diameter) ?
			max1 : diameter;
	return max1;
}

int main(int argc, char *argv[])
{
	int i, j;
	int n;
	int root;
	int **V;
	
	scanf("%d %d", &n, &root);
	root--;
	V = malloc(n * sizeof(int *));
	for (i = 0; i < n; i++) {
		int e;
		
		scanf("%d", &e);
		V[i] = malloc((e + 1) * sizeof(int));
		V[i][0] = e;
		
		for (j = 1; j <= e; j++) {
			int child;

			scanf("%d", &child);
			child--;
			V[i][j] = child;
		}
	}

	DFS(root, V);

	printf("%d\n", diameter);

	for (i = 0; i < n; i++)
		free(V[i]);
	free(V);
}
