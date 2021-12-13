#include <stdio.h>
#include <unistd.h>

#define char pkgname
#define char urlname
#define char tarballname

#define char loopwork

void Usage(char *filename) {
   printf("Usage: %s <file> <string>\n", filename);
   printf("%s version 1.0 \n", filename);
}

int main (int argc, char *argv[])
{

if(geteuid() != 0)
{
  msgerr("ROOT NEEDED!");
}

  int count;

  printf ("argv[0] = %s\n",argv[0]);

  if (argc > 1)
    {
      for (count = 1; count < argc; count++)
	{
	  printf("argv[%d] = %s\n", count, argv[count]);
	}
    }
  else
    {
      printf("The command had no other arguments.\n");
    }

  return 0;
}
