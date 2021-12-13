
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
#include <stdio.h>
 
// Recursive function to implement strstr() function
const char* strstr(const char* X, const char* Y)
{
    if (*Y == '\0')
        return X;
 
    for (int i = 0; i < strlen(X); i++)
    {
        if (*(X + i) == *Y)
        {
            char* ptr = strstr(X + i + 1, Y + 1);
            return (ptr) ? ptr - 1 : NULL;
        }
    }
 
    return NULL;
}
 
// Implement strstr function in C
int main()
{
    char *X = "Techie Delight - Coding made easy";
    char *Y = "Coding";
 
    printf("%s\n", strstr(X, Y));
 
    return 0;
}
