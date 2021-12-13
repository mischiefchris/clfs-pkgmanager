#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// also scanf a char[256] look into
void compare( char str1[], char str2[]){
int l1,l2,i;
l1=strlen(str1);
l2=strlen(str2);
if(l1!=l2){
     printf("string %s and string %s are not equal\n",str1,str);
}
else{
        for( i = 0; i < l1 ; i++){   // l1 or l2 anyone as both are equal.
                if(str1[i]!=str2[i]){
                     printf("string %s and string %s are not equal\n",str1,str);
                     break;
                }
       }
       if(i==l1){      //if the for loop has ran for the whole l1 lenth.
               printf("string %s and string %s are equal\n",str1,str);
       }
    }
}
