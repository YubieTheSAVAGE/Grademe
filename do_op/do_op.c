#include <stdlib.h>
#include <stdio.h>

int ft_strlen(char *str)
{
    int i = 0;
    while(str[i])
        i++;
    return i;
}

int main(int ac, char **av)
{
    int x;
    int y;
    int res = 0;
    if (ac == 4)
    {
        if(ft_strlen(av[2]) == 1)
        {
            x = atoi(av[1]);
            y = atoi(av[3]);
            if(av[2][0] == '+')
                res = x + y;
            else if(av[2][0] == '-')
                res = x - y;
            else if(av[2][0] == '*')
                res = x * y;
            else if(av[2][0] == '/')
                res = x / y;
            else if(av[2][0] == '%')
                res = x % y;
            printf("%d", res);
        }
    }
    printf("\n");
    return 0;
}