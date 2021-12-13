#include <stdio.h>
#include <string.h>
 
int main(void)
{
    char str[] = "pkgname=file fffff";
    char *ps = memchr(str,'=',strlen(str));
    if (ps != NULL)
       printf ("search character found:  %s\n", ps);
    else
       printf ("search character not found\n");
 
    return 0;
}
