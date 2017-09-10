/*
 * In The Name Of God
 * ========================================
 * [] File Name : main.c
 *
 * [] Creation Date : 10-03-2015
 *
 * [] Last Modified : Tue 10 Mar 2015 01:28:41 AM IRST
 *
 * [] Created By : tara tandel (tara.tandel.94@gmail.com)
 * =======================================
*/
#include <stdio.h>

#include "diset.h"

int main(int argc, char *argv[])
{
	struct diset *d = diset_new(10);

	printf("%d\n", diset_find(d, 1));
	diset_merge(d, 1, 4);
	printf("%d\n", diset_find(d, 4));
	printf("%d\n", diset_find(d, 1));
	printf("%d\n", diset_members(d, 4));

	diset_delete(d);
}
