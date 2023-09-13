#include <stdlib.h>
#include <unistd.h>

int is_space(char c)
{
    return (c == ' ' || c == '\t');
}

int count_words(char *str)
{
    int count = 0 ;
    int i = 0;
    while(str[i])
    {
        if(!is_space(str[i]) && (is_space(str[i + 1]) || str[i + 1] == '\0'))
            count++;
        i++;
    }
    return count;
}

char *word_alloc(char *str)
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

char **ft_split(char *str)
{
    char **sp;
    int i = 0;
    sp = malloc((count_words(str) + 1) * sizeof(char *));
    while(*str)
    {
        while(is_space(*str) && *str)
            str++;
        if(!is_space(*str) && *str)
        {
            sp[i] = word_alloc(str);
            i++;
            while(!is_space(*str) && *str)
                str++;
        }
    }
    sp[i] = NULL;
    return sp;
}

void ft_putstr(char *str)
{
    int i = 0;
    while(str[i])
    {
        write(1, &str[i], 1);
        i++;
    }
}

int main(int argc, char **argv)
{
    int i = 1;
    char **sp;
    if(argc >= 2)
    {
        sp = ft_split(argv[1]);
        while(sp[i])
        {
            ft_putstr(sp[i]);
            //if(sp[i + 1] != NULL)
                write(1, " ", 1);
            i++;
        }
        ft_putstr(sp[0]);
    }
    write(1, "\n", 1);
    return 0;
}