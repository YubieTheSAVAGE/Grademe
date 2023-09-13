#include <stdio.h>
#include <stdlib.h>

void fprime(int nbr)
{
    int index = 2;
    if(nbr == 1)
    {
        printf("1");
        return ;
    }else if(nbr < 1)
        return ;
    while(index <= nbr)
    {
        if(nbr % index == 0)
        {
            printf("%d", index);
            nbr /= index;
            index = 1;
            if(nbr == 1)
                return ;
            else
                printf("*");
        }
        index++;
    }
}

int main(int ac, char **av)
{
    if(ac == 2)
        fprime(atoi(av[1]));
    printf("\n");
    return 0;
}