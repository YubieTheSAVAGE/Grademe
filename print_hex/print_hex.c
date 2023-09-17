#include <unistd.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

void dec_to_hex(int n)
{
    char base[] = "0123456789abcdef";
    if(n >= 16)
        dec_to_hex(n / 16);
    n %= 16;
    ft_putchar(base[n % 16]);
}

int ft_atoi(char *str)
{
    int i = 0;
    int nb = 0;
    while(str[i])
    {
        nb = nb * 10 + (str[i] - '0');
        i++;
    }
    return nb;
}

int main(int ac, char **av)
{
    if(ac == 2)
    {
        dec_to_hex((ft_atoi(av[1])));
    }
    write(1, "\n", 1);
    return 0;
}