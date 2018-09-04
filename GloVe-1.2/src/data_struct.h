//   Copyright 2018 University of California, Los Angeles
//
//   Licensed under the Apache License, Version 2.0 (the "License");
//   you may not use this file except in compliance with the License.
//   You may obtain a copy of the License at
//
//       http://www.apache.org/licenses/LICENSE-2.0
//
//   Unless required by applicable law or agreed to in writing, software
//   distributed under the License is distributed on an "AS IS" BASIS,
//   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//   See the License for the specific language governing permissions and
//   limitations under the License.
//
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
