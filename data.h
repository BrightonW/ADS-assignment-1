#ifndef _DATA_H_
#define _DATA_H_

//#include "utils.h"

#define C ','     
#define Q '\"'   
#define NL '\n' 

#define MAX_LEN 128

// Note: it's more convenient to typedef data_t as char**
//       but the requirement is to use struct ;-(
typedef struct {
	char *cyear, *block_id, *prop_id, *base_id;  // 0-3
	char *build_add, *c_s_a; *biz_add;   // 4, 5
	char *t_name; *code;                     // 6
	char *desc;                     // 7
	char *x, *y;                    // 8,9
	char *loc;                      // 10;
} data_t;

typedef struct {
    int cyear;
    int block_id;
    int prop_id;
    int base_id;
    char build_add[256];
    char c_s_a[256];
    char biz_add[256];
    char t_name[256];
    int i_code;
    char i_desc[256];
    char seat_type[256];
    int num_seats;
    double longitude;
    double latitude;
}data_t;

void print_data(data_t *d, FILE *f);  // print a data to file f
void free_data(data_t *d);            // 
data_t *get_next_data(FILE *f);       // return a next record read from f

void data_get_header(FILE *f);       // get rid off & and store header for late use
void data_free_header();             // free the sored header

char *getfield(FILE *f, char deli);  // get a next field from file f
#endif
