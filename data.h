#ifndef _DATA_H_
#define _DATA_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <ctype.h>

#define NL '\n' 
#define FIELDS 14

#define FIELD_LEN 128
struct data {
	char *cyear,*block_id,*prop_id;
	char *base_id;
	char *build_add, *c_s_a, *biz_add;
	char *t_name;
	char *i_code,*i_desc;
	char *seat_type,*num_seats;
	char *longi,*lat;
};
typedef struct data data_t;
void dataPrintHeader(FILE *file);       // get rid off & and store header for late use
void printData(FILE *file, data_t *data);
void freeHeader();
char *read_field(FILE *f, char deli);
data_t *get_next_data(FILE *f);
void freeData(data_t *data);
#endif
