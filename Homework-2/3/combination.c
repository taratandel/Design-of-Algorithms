/*
 * In The Name Of God
 * ========================================
 * [] File Name : combination.c
 *
 * [] Creation Date : 18-02-2015
 *
 * [] Last Modified : Wed 18 Feb 2015 10:17:04 PM IRST
 *
 * [] Created By : Tara Tandel (Tara.tandel.94@gmail.com)
 * =======================================
*/
#include <stdlib.h>

#include "combination.h"

static int **combinations;

int combination_r(int n, int k)
{
	if (k == 0 || n <= 0)
		return 1;
	if (n == k)
		return 1;
	if (combinations[n - 1][k] == 0)
		combinations[n - 1][k] = combination_r(n - 1, k);
	if (combinations[n - 1][k - 1] == 0)
		combinations[n - 1][k - 1] = combination_r(n - 1, k - 1);
	return combinations[n - 1][k - 1] + combinations[n - 1][k];
}

int combination(int n, int k)
{
	int i;
	int ret_val;

	combinations = malloc(sizeof(int *) * (n + 1));
	for (i = 0; i < n; i++)
		combinations[i] = calloc(sizeof(int), k + 1);

	ret_val = combination_r(n, k);

	for (i = 0; i < n; i++)
		free(combinations[i]);
	free(combinations);

	return ret_val;
}
