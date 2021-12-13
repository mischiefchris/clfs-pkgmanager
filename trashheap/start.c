#include <stdio.h>
#include <unistd.h>

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

#define msg(X) printf("%s==> %s %s \n",ANSI_COLOR_GREEN,X,ANSI_COLOR_RESET)
#define msginst(Y) printf("%s %s %s \n",ANSI_COLOR_GREEN,Y,ANSI_COLOR_RESET)
#define msgmiss(Z) printf("%s==> %s %s \n",ANSI_COLOR_YELLOW,Z,ANSI_COLOR_RESET)
#define msgnoinst(T) printf("%s - %s %s \n",ANSI_COLOR_CYAN,T,ANSI_COLOR_RESET)
#define msgerr(U) printf("%s==> ERROR: %s %s \n",ANSI_COLOR_RED,U,ANSI_COLOR_RESET)
#define msgwarn(V) printf("%s==> WARNING :%s %s \n",ANSI_COLOR_YELLOW,V,ANSI_COLOR_RESET)

void Usage() {
   printf("Usage: <file> <string>\n");
   printf("version 1.0 \n");
}

int main(void) {
Usage();
return 0;
}










