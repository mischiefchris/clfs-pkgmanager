#include <stdio.h>
#include <string.h>

int main(){
FILE *fp;
char filename[]="PKGBUILD";
char line[512];
char search_string[] = "pkgname";
fp=fopen(filename,"r");
if(!fp)
{
perror("could not find the file");
}
while ( fgets ( line, 200, fp ) != NULL ) /* read a line */
{
if(strstr(line,search_string))
  fputs ( line, stdout ); /* write the line */
}
   fclose ( fp );
   return 0;
}
