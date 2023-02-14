// wish_read.c
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "wish.h"

char *wish_read_line(FILE *in) {
char *line = NULL;
size_t len = 0;
ssize_t read = getline(&line, &len, in);
if (read == -1) {
perror("wish: error reading line");
return NULL;
}
if (read > WISH_MAX_INPUT) {
fprintf(stderr, "wish: line too long\n");
return NULL;
}
// Check if the line is blank or consists only of white spaces
int blank = 1;
for (int i = 0; i < read; i++) {
if (!isspace(line[i])) {
blank = 0;
break;
}
}
if (blank) {
return NULL;
}
// Remove the newline character from the line
line[read-1] = '\0';
return line;
}

int wish_read_config(char *fname, int ok_if_missing) {
FILE *fp = fopen(fname, "r");
if (!fp) {
if (!ok_if_missing) {
perror("wish: error opening file");
return 1;
}
return 0;
}
char *line;
while ((line = wish_read_line(fp)) != NULL) {
// Do something with the line
free(line);
}
if (fclose(fp) != 0) {
perror("wish: error closing file");
return 1;
}
return 0;
}

// wish.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "wish.h"

int main(int argc, char *argv[]) {
char *home = getenv("HOME");
if (!home) {
perror("wish: error reading $HOME");
return EXIT_FAILURE;
}
// Construct the full path to the config file
char fname[strlen(home) + strlen("/wish.conf") + 1];
strcpy(fname, home);
strcat(fname, "/wish.conf");
// Read the config file
if (wish_read_config(fname, 1) == 1) {
return EXIT_FAILURE;
}
// Read commands from stdin
printf("%s", WISH_DEFAULT_PROMPT);
char *line;
while ((line = wish_read_line(stdin)) != NULL) {
// Do something with the command
free(line);
printf("%s", WISH_DEFAULT_PROMPT);
}
return EXIT_SUCCESS;
}
