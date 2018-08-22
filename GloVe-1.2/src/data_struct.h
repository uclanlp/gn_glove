//
// Created by zeyu on 2/1/18.
//

#include "const.h"

#ifndef GLOVE_1_2_DATA_STRUCT_H
#define GLOVE_1_2_DATA_STRUCT_H

typedef struct vocabulary {
    char *word;
    long long count;
} VOCAB;

typedef struct cooccur_rec {
    int word1;
    int word2;
    real val;
} CREC;

typedef struct cooccur_rec_id {
    int word1;
    int word2;
    real val;
    int id;
} CRECID;

#endif //GLOVE_1_2_DATA_STRUCT_H
