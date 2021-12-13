#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int sbuildy(char *str) {
	FILE *fp;
	int line_num = 1;
	int find_result = 0;
	char temp[512];
	char *buffer;

	fp = fopen("sbuildy", "r");
	while(fgets(temp, 512, fp) != NULL) {
		if((strstr(temp, str)) != NULL) {
			printf("line_number: %d\n", line_num);
			printf("\n%s\n", temp);
			find_result++;
		}
		line_num++;
	}

	if(find_result == 0) {
		printf("\nSorry!\n");
	}

	//Close the file if still open.
	if(fp) {
		fclose(fp);
	}
   	return(0);
}

//Our main function.
int main(int argc, char *argv[]) {
	int result, errno;
	system("clear");

	result = sbuildy("name");
	if(result == -1) {
		perror("Error");
		printf("Error number = %d\n", errno);
		exit(1);
	}
	return(0);
}
