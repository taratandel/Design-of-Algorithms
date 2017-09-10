/*
 * In The Name Of God
 * ========================================
 * [] File Name : main.c
 *
 * [] Creation Date : 24-02-2015
 *
 * [] Last Modified : Tue 24 Feb 2015 12:27:00 PM IRST
 *
 * [] Created By : Tara Tandel (Tara.tandel.94@gmail.com)
 * =======================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "minmult.h"
#include "common.h"

int main(int argc, char *argv[])
{
	char filename[1024];
	int i, number;
	int *d;
	FILE *file = NULL;

	printf("Please enter filename:\n");
	fgets(filename, 1024, stdin);
	filename[strlen(filename) - 1] = '\0';

	file = fopen(filename, "r");
	if (!file)
		sdie("fopen()");

	fscanf(file, "%d", &number);
	d = malloc((number + 1) * sizeof(int));
	for (i = 0; i < number; i++) {
		int x, y;

		fscanf(file, "%*s %d %d", &x, &y);
		if (i > 0 && d[i] != x)
			udie("wrong input at %d matrix from %s (%d != %d)",
					i + 1, filename, d[i], x);
		d[i] = x;
		d[i + 1] = y;
	}
	fclose(file);

	minmult(number, d);
	minmult_fprint(stdout);

	free(d);
}
