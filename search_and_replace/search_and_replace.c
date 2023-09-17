#include <unistd.h>

int ft_strlen(char *str)
{
    if(*str == '\0')
        return 0;
    return (1 + ft_strlen(++str));
}

int main(int ac, char **av)
{
    int i = 0;
    if(ac == 4)
    {
        if(ft_strlen(av[2]) == 1 && ft_strlen(av[3]))
        {
            while(av[1][i])
            {
                if(av[1][i] == av[2][0])
                    write(1, &av[3][0], 1);
                else
                    write(1, &av[1][i], 1);
                i++;
            }
        }
    }
    write(1, "\n", 1);
    return 0;
}