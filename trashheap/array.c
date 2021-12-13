#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFF 2056
#define FILENAME "PKGBUILD"

char data[BUFF];
char line[BUFF][BUFF];
char grid[BUFF][BUFF];
int i = 0;
int j = 0;

char *opensesame(){
char *mystr;
int c, n = 0;
FILE *fp = fopen(FILENAME, "r");
FILE *fptr = fopen(FILENAME, "r");
if(!fp) {
perror("File opening failed");
}
while ((c = fgetc(fp)) != EOF){
    data[n++] = c;
    mystr = data;
}
while(fgets(line[i], BUFF, fptr)){
        i++;
        line[i][strlen(line[i]) - 1] = '\0';
        }
    j = i;
    for (i = 0; i < j; ++i ){
    int width = strlen(line[i]) + 1;
    memcpy(grid[i], line[i], width);
    }

fclose(fp);
fclose(fptr);
return mystr;
}

void printgrid(){
int t = 0, l = 0;
for (t = 0; t < i; t++) {
        for (l = 0; l < j; l++) {
            printf("%c", grid[t][l]);
        }
    }
}

void printgrid_linenum(){
int lin = -1, x;
for (x = 0; x < i; x++) {
	lin++;
        printf("|%d|%d| %s", lin, strlen(grid[lin]), grid[lin]);
    }
}

int main(void){
    char *hello = opensesame();
    printgrid_linenum();
    //printf("%s", hello);
    return 0;
}
