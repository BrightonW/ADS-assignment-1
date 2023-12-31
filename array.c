#include "array.h"
list_t createList() {
	return NULL;
}

// insert at start
list_t insert(data_t *d, list_t l) {
    node_t *node = (node_t *)malloc(sizeof(*node));
    if (node == NULL) {
        perror("Memory allocation error");
        exit(EXIT_FAILURE);
    }
    node->d = d;
    node->next = l;
    return node;
}

void search(char *key, list_t l, FILE *f) {
	int n=0;
	node_t *p= l;
	// printf("search for [%s]\n",key);
	while (p != NULL) {
		if (strcmp(p->d->t_name,key)==0) {
			n++;
			fprintf(f, "%s --> ", key);
			printData(f,p->d);
		}
        	p= p->next;
	}
	if (n==0) fprintf(f, "%s --> NOT FOUND\n", key);
}


void free_list(list_t l){
	node_t *p= l;
	while (p != NULL) {
		node_t *t= p;
		p= p->next;
		freeData(t->d);
		free(t);
	}
}


