#ifndef LLIST
#define LLIST
struct lnode {
    int data;
    struct lnode *next;
};

struct sllist {
    struct lnode *head;
    struct lnode *tail;
};

struct lnode* lnalloc(void);
struct sllist* sllalloc(void);
void addtohead(struct sllist *list, int data);
void addtotail(struct sllist *list, int data);
void listprint(struct sllist *list);
#endif
