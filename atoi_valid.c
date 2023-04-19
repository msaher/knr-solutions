int atoi_valid(char *s, int *np);

/* atoi_valid:  Like atoi, but return 0 when the string can't entirely
 * be converted to an integer.
 * Preseves the old value of *np on failure */
int atoi_valid(char *s, int *np)
{
    if(*s == '\0')
        return 0;

    int oldn = *np;
    *np = 0; /* start fresh */
    short sign = (*s == '-') ? -1 : 1; 
    if(*s == '-' || *s =='+')
        s++;

    while(*s != '\0') {
        if(!isdigit(*s))
            break;
        else
            *np = 10.0 * *np + (*s++ - '0'); /* do what atoi would normally do */
    }

    if(*s == '\0') {
        *np *= sign;
        return 1; /* Success */
    }
    else { /* Not an integer */
        *np = oldn;
        return 0;
    }
}

