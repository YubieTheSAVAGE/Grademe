#include <stddef.h>

int search(char *str, char c)
{
    int i = 0;
    while(str[i])
    {
        if(str[i] == c)
            return 1;
        i++;
    }
    return 0;
}

size_t	ft_strcspn(const char *s, const char *reject)
{
    size_t i = 0;
    while(s[i])
    {
        if(search(reject, s[i]))
            return i;
        i++;
    }
    return i;
}