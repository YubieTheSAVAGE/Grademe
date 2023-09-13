#include <stdlib.h>

int is_space(char c)
{
    return (c == ' ' || c == '\t' || c == '\n');
}

int count_words(char *str)
{
    int count = 0;
    int i = 0;
    while(str[i])
    {
        if(!is_space(str[i]) && (is_space(str[i+1]) || str[i+1] == '\0') )
            count++;
        i++;
    }
    return count;
}

char *world_alloc(char *str)
{
    int i = 0;
    char *word;

    while(str[i] && !is_space(str[i]))
        i++;
    word = malloc((i + 1) * sizeof(char));
    i = 0;
    while(str[i] && !is_space(str[i]))
    {
        word[i] = str[i];
        i++;
    }
    word[i] = '\0';
    return word;
}

char    **ft_split(char *str)
{
    int i = 0;
    int wc = count_words(str);
    char **result;

    result = malloc((wc + 1) * sizeof(char *));
    while(*str)
    {
        while(*str && is_space(*str))
            str++;
        if(*str && !is_space(*str))
        {
            result[i] = world_alloc(str);
            i++;
            while(*str && !is_space(*str))
                str++;
        }
    }
    result[i] = NULL;
    return result;
}