/*
 * In The Name Of God
 * ========================================
 * [] File Name : main.c
 *
 * [] Creation Date : 16-03-2015
 *
 * [] Last Modified : Mon 16 Mar 2015 01:45:14 AM IRST
 *
 * [] Created By : Tara Tandel (Tara.tandel.94@gmail.com)
 * =======================================
*/
#include <stdio.h>
#include <stdlib.h>

#include "set.h"

int main(int argc, char *argv[])
{
	struct set *S = set_new();

	set_add(S, 1);
	set_add(S, 2);
	set_add(S, 3);
	set_add(S, 4);

	set_fprint(S, stdout);
	printf("\n");

	set_remove(S, 1);

	set_fprint(S, stdout);
	printf("\n");

	struct set **subsets = NULL;
	int subsets_n;
	int i;

	set_subset(S, 2, &subsets, &subsets_n);
	for (i = 0; i < subsets_n; i++) {
		set_fprint(subsets[i], stdout);
		printf("\n");
		set_free(subsets[i]);
	}
	free(subsets);
}
