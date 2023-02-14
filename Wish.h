#ifndef WISH_H
#define WISH_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define WISH_MAX_INPUT 1000
#define WISH_DEFAULT_PROMPT "wish> "

char *wish_read_line(FILE *in);
int wish_read_config(char *fname, int ok_if_missing);

#endif /* WISH_H */

