/*
 * In The Name Of God
 * ========================================
 * [] File Name : main.c
 *
 * [] Creation Date : 08-04-2015
 *
 * [] Last Modified : Wed 08 Apr 2015 12:46:08 PM IRDT
 *
 * [] Created By : Tara Tandel (Tara.tandel.94@gmail.com)
 * =======================================
*/
#include <stdio.h>
#include <stdlib.h>

#include "object.h"
#include "fknapsack.h"

int main(int argc, char *argv[])
{
	int i;
	int n, W;
	struct object *obj;

	scanf("%d", &n);
	obj = malloc(n * sizeof(struct object));
	for (i = 0; i < n; i++) {
		scanf("%d %d", &obj[i].weight, &obj[i].price);
		obj[i].density = obj[i].weight / obj[i].price;
		obj[i].index = i;
	}
	scanf("%d", &W);

	int n_out;
	struct object *obj_out;

	fknapsack(n, obj, W, &n_out, &obj_out);
	for (i = 0; i < n_out; i++)
		printf("%d %d\n", obj_out[i].index, obj_out[i].weight);

	free(obj);
	free(obj_out);
}
