/*
 * In The Name Of God
 * ========================================
 * [] File Name : object.c
 *
 * [] Creation Date : 08-04-2015
 *
 * [] Last Modified : Wed 08 Apr 2015 12:30:02 PM IRDT
 *
 * [] Created By : Tara Tandel (Tara.tandel.94@gmail.com)
 * =======================================
*/
#include "object.h"

int object_cmp(const struct object *o1,
		const struct object *o2)
{
	return o1->density - o2->density;
}
