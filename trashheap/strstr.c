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

int compare(char *X, char *Y){
    while (*X && *Y){
        if (*X != *Y)
            return 0;
        X++;
        Y++;
    }
return (*Y == '\0');
}

// Function to implement strstr() function
char* seeker(char* X, char* Y){
    while (*X != '\0'){
        if ((*X == *Y) && compare(X, Y))
            return X;
        X++;
    }
    return NULL;
}

int main(){
opensesame();
printf("%s\n", pos);
printf("%s\n", dos);

return 0;
}
