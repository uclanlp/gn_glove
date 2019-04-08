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
// Created by jieyu on 2/5/18.
//

#include  <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_STRING_LENGTH 1000

#include "temp.h"
#include "const.h"
#include "cooccur.h"

/* Efficient string comparison */
int scmp( char *s1, char *s2 ) {
    while(*s1 != '\0' && *s1 == *s2) {s1++; s2++;}
    return(*s1 - *s2);
}

/* Move-to-front hashing and hash function from Hugh Williams, http://www.seg.rmit.edu.au/code/zwh-ipl/ */

/* Simple bitwise hash function */
unsigned int bitwisehash(char *word, int tsize, unsigned int seed) {
    char c;
    unsigned int h;
    h = seed;
    for(; (c =* word) != '\0'; word++) h ^= ((h << 5) + c + (h >> 2));
    return((unsigned int)((h&0x7fffffff) % tsize));
}

/* Create hash table, initialise pointers to NULL */
HASHREC ** inithashtable() {
    int	i;
    HASHREC **ht;
    ht = (HASHREC **) malloc( sizeof(HASHREC *) * TSIZE );
    for(i = 0; i < TSIZE; i++) ht[i] = (HASHREC *) NULL;
    return(ht);
}

/* Search hash table for given string, return record if found, else NULL */
HASHREC *hashsearch(HASHREC **ht, char *w) {
    HASHREC	*htmp, *hprv;
    unsigned int hval = HASHFN(w, TSIZE, SEED);
    for(hprv = NULL, htmp=ht[hval]; htmp != NULL && scmp(htmp->word, w) != 0; hprv = htmp, htmp = htmp->next);
    if( htmp != NULL && hprv!=NULL ) { // move to front on access
        hprv->next = htmp->next;
        htmp->next = ht[hval];
        ht[hval] = htmp;
    }
    return(htmp);
}

/* Insert string in hash table, check for duplicates which should be absent */
void hashinsert(HASHREC **ht, char *w, long long id) {
    HASHREC	*htmp, *hprv;
    unsigned int hval = HASHFN(w, TSIZE, SEED);
    // hprv stands for hash table previous ptr
    for(hprv = NULL, htmp = ht[hval]; htmp != NULL && scmp(htmp->word, w) != 0; hprv = htmp, htmp = htmp->next);
    if(htmp == NULL) {
        htmp = (HASHREC *) malloc(sizeof(HASHREC));
        htmp->word = (char *) malloc(MAX_STRING_LENGTH);
        strcpy(htmp->word, w);
        htmp->id = id;
        htmp->next = NULL;
        if(hprv == NULL) ht[hval] = htmp;
        else hprv->next = htmp;
    }
    else fprintf(stderr, "Error in get_vocabhash.c, duplicate entry located: %s.\n",htmp->word);
    return;
}

HASHREC **get_vocabhash(char *filename){
    FILE *fin;
    fin = fopen(filename, "rb");
    HASHREC2 *vocab_unit = (HASHREC2 *)malloc(sizeof(HASHREC2));
    HASHREC **vocab_hash = inithashtable();
    
    while(fread(vocab_unit, sizeof(HASHREC2), 1, fin)){
        hashinsert(vocab_hash, vocab_unit->word, vocab_unit->id);
    }
//    int i = 0;
//     for(i=0; i< 100; i++){
//         HASHREC *htmp=vocab_hash[i];
//         while(htmp!= NULL){
//             printf("%s\t%llu\n", htmp->word, htmp->id);
//             htmp = htmp->next;
//         }

//     }
    // printf("%llu",hashsearch(vocab_hash, (char *)"tracked")->id);
    fclose(fin);
    return vocab_hash;
}
