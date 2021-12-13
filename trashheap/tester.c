#include "pkgd.h"

FILE *fptr;
long length;
char *data = 0;

char *openfile(){
fptr = fopen(FILENAME, "rb");
if(fptr){
  fseek(fptr, 0, SEEK_END);
  length = ftell(fptr);
  fseek(fptr, 0, SEEK_SET);
  data = malloc(length);
  if(data)
  {
    fread(data, 1, length, fptr);
  }
  fclose(fptr);
}

if(data){


  //printf("%s", ver);
}
return data;
}

// remove tokken from string str, tokken
void rmtok(char *X, char *Y) {
  char *m;
  int len = strlen(Y);
  while ((m = strstr(X, Y))) {
    *m = '\0';
    strcat(X, m+len);
    }
}

// replace one string at a time src, str, new
void rplstr(char *X, char *Y, char *Z){
     char *q;
     if ((q = strstr(X, Y)) == NULL) {
         return;
     }
     int y_len = strlen(Y);
     int z_len = strlen(Z);
     int t_len = strlen(q+y_len);
     memmove(q+z_len,q+y_len,t_len+1);
     memcpy(q, Z, z_len);
}

// replace all src, str, new
void strmagic(char *X, char *Y, char *Z){
char *w = strstr(X, Y);
  if(w){
  int len = strlen(X)+strlen(Z)-strlen(Y);
  char r[len];
  memset(r, 0, len);
    if(w >= X){
    strncpy(r, X, w-X);
    r[w-X]='\0';
    strncat(r, Z, strlen(Z));
    strncat(r, w+strlen(Y), w+strlen(Y)-X+strlen(X));
    strcpy(X, r);
    strmagic(w+strlen(Z), Y, Z);
    }
  }
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
char *seeker(char *X, char *Y){
    while (*X != '\0'){
        if ((*X == *Y) && compare(X, Y))
            return X;
        X++;
    }
    return NULL;
}

int main(void){
char *a = openfile();
char *b = seeker(a, "pkgname=");
strtok(b, "\n");
char *chh = seeker(b, "pkgver=");
printf("%s", chh);
return 0;
}
