#include <stdio.h> 
#include <stdlib.h>
#include <syscall.h>
#include <unistd.h>
#include <fcntl.h>
#define STDIN  0
#define STDOUT 1
#define STDERR 2

char buf[BUFSIZ];

void filecopy(int fda, int fdb);

/* cat:  concatenate files, version 2 */ 
int main(int argc, char *argv[]) 
{ 
    FILE *fp; 
    char *prog = argv[0];  /* program name for errors */ 

    int fd;

    if (argc == 1 ) /* no args; copy standard input */ 
        filecopy(STDIN, STDOUT); 
    else 
        while (--argc > 0) {
            if ((fd = open(*++argv, O_RDONLY, 0)) == -1) { 
                fprintf(stderr, "%s: can't open %s\n", prog, *argv); 
                exit(1); 
            } else { 
                filecopy(fd, STDOUT); 
                close(fd); 
            }
        }
    /* if (ferror(stdout)) { */ 
    /*     fprintf(stderr, "%s: error writing stdout\n", prog); */ 
    /*     exit(2); */ 
    /* } */ 
    exit(0); 
} 

/* filecopy:  copy file ifp to file ofp */ 
void filecopy(int fda, int fdb) 
{ 
    size_t n;
    if ((n = read(fda, buf, BUFSIZ)) > 0)
        write(fdb, buf, n);
} 
