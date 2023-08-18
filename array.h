/*
copied from FOUNDATION OF ALGORITHMS listops.c 
https://people.eng.unimelb.edu.au/ammoffat/ppsaa/c/listops.c
*/
#ifndef _ARRAY_
#define _ARRAY_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "data.h"

typedef struct node node_t;

struct node {
	data_t *d;
	node_t *next;
};

typedef node_t *list_t;

list_t createList(); 
list_t insert(data_t *d, list_t l);
void search(char *key, list_t l, FILE *f);
void free_list(list_t l);
void *my_malloc(size_t n);
#endif
