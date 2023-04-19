struct tnode {     /* the tree node: */ 
    char *word;           /* points to the text */ 
    int count;            /* number of occurrences */ 
    struct tnode *left;   /* left child */ 
    struct tnode *right;  /* right child */ 
}; 

void treeprint(struct tnode *p);
struct tnode *addtree(struct tnode *p, char *w);
struct tnode* addtreeif(struct tnode *p, char *w, int (*cond)(char*));
