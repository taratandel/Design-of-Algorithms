/*
 * In The Name Of God
 * ========================================
 * [] File Name : set.h
 *
 * [] Creation Date : 16-03-2015
 *
 * [] Last Modified : Mon 16 Mar 2015 01:45:39 AM IRST
 *
 * [] Created By : Tara Tandel (Tara.tandel.94@gmail.com)
 * =======================================
*/
#ifndef SET_H
#define SET_H

#include <stdint.h>

struct set {
	uint32_t set_t;
	int size;
};

struct set *set_new(void);

void set_add(struct set *S, int number);

void set_remove(struct set *S, int number);

int set_get(const struct set *S, int number);

void set_fprint(const struct set *S, FILE *stream);

void set_free(struct set *S);

void set_subset(const struct set *S, int k,
		struct set ***subsets, int *numbers);

#endif
