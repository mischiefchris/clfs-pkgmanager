#include <string.h>
#include <stdio.h>

char *search(char const* str, char const* substr){
char *pos = strstr(str, substr);
char opt[1028]; strcat(opt, pos);
char *pch = strtok(opt, " ");
//printf("%s", pch); // debugging printf
return pch;
}

int main(void){
    //FILE *fptr = fopen("PKGBUILD", "r");
    char *result;
    char *str = "fffffff pkgname=file fffffff";
    
    result = search(str, "pkgname=");
    printf("minipkg found: %s \n", result);
    return 0;
}

