/*
 * In The Name Of God
 * ========================================
 * [] File Name : lcs.c
 *
 * [] Creation Date : 04-03-2015
 *
 * [] Last Modified : Wed 04 Mar 2015 05:24:33 AM IRST
 *
 * [] Created By : Tara Tandel (Tara.tandel.94@gmail.com)
 * =======================================
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "lcs.h"

static char *P;

int lcs(const char *A, const char *B)
{
	int max = 0;
	int max_i, max_j;
	int **D;
	int n, m;
	int i, j;

	if (P)
		free(P);

	n = strlen(A);
	m = strlen(B);
	D = malloc(n * sizeof(int *));
	for (i = 0; i < n; i++)
		D[i] = malloc(m * sizeof(int));

	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			if (A[i] != B[j])
				D[i][j] = 0;
			else
				D[i][j] = (i > 0 && j > 0)
				          ? D[i - 1][j - 1] + 1 : 1;
			if (D[i][j] > max) {
				max = D[i][j];
				max_i = i;
				max_j = j;
			}
		}
	}

	P = malloc(((n > m) ? m : n)
	           * sizeof(char));
	i = 0;
	while (max_i >= 0 && max_j >= 0 &&
	       D[max_i][max_j] != 0) {
		P[i] = A[max_i];
		max_i--;
		max_j--;
		i++;
	}
	P[i] = 0;

	for (i = 0; i < n; i++)
		free(D[i]);
	free(D);

	return max;
}

void lcs_fprint(FILE *stream)
{
	if (!P)
		return;

	int size = strlen(P);
	while (size > 0)
		fputc(P[--size], stream);
	fputc('\n', stream);
}
