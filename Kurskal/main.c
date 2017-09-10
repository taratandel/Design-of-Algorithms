/*
 * In The Name Of God
 * ========================================
 * [] File Name : main.c
 *
 * [] Creation Date : 10-03-2015
 *
 * [] Last Modified : Tue 10 Mar 2015 01:24:43 AM IRST
 *
 * [] Created By : Tara Tandel (Tara.tandel.94@gmail.com)
 * =======================================
*/
#include <stdlib.h>
#include <stdio.h>

#include "edge.h"
#include "kurskal.h"

int main(int argc, char *argv[]){
	int n, m;
	int i;
	struct edge *E;

	scanf("%d %d", &n, &m);

	E = malloc(sizeof(struct edge) * m);

	for (i = 0; i < m; i++) {
		int V1, V2, W;
		
		scanf("%d %d %d", &V1, &V2, &W);

		E[i].start = V1 - 1;
		E[i].end = V2 - 1;
		E[i].weight = W;
	}
	
	int out_m;
	struct edge *out_E;
	int min;

	min = kurskal(m, n, E, &out_m, &out_E);

	printf("Minimum is : %d\n", min);
	printf("start : end : weight\n");
	for (i = 0; i < out_m; i++)
		printf("%d : %d : %d\n",
				out_E[i].start,
				out_E[i].end,
				out_E[i].weight);

	free(out_E);
	free(E);
}
