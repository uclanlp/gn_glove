//
// Created by zeyu on 2/1/18.
//

//#include "data_struct.h"
//#include "const.h"

#ifndef GLOVE_1_2_COOCCUR_H
#define GLOVE_1_2_COOCCUR_H


typedef struct hashrec {
    char        *word;
    long long id;
    struct hashrec *next;
} HASHREC;

#endif //GLOVE_1_2_COOCCUR_H




HASHREC *hashsearch(HASHREC **ht, char *w);
unsigned int bitwisehash(char *word, int tsize, unsigned int seed);
int scmp( char *s1, char *s2);

