/*
 * In The Name Of God
 * ========================================
 * [] File Name : kurskal.h
 *
 * [] Creation Date : 10-03-2015
 *
 * [] Last Modified : Tue 10 Mar 2015 01:21:24 AM IRST
 *
 * [] Created By : Tara Tandel (Tara.tandel.94@gmail.com)
 * =======================================
*/
#ifndef KURSKAL_H
#define KURSKAL_H

#include "edge.h"

int kurskal(int E, int V, const struct edge *edges,
		int *out_E, struct edge **out_edges);

#endif
