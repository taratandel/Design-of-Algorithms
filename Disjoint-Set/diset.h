/*
 * In The Name Of God
 * ========================================
 * [] File Name : diset.h
 *
 * [] Creation Date : 10-03-2015
 *
 * [] Last Modified : Tue 10 Mar 2015 01:27:24 AM IRST
 *
 * [] Created By : tara tandel (tara.tandel.94@gmail.com)
 * =======================================
*/
#ifndef DISET_H
#define DISET_H

struct diset {
	int *U;
	int number;
};

struct diset *diset_new(int number);
int diset_find(struct diset *d, int i);
int diset_merge(struct diset *d, int i, int j);
int diset_members(struct diset *d, int i);
void diset_delete(struct diset *d);

#endif
