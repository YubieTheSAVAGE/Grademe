#include <unistd.h>

int search(char *str, char c, int index)
{
    int i = 0;
    while(i < index)
    {
        if(str[i] == c)
            return 1;
        i++;
    }
    return 0;
}

int ft_strlen(char *str)
{
    if(!(*str))
        return 0;
    return (1 + ft_strlen(++str));
}

int main(int ac, char **av)
{
    int i = 0;
    int j;
    if(ac == 3)
    {
        j = ft_strlen(av[2]);
        while(av[1][i])
        {
            if(!(search(av[1], av[1][i], i)))
                if(search(av[2], av[1][i], j))
                    write(1, &av[1][i], 1);
            i++;
        }
    }
    write(1, "\n", 1);
    return 0;
}