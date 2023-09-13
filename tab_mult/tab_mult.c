#include <unistd.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

int ft_atoi(char *str)
{
    int i = 0;
    int nbr = 0;
    while(str[i])
    {
        nbr = nbr * 10 + (str[i] - '0');
        i++;
    }
    return nbr;
}

void ft_putnbr(int nbr)
{
    if(nbr > 9)
    {
        ft_putnbr(nbr / 10);
        ft_putchar(nbr % 10 + '0');
    }
    else
        ft_putchar(nbr + '0');
}

int main(int argc, char **argv)
{
    int i = 1;
    int x;
    int r;
    if(argc == 2)
    {
        x = ft_atoi(argv[1]);
        while(i <= 9)
        {
            r = x * i;
            ft_putnbr(i);
            ft_putchar(' ');
            ft_putchar('x');
            ft_putchar(' ');
            ft_putnbr(x);
            ft_putchar(' ');
            ft_putchar('=');
            ft_putchar(' ');
            ft_putnbr(r);
            ft_putchar('\n');
            i++;
        }
    }else
        ft_putchar('\n');
    return 0;
}