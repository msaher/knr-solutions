#include "hashtable.h"

struct nlist {       /* table entry: */ 
    struct nlist *next;   /* next entry in chain */ 
    char *name;           /* defined name */ 
    char *defn;           /* replacement text */ 
}; 

static struct nlist *hashtab[HASHSIZE];  /* pointer table */ 

/* hash: form hash value for string s */
unsigned hash(char *s)
{
    unsigned hashval;
    for (hashval = 0; *s != '\0'; s++)
        hashval = *s + 31 * hashval;
    return hashval % HASHSIZE;
}

struct nlist *lookup(char *);

/* lookup: look for s in hashtab */
struct nlist *lookup(char *s)
{
    struct nlist *np;
    for (np = hashtab[hash(s)]; np != NULL; np = np->next)
        if (strcmp(s, np->name) == 0)
            return np;
    /* found */
    return NULL;
    /* not found */
}

/* install: put (name, defn) in hashtab */
struct nlist *install(char *name, char *defn)
{
    struct nlist *np;
    unsigned hashval;
    if ((np = lookup(name)) == NULL) { /* not found */
        np = (struct nlist *) malloc(sizeof(*np));
        if (np == NULL || (np->name = strdup(name)) == NULL)
            return NULL;
        hashval = hash(name);
        np->next = hashtab[hashval]; /* saher: Add to head (in case of hash conflict). */
        hashtab[hashval] = np;
    } else
        /* already there */
        free((void *) np->defn);
    /*free previous defn */
    if ((np->defn = strdup(defn)) == NULL)
        return NULL;
    return np;
}

void freenp(struct nlist* np)
{
    free(np->defn);
    free(np->name);
    free(np);
}

/* install: put (name, defn) in hashtab */
void undef(char *name)
{
    struct nlist *np;
    struct nlist *prev = NULL;
    int hashval = hash(name);
    for(np = hashtab[hashval]; np != NULL && strcmp(name, np->name) != 0; prev = np, np = np->next)
        ;
    
    if(np == NULL) /* not found */
        return;

    if(prev == NULL) /* np was the head */
        hashtab[hashval] = np->next;
    else {
        prev->next = np->next;
        hashtab[hashval] = prev;
    }
    freenp(np);
}

void printhash(void)
{
    struct nlist* np;
    for(int i = 0; i < HASHSIZE; i++) {
        if((np = hashtab[i]) == NULL)
            continue;
        printf("Hash index = %d\n", i);
        do {
            printf("\tName: %s. Defn: %s\n", np->name, np->defn);
        } while((np = np->next) != NULL);
    }
}
