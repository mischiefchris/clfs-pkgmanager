#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {

char *line = NULL;
size_t len = -1;
int row_num = -1;

     FILE *fp = fopen("PKGBUILD", "r");
     if(fp == NULL) {
         perror("Unable to open file!");
         exit(1);
     }

     while(getline(&line, &len, fp) != -1) {
	row_num++;
        printf("|%d||%zd|%s\n", row_num, strlen(line), line);
	//printf("===|%s|\n", line);
     }

     printf("===|%zd|\n", len);

     fclose(fp);
     free(line);     // getline will resize the input buffer as necessary
                     // the user needs to free the memory when not needed!
}
