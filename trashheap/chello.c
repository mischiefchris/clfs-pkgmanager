#include <stdio.h>
#include <string.h>

char *c_hello() {
  char *mystr = "Hello World!\n";
  return mystr;
  // return "this string";  // alterative
}

int main(void){
char *h = c_hello();
printf("%s", h);
return 0;
}
