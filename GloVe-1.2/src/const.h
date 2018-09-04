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
