#include "pkgmini.h"

FILE *fptr;

long datalength;
char *data = 0;

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
return data;
}

int main(void){
openfile();
printf(data);
//pkgname();
//char *b = strstrstrip("version=", VER);
//char *c = strstrstrip("release=", REL);
//char *d = strstrstrip("epoch=", EPH);
return 0;
}
