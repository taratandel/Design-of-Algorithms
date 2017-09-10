/*
 * In The Name Of God
 * ========================================
 * [] File Name : object.h
 *
 * [] Creation Date : 08-04-2015
 *
 * [] Last Modified : Wed 08 Apr 2015 12:36:34 PM IRDT
 *
 * [] Created By : Tara Tandel (Tara.tandel.94@gmail.com)
 * =======================================
*/
#ifndef OBJECT_H
#define OBJECT_H

struct object {
	int weight;
	int price;
	int index;
	double density;
};

int object_cmp(const struct object *o1,
		const struct object *o2);

#endif
