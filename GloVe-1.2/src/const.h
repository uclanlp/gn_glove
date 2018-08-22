#ifndef __CONST_H__
#define __CONST_H__

typedef double real;

#define TSIZE	1048576
#define SEED	1159241

#define _FILE_OFFSET_BITS 64
#define MAX_STRING_LENGTH 1000
#define MAX_WORD_LENGTH 50
#define MAX_WORD_COUNT 300

#define HASHFN bitwisehash
unsigned int bitwisehash(char *word, int tsize, unsigned int seed);
#endif