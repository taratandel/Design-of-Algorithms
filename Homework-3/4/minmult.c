/*
 * In The Name Of God
 * ========================================
 * [] File Name : minmult.c
 *
 * [] Creation Date : 24-02-2015
 *
 * [] Last Modified : Tue 24 Feb 2015 12:27:56 PM IRST
 *
 * [] Created By : Tara Tandel (Tara.tandel.94@gmail.com)
 * =======================================
*/
#include <stdio.h>
#include <stdlib.h>

static int **P;
static int size;

int minmult(int n, const int d[])
{
	int i, j, k, diagonal;
	int **M;

	M = malloc(n * sizeof(int *));
	for (i = 0; i < n; i++)
		M[i] = malloc(n * sizeof(int));

	if (P) {
		for (i = 0; i < size; i++)
			free(P[i]);
		free(P);
	}

	P = malloc(n * sizeof(int *));
	for (i = 0; i < n; i++)
		P[i] = malloc(n * sizeof(int));

	size = n;

	for (i = 0; i < n; i++)
		M[i][i] = 0;

	for (diagonal = 1; diagonal < n; diagonal++) {
		for (i = 0; i < n - diagonal; i++) {
			j = i + diagonal;
			M[i][j] = M[i][i] + M[i + 1][j] + d[i] *
				d[i + 1] * d[j + 1];
			P[i][j] = i;
			for (k = i + 1; k < j; k++) {
				int val = M[i][k] + M[k + 1][j] +
					d[i] * d[k + 1] * d[j + 1];

				if (val < M[i][j]) {
					M[i][j] = val;
					P[i][j] = k;
				}
			}
		}
	}

	int retval = M[0][n - 1];

	for (i = 0; i < n; i++)
		free(M[i]);
	free(M);

	return retval;
}

void minmult_fprint_r(FILE *stream, int i, int j)
{
	if (i == j) {
		fprintf(stream, "A%d", i);
	} else {
		int val = P[i][j];

		fprintf(stream, "(");
		minmult_fprint_r(stream, i, val);
		minmult_fprint_r(stream, val + 1, j);
		fprintf(stream, ")");
	}
}

void minmult_fprint(FILE *stream)
{
	if (!size || !P)
		return;
	minmult_fprint_r(stream, 0, size - 1);
	fprintf(stream, "\n");
	fflush(stream);
}
