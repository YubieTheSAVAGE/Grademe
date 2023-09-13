#include <unistd.h>
#include <stdlib.h>

int is_space(char c)
{
    return (c == ' ' || c == '\t');
}

int word_count(char *str)
{
    int i = 0;
    int count = 0;

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
    int i = 0;
    int wc = 0 ;
    char **sp;
    wc = word_count(str);
    sp = malloc((wc + 1) * sizeof(char *));
    while(*str)
    {
        while(*str && is_space(*str))
            str++;
        if(*str && !is_space(*str))
        {
            sp[i] = word_alloc(str);
            i++;
            while(*str && !is_space(*str))
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
    int i = 0;
    char **sp;
    if(argc == 2)
    {   
        sp = ft_split(argv[1]);
        while(sp[i])
            i++;
        i--;
        while(i >= 0)
        {
            ft_putstr(sp[i]);
            if(i != 0)
                write(1, " ", 1);
            i--;
        }
    }
    write(1, "\n", 1);
    return 0;
}