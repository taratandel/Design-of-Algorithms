/*
 * In The Name Of God
 * ========================================
 * [] File Name : n-queen.c
 *
 * [] Creation Date : 12-04-2015
 *
 * [] Last Modified : Sun 12 Apr 2015 07:34:42 AM IRDT
 *
 * [] Created By : Tara Tandel (Tara.tandel.94@gmail.com)
 * =======================================
*/
#include <stdlib.h>
#include <stdio.h>

static int n;
static int *col;

static int n_queen_promising(int index)
{
	int i;

	index--;
	for (i = 0; i < index; i++) {
		if (col[i] == col[index])
			return 0;
		if ((index - i) == abs(col[i] - col[index]))
			return 0;
	}
	return 1;
}

static void n_queen_print(void)
{
	int i, j;

	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (col[i] == j)
				printf("Q");
			else
				printf("-");
		}
		printf("\n");
	}
}

static void n_queen_r(int index)
{
	int i;

	if (n_queen_promising(index)) {
		if (index == n) {
			n_queen_print();	
		} else {
			for (i = 0; i < 4; i++) {
				col[index] = i;
				n_queen_r(index + 1);
			}
		}
	}
}

void n_queen(int size)
{
	n = size;
	col = malloc(n * sizeof(int));

	n_queen_r(0);
}
