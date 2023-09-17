#include <stdio.h>
#include <stdlib.h>

int main(int ac, char **av)
{
    int x;
    int y;
    int min;
    if(ac == 3)
    {
        x = atoi(av[1]);
        y = atoi(av[2]);
        if(x > y)
            min = y;
        else
            min = x;
        while(min >= 1)
        {
            if(x % min == 0 && y % min == 0)
            {
                printf("%d", min);
                break;
            }
            min--;
        }
    }
    printf("\n");
    return 0;
}