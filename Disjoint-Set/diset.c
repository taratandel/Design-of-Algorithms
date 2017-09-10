/*
 * In The Name Of God
 * ========================================
 * [] File Name : diset.c
 *
 * [] Creation Date : 10-03-2015
 *
 * [] Last Modified : Tue 10 Mar 2015 01:27:02 AM IRST
 *
 * [] Created By : tara tandel (tara.tandel.94@gmail.com)
 * =======================================
*/
#include <stdlib.h>

#include "diset.h"

struct diset *diset_new(int number)
{
	struct diset *new;
	int i = 0;

	new = malloc(sizeof(struct diset));
	new->U = malloc(sizeof(int) * number);
	new->number = number;

	for (i = 0; i < number; i++)
		new->U[i] = -1;

	return new;

}

int diset_find(struct diset *d, int i)
{
	if (d->U[i] < 0)
		return i;
	return d->U[i] = diset_find(d, d->U[i]);
}

int diset_merge(struct diset *d, int i, int j)
{
	i = diset_find(d, i);
	j = diset_find(d, j);
	if (i != j) {
		d->U[i] = d->U[i] + d->U[j];
		d->U[j] = i;
		return 1;
	}
	return 0;

}

int diset_members(struct diset *d, int i)
{
	i = diset_find(d, i);
	return -d->U[i];
}

void diset_delete(struct diset *d)
{
	free(d->U);
	free(d);
}
