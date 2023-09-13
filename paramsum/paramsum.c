#include <unistd.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

void ft_putnbr(int nbr)
{
    long long n = nbr;
    if(n < 0)
    {
        ft_putchar('-');
        n = -n;
    }
    else if(n >= 10)
    {
        ft_putnbr(n / 10);
        ft_putchar(n % 10 + '0');
    }
    else
        ft_putchar(n + '0');
}

int main(int ac, char **av)
{   
    int i = 0;
    if(ac >= 2)
    {
        av++;
        while(*av)
        {
            i++;
            av++;
        }
    }
    ft_putnbr(i);
    ft_putchar('\n');
    return 0;
}