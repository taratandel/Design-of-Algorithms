/*
 * In The Name Of God
 * ========================================
 * [] File Name : main.c
 *
 * [] Creation Date : 18-02-2015
 *
 * [] Last Modified : Wed 18 Feb 2015 10:16:07 PM IRST
 *
 * [] Created By : Tara Tandel (Tara.tandel.94@gmail.com)
 * =======================================
*/
#include <stdio.h>

#include "combination.h"

int main(int argc, char *argv[])
{
	int n, k;

	scanf("%d %d", &n, &k);

	printf("%d\n", combination(n, k));
}
