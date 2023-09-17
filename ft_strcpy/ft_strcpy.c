#include <stdlib.h>

char    *ft_strcpy(char *s1, char *s2)
{
    int i = 0;
    if(!s2)
        return NULL;
    while(s2[i])
    {
        s1[i] = s2[i];
        i++;
    }
    return s1;
}