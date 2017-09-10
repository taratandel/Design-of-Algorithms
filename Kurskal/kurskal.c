/*
 * In The Name Of God
 * ========================================
 * [] File Name : kurskal.c
 *
 * [] Creation Date : 10-03-2015
 *
 * [] Last Modified : Tue 10 Mar 2015 01:24:15 AM IRST
 *
 * [] Created By : Tara Tandel (Tara.tandel.94@gmail.com)
 * =======================================
*/
#include <stdlib.h>

#include "edge.h"
#include "diset.h"
#include "kurskal.h"

static int edge_cmp_v(const void* a,const void* b)
{
	return edge_cmp((const struct edge *)a,
			(const struct edge *)b);
}

int kurskal(int E, int V, const struct edge *edges,
		int *out_E, struct edge **out_edges)
{
	struct edge *edges_new;
	int i;
	int min_weight=0;
	struct diset *d;
	
	d = diset_new(V);

	edges_new = malloc(sizeof(struct edge) * E);
	for (i = 0; i < E; i++)
		edges_new[i] = edges[i];

	*out_edges = malloc(sizeof(struct edge) * E);
	
	*out_E = 0;

	qsort(edges_new, E, sizeof(struct edge), edge_cmp_v);	
	
	for (i = 0; i < E; i++) {
		if (diset_merge(d, edges_new[i].start, edges_new[i].end)) {
			min_weight += edges_new[i].weight;
			(*out_edges)[*out_E] = edges_new[i];
			(*out_E)++;
		}
	}

	free(edges_new);
	diset_delete(d);

	return min_weight;
}
