struct tnode; 

void treeprint(struct tnode *p);
struct tnode *addtree(struct tnode *p, char *w);
struct tnode* addtreeif(struct tnode *p, char *w, int (*cond)(char*));
