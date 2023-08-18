
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "data.h"
#include "array.h"
int main(int argc, char *argv[]) {
    data_t *d;
    char *s = NULL;
    assert(argc > 2);
    FILE *f = fopen(argv[2], "r");

    dataPrintHeader(f);  // get header line of data

    // Build dict as a linked list
    list_t ll = createList();
    while ((d = get_next_data(f))) {
        // print_data(d,stdout);
        ll = insert(d, ll);
    }
    fclose(f);

    // Search for key from file atgv[2]
    f = fopen(argv[3], "w");
    while ((s = read_field(stdin, NL))) {
        search(s, ll, f);
        free(s);
    }

    fclose(f);
    free_list(ll);
    freeHeader();
    return 0;
}

