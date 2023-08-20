#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "data.h"
#include<ctype.h>

#define KEY_INDEX 7
#define Q '\"'
char *header[FIELDS];  //header storing

// function definition
void dataPrintHeader(FILE *file){
    int i;
    for(i = 0; i < FIELDS - 1; i++){
        header[i] = read_field(file,C);        
    }
    header[i]= read_field(file,NL);
}
void printData(FILE *file, data_t *data){
   /* for(int i=0;i<FIELDS;i++){
        fprintf(file, "%s: %s || ", header[i], data->header[i]); //cyear);
    }
        fprintf(file, "\n");
}*/
    fprintf(file, "%s: %s || ", header[0], data->cyear);
    fprintf(file, "%s: %s || ", header[1], data->block_id);
    fprintf(file, "%s: %s || ", header[2], data->prop_id);
    fprintf(file, "%s: %s || ", header[3], data->base_id);
    fprintf(file, "%s: %s || ", header[4], data->build_add);
    fprintf(file, "%s: %s || ", header[5], data->c_s_a);
    fprintf(file, "%s: %s || ", header[6], data->biz_add);
    fprintf(file, "%s: %s || ", header[7], data->t_name);
    fprintf(file, "%s: %s || ", header[8], data->i_code);
    fprintf(file, "%s: %s || ", header[9], data->i_desc);
    fprintf(file, "%s: %s || ", header[10], data->seat_type);
    fprintf(file, "%s: %s || ", header[11], data->num_seats);
    fprintf(file, "%s: %s || ", header[12], data->longi);
    fprintf(file, "%s: %s || ", header[13], data->lat);

    fprintf(file, "\n");
}
void freeHeader(){
    for(int i=0;i<FIELDS;i++){
        free(header[i]);
    }
}
/*int scopy(char *t, const char *s, char deli) {
    while (*s && *s != deli) {
        if (*s == '\"') {
            // Check for consecutive double-quote characters
            if (*(s + 1) == '\"') {
                *t++ = '\"';
                s += 2;
            } else {
                break;
            }
        } else {
            *t++ = *s++;
        }
    }
    *t = '\0';

    if (*s == '\"' && *(s + 1) != '\"') {
        return 0;
    }
    
    return 1;
}*/

char *read_field(FILE *f, char deli) {
    char *result = NULL;
    char buffer[FIELD_LEN];
    size_t result_len = 0;

    while (1) {
        int c = fgetc(f);
        if (c == EOF || c == deli || c == '\n') {
            buffer[result_len] = '\0';
            result = realloc(result, result_len + 1);
            if (result == NULL) {
                perror("Memory allocation error");
                exit(EXIT_FAILURE);
            }
            strcat(result, buffer);
            if (c == deli || c == '\n' || c == EOF) {
                return result;
            }
            result_len = 0;
        } else if (c == Q) {
            int cont = 1;
            while (cont) {
                c = fgetc(f);
                if (c == Q) {
                    cont = 0;
                } else if (c == EOF) {
                    perror("Unexpected EOF");
                    exit(EXIT_FAILURE);
                } else {
                    buffer[result_len] = c;
                    result_len++;
                    if (result_len >= FIELD_LEN - 1) {
                        fprintf(stderr, "Field too long\n");
                        exit(EXIT_FAILURE);
                    }
                }
            }
        } else {
            buffer[result_len] = c;
            result_len++;
            if (result_len >= FIELD_LEN - 1) {
                fprintf(stderr, "Field too long\n");
                exit(EXIT_FAILURE);
            }
        }
    }

    return result;
}

data_t *get_next_data(FILE *f) {
    char *s = read_field(f, C);
    if (!s) return NULL;

    data_t *d = (data_t *)malloc(sizeof(data_t));
    if (!d) {
        perror("Memory allocation error");
        exit(EXIT_FAILURE);
    }
    d->cyear = s;
    d->block_id = read_field(f, C);
    d->prop_id = read_field(f, C);
    d->base_id = read_field(f, C);
    d->build_add = read_field(f, C);
    d->c_s_a = read_field(f, C);
    d->biz_add = read_field(f, C);
    d->t_name = read_field(f, C);
    d->i_code = read_field(f, C);
    d->i_desc = read_field(f, C);
    d->seat_type = read_field(f, C);
    d->num_seats = read_field(f, C);
    d->longi = read_field(f, C);
    char *line = read_field(f, NL);
    d->lat = line;

    return d;
}

void freeData(data_t *data) {
    // Free each fieldata in a loop
    char *dataSet[] = { data->cyear, data->block_id, data->prop_id, data->base_id, data->build_add,
                      data->c_s_a, data->biz_add, data->t_name, data->i_code, data->i_desc, data->seat_type,
                      data->num_seats, data->longi, data->lat };

    for (int i = 0; i < sizeof(dataSet) / sizeof(dataSet[0]); i++) {
        free(dataSet[i]);
    }

    free(data);
}


/*char *my_strdup(char *str) {
    size_t len=strlen(str);
	char *new_str= (char*)malloc(len+1);
    if(newstr){
        strcpy(newstr,str);
    }
	return new_str;
}*/
