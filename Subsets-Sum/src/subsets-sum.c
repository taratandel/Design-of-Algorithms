/*
 * In The Name Of God
 * ========================================
 * [] File Name : subsets-sums.c
 *
 * [] Creation Date : 08-05-2015
 *
 * [] Created By : Tara Tandel (Tara.tandel.94@gmail.com)
 * =======================================
*/
#include <stdlib.h>
#include <stdio.h>

/*
 * Copyright (c) 2015 Tara Tandel.
*/

static int n;
static int W;
static const int *w;
static int *include;

static int subsets_sum_promising(int index, int total, int current)
{
	return (current + total >= W) &&
	       (current == W || current + w[index] <= W);
}

static void subsets_sum_print(void)
{
	int i;
	for (i = 0; i < n; i++)
		if (include[i])
			printf("%d ", w[i]);
	printf("\n");
}

static void subsets_sum_r(int index, int total, int current)
{
	if (subsets_sum_promising(index, total, current)) {
		if (current == W) {
			subsets_sum_print();
		} else {
			include[index] = 1;
			subsets_sum_r(index + 1, total - w[index],
				current + w[index]);
			include[index] = 0;
			subsets_sum_r(index + 1, total - w[index], current);
		}
	}
}

void subsets_sum(int size, const int *weight, int w_max)
{
	int total = 0;
	int i;

	n = size;
	W = w_max;
	w = weight;

	include = malloc(sizeof(int) * size);
	for (i = 0; i < n; i++)
		include[i] = 0;
	for (i = 0; i < n; i++)
		total += weight[i];

	subsets_sum_r(0, total, 0);
}
