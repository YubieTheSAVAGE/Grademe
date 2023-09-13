#include <unistd.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

int main(int argc, char **argv)
{
    int i = 0;
    int snake = 0;
    if(argc == 2)
    {
        while(argv[1][i])
        {
            if(argv[1][i] && argv[1][i] != '_' && !snake)
                ft_putchar(argv[1][i]);
            if(argv[1][i] && argv[1][i] == '_')
                snake = 1;
            if(argv[1][i] && argv[1][i] != '_' && snake)
            {
                ft_putchar(argv[1][i] - 32);
                snake = 0;
            }
            i++;
        }
    }
    ft_putchar('\n');
    return 0;
}