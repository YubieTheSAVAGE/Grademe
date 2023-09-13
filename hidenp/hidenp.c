#include <unistd.h>

int ft_strlen(char *str)
{
    if(*str == '\0')
        return 0;
    return (1 + ft_strlen(++str));
}

int main(int ac, char **av)
{
    int count = 0;
    int i = 0;
    int j = 0;
    if(ac == 3)
    {
        while(av[1][i])
        {
            while(av[2][j])
            {
                if(av[1][i] == av[2][j])
                {
                    count++;
                    break;
                }
                j++;
            }
            i++;
        }
        if(ft_strlen(av[1]) == count)
            write(1, "1", 1);
        else
            write(1, "0", 1);
    }
    write(1, "\n", 1);
    return 0;
}