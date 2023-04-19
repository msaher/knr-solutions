#ifndef HASH
#define HASH
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define HASHSIZE 101 

unsigned hash(char *s);
struct nlist *lookup(char *);
struct nlist *install(char *name, char *defn);
void freenp(struct nlist* np);
void undef(char *name);
void printhash(void);
#endif
