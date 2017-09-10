/*
 * In The Name Of God
 * ========================================
 * [] File Name : main.c
 *
 * [] Creation Date : 21-02-2015
 *
 * [] Last Modified : Sat 21 Feb 2015 07:54:02 PM IRST
 *
 * [] Created By : Tara Tandel (Tara.tandel.94@gmail.com)
 * =======================================
*/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int i;
	int max = 0, current_max = 0;
	int n;
	int *array;

	scanf("%d", &n);

	array = malloc(n * sizeof(int));

	for (i = 0; i < n; i++)
		scanf("%d", array + i);

	for (i = 0; i < n; i++) {
		max = (current_max > max) ? current_max : max;
		if (current_max + array[i] < 0)
			current_max = 0;
		else
			current_max += array[i];
	}
	max = (current_max > max) ? current_max : max;

	printf("%d\n", max);
}
