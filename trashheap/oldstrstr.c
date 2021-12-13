#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/* Write C code to implement the strstr() function to search for a substring */
char* StrStr(char *str, char *substr){
while (*str)
	{
	char *Begin = str;
	char *pattern = substr;
	// If first character of sub string match, check for whole string
	while (*str && *pattern && *str == *pattern)
		{
		str++;
		pattern++;
		}
		// If complete sub string match, return starting address
		if (!*pattern)
		return Begin;
		str = Begin + 1;// Increament main string
	  }
	  return NULL;
}

/* Main Method */
int main(){
char s1 [] = "This is www.firmcodes.com";
printf ("Returned String 1: %s\n", StrStr(s1, "firmcodes"));

return 0;
}
