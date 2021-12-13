#include "minipkg.h"

FILE *fptr;

long datalength;
char *data = 0;
int pkgbool = 0;
char *pkgi;
char *veri;

// create a duplicate of buildscript: src
char *datadup(char *dupi) {
    char *dp = malloc(strlen(dupi) + 1);
    if (dp == NULL) { return NULL; }
    strcpy(dp, dupi);
    return dp;
}

// remove tokken from string: str, tokken
void rmtok(char *X, char *Y) {
  char *m;
  int len = strlen(Y);
  while ((m = strstr(X, Y))) {
    *m = '\0';
    strcat(X, m+len);
    }
}

// replace one string at a time: src, str, new
void repl(char *X, char *Y, char *Z){
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

// replace all matching strings: src, str, new
void replall(char *X, char *Y, char *Z){
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
    replall(w+strlen(Z), Y, Z);
    }
  }
}

// strips string of delimiters: str, strip item
void stripstr(char *X, char *Y){
  rmtok(X, Y);
  rmtok(X, "'");
  rmtok(X, "\"");
  rmtok(X, "(");
  rmtok(X, ")");
  rmtok(X, "{");
  rmtok(X, "}");
  rmtok(X, ",");
}

char *strstrstrip(char *x, char *y){
  char *dup = datadup(data);
  char *xy = strstr(dup, x);
  if(!xy){
  return strdup("");
  } else {
  strtok(xy, "\n");
  stripstr(xy, y);
  }
return xy;
}

char *pkgname(){
pkgi = strstrstrip(PKG, PKG);
stripstr(pkgi, PKG);
  if(!pkgi){
    printf("%s not found!\n", PKG);
    printf("ERROR: Please follow building guide...\n");
    exit(EXIT_FAILURE);
  }
  if(strlen(pkgi) == FALSE){
    printf("%s not readable!\n", PKG);
    printf("ERROR: Please follow building guide...\n");
    exit(EXIT_FAILURE);
  }
return pkgi;
}

char *version(){
veri = strstrstrip(VER, VER);
  if(!veri){
  return strdup("");
  } else {
  stripstr(veri, VER);
  }
return veri;
}

char *openfile(){
fptr = fopen(FILENAME, "rb");
if(!fptr){
  printf("ERROR: %s not found!\n", FILENAME);
  printf("ERROR: Please follow building guide...\n");
  exit(EXIT_FAILURE);
  } else{
  printf("FOUND: %s \n", FILENAME);
  fseek(fptr, 0, SEEK_END);
  datalength = ftell(fptr);
  fseek(fptr, 0, SEEK_SET);
  data = malloc(datalength);
  if(data)
  {
    fread(data, 1, datalength, fptr);
  }
  fclose(fptr);
}

if(data){
  // error: if minimal info field are not found
}
return data;
}

int main(void){
openfile();
pkgname();

//char *b = strstrstrip("version=", VER);
//char *c = strstrstrip("release=", REL);
//char *d = strstrstrip("epoch=", EPH);
return 0;
}
