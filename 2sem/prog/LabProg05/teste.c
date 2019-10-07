#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int t = 10;
    char* s = (char*) malloc (t*sizeof(char));
    for (int i = 0; i < 4; ++i)
    {
        printf("s[%d]: ", i);
        scanf(" %c", &s[i]);
    }
    s[5] = '\0';
    s[6] = 'f';
    int tam = strlen(s);
    printf("%d", tam);
    // char *item = s;
    // do
    // {
    // printf("%c ", *item);
    // ++item;
    // } while (*item != '\0');
}