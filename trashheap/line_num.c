#include <stdio.h>

#define FILENAME "PKGBUILD"

char *strstr_func(char const* str, char const* substr){
char *pos = strstr(str, substr);
char opt[1028]; strcat(opt, pos);
char *pch = strtok(opt, " ");
printf("|%d", pos - str);
return pch;
}

char *find_str(char const* str, char const* substr){
      char* pos = strstr(str, substr);
      if(pos){
        printf("|%d", pos - str);
        }
      else{
        printf("");
        }
return str;
}

int main()
{
	FILE *fp;
	char ch[256];
	int count= -1;

	//open file in read more
	fp=fopen(FILENAME,"r");
	if(fp==NULL)
	{
		printf("File \"%s\" does not exist!!!\n",FILENAME);
		return -1;
	}

	//read character by character and check for new line	
	while (fgets(ch, sizeof ch, fp) != NULL ){
	count++;
	printf("|%d||%zd|%s", count, strlen(ch), ch);
	}

	//close the file
	fclose(fp);

	//print number of lines
	printf("Total number of lines are: %d\n",count);

	return 0;
}

