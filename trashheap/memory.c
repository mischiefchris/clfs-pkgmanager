#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char * buffer = 0;
long length;
FILE * f = fopen (filename, "rb");

if (f)
{
  fseek (f, 0, SEEK_END);
  length = ftell (f);
  fseek (f, 0, SEEK_SET);
  buffer = malloc (length);
  if (buffer)
  {
    fread (buffer, 1, length, f);
  }
  fclose (f);
}

if (buffer)
{
  // start to process your data / extract strings here...
}

void sbuildy(){
FILE    *infile;
char    *buffer;
long    numbytes;
infile = fopen("PKGBUILD", "r");
if(infile == NULL)
    printf("\nERROR\n");
fseek(infile, 0L, SEEK_END);
numbytes = ftell(infile);
fseek(infile, 0L, SEEK_SET);
buffer = (char*)calloc(numbytes, sizeof(char));
if(buffer == NULL)
    printf("\nERROR\n");
fread(buffer, sizeof(char), numbytes, infile);
fclose(infile);
printf("\n%s\n", buffer);
char *ps = strstr(buffer, "pkgname");
printf("\n%s\n", ps);
}

int main(void){
sbuildy();
free(buffer);
return 0;
}
