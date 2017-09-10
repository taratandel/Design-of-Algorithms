/*
 * In The Name Of God
 * ========================================
 * [] File Name : set.c
 *
 * [] Creation Date : 16-03-2015
 *
 * [] Last Modified : Mon 16 Mar 2015 03:37:28 AM IRST
 *
 * [] Created By : Tara Tandel (Tara.tandel.94@gmail.com)
 * =======================================
*/
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "set.h"

struct set *set_new(void)
{
	struct set *new;

	new = malloc(sizeof(struct set));
	new->set_t = 0;
	new->size = 0;
	return new;
}

void set_add(struct set *S, int number)
{
	if (!set_get(S, number)) {
		S->set_t += 1 << number;
		S->size++;
	}
}

void set_remove(struct set *S, int number)
{
	if (set_get(S, number)) {
		S->set_t -= 1 << number;
		S->size--;
	}
}

int set_get(const struct set *S, int number)
{
	return (S->set_t & (1 << number));
}

void set_fprint(const struct set *S, FILE *stream)
{
	int i = 0;

	fprintf(stream, "[ ");
	for (i = 0; i < sizeof(int) * 8; i++) {
		if (set_get(S, i))
			fprintf(stream, "%d ", i);
	}
	fprintf(stream, "]");
	fflush(stream);
}

void set_free(struct set *S)
{
	free(S);
}

static int C(int n, int k)
{
	int i, j;
	int **B;

	B = malloc((n + 1) * sizeof(int *));
	for (i = 0; i <= n; i++)
		B[i] = malloc((k + 1) * sizeof(int));

	for (i = 0; i <= n; i++) {
		for (j = 0; j <= k; j++) {
			if (j == 0 || j == i)
				B[i][j] = 1;
			else if (i > j)
				B[i][j] = B[i - 1][j - 1] + B[i - 1][j];
		}
	}
	int answer = B[n][k];

	for (i = 0; i <= n; i++)
		free(B[i]);
	free(B);

	return answer;
}

/*
 * set: S
 * subset size: k
 * subset template: t
 * S = {..., s, ...}
 *
 * http://stackoverflow.com/questions/4555565/
 *	generate-all-subsets-of-size-k-from-a-set
*/
static void set_subset_r(const struct set *S, int k, struct set *t,
		int index, int s, struct set **subsets, int *sub_index)
{
	int i = 0;

	if (index == k) {
		*subsets[*sub_index] = *t;
		(*sub_index)++;
	} else {
		for (i = s; i < sizeof(int) * 8; i++) {
			if (set_get(S, i)) {
				set_add(t, i);
				set_subset_r(S, k, t, index + 1,
						i + 1, subsets, sub_index);
				set_remove(t, i);
			}
		}
	}
}

void set_subset(const struct set *S, int k,
		struct set ***subsets, int *numbers)
{
	int i = 0;
	int zero = 0;
	struct set *t;

	*numbers = C(S->size, k);
	*subsets = malloc(*numbers * sizeof(struct set *));
	for (i = 0; i < *numbers; i++)
		(*subsets)[i] = set_new();

	t = set_new();
	set_subset_r(S, k, t, 0, 0, *subsets, &zero);
	set_free(t);
}
