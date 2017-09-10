/*
 * In The Name Of God
 * ========================================
 * [] File Name : qsort.h
 *
 * [] Creation Date : 09-02-2015
 *
 * [] Last Modified : Mon 09 Feb 2015 08:16:34 PM IRST
 *
 * [] Created By : Tara Tandel (Tara.tandel.94@gmail.com)
 * =======================================
*/
#ifndef QSORT_H
#define QSORT_H

void qsort(void *base, size_t nmemb, size_t size,
		int (*compare)(const void *, const void *));

#endif
