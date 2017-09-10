/*
 * In The Name Of God
 * ========================================
 * [] File Name : tsp.c
 *
 * [] Creation Date : 16-03-2015
 *
 * [] Last Modified : Mon 16 Mar 2015 10:28:34 AM IRST
 *
 * [] Created By : Tara Tandel (Tara.tandel.94@gmail.com)
 * =======================================
*/
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

#include "set.h"
#include "tsp.h"

static int **P;
static int size;

void travel(int n, int **const W, int *minlength)
{
	int i, j, k, l;
	int **D;
	struct set *V;

	V = set_new();
	for (i = 1; i < n; i++)
		set_add(V, i);

	if (P) {
		for (i = 0; i < size; i++)
			free(P[i]);
		free(P);
	}
	size = n;

	P = malloc(n * sizeof(int *));
	for (i = 0; i < n; i++)
		P[i] = malloc((1 << n) * sizeof(int));

	D = malloc(n * sizeof(int *));
	for (i = 0; i < n; i++)
		D[i] = malloc((1 << n) * sizeof(int));

	for (i = 1; i < n; i++)
		D[i][0] = W[i][0];

	for (k = 1; k <= n - 2; k++) {
		struct set **A;
		int A_n;

		set_subset(V, k, &A, &A_n);
		for (l = 0; l < A_n; l++) {
			for (i = 1; i < n; i++) {
				if (!set_get(A[l], i)) {
					int min = INT_MAX;
					int min_index;

					for (j = 0; j < n; j++) {
						if (set_get(A[l], j)) {
							struct set *t;

							t = set_new();
							*t = *(A[l]);
							set_remove(t, j);
							if (D[j][t->set_t] + W[i][j] > 0
									&& min > D[j][t->set_t] + W[i][j]) {
								min = D[j][t->set_t] + W[i][j];
								min_index = j;
							}
							set_free(t);
						}
					}
					D[i][A[l]->set_t] = min;
					P[i][A[l]->set_t] = min_index;
				}
			}
		}
		for (l = 0; l < A_n; l++)
			set_free(A[l]);
		free(A);
	}

	int min = INT_MAX;
	int min_index;

	for (i = 1; i < n; i++) {
		struct set *t;

		t = set_new();
		*t = *V;
		set_remove(t, i);
		if (D[i][t->set_t] + W[0][i] >= 0
				&& min > D[i][t->set_t] + W[0][i]) {
			min = D[i][t->set_t] + W[0][i];
			min_index = i;
		}
		set_free(t);
	}

	D[0][V->set_t] = min;
	P[0][V->set_t] = min_index;
	*minlength = min;

	for (i = 0; i < n; i++)
		free(D[i]);
	free(D);

	set_free(V);
}

void travel_fprint(FILE *stream)
{
	if (!P || !size)
		return;
	int i;
	int start = 0, old_start = 0;
	struct set *V;

	V = set_new();
	for (i = 1; i < size; i++)
		set_add(V, i);

	fprintf(stream, "1 -> ");
	while (V->set_t) {
		fprintf(stream, "%d -> ", P[start][V->set_t] + 1);
		old_start = start;
		start = P[start][V->set_t];
		set_remove(V, P[old_start][V->set_t]);
	}
	fprintf(stream, " 1\n");

	set_free(V);
}
