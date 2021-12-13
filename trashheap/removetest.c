#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void removeSubstr (char *string, char *sub) {
        char *match;
        int len = strlen(sub);
        while ((match = strstr(string, sub))) {
                *match = '\0';
                strcat(string, match+len);
        }
}

void sbuildy(char *str) {
	FILE *fp;
	int line_num = 1;
	int find_result = 0;
	char temp[512];
	char *buffer;

	fp = fopen("PKGBUILD", "r");
	while(fgets(temp, 512, fp) != NULL) {
		if((strstr(temp, str)) != NULL) {
			//printf("line_number: %d\n", line_num);

removeSubstr(temp, "pkgname=");
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
}

//Our main function.
int main(int argc, char *argv[]) {
	system("clear");

	sbuildy("pkgname=");
	return 0;
}
