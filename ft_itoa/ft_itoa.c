#include <stdlib.h>

int alloc_size(long nbr)
{
    int i = 0;
    while(nbr > 0)
    {
        nbr /= 10;
        i++;
    }
    return i;
}

void ft_swap(char *a, char *b)
{
    char c;
    c = *a;
    *a = *b;
    *b = c;
}

void ft_strrev(char *str)
{
    int i = 0;
    int j = 0;
    while(str[j])
        j++;
    j--;
    while(i < j)
    {
        ft_swap(&str[i], &str[j]);
        i++;
        j--;
    }
}

char *ft_itoa(int nbr)
{
    int i = 0;
    long nb = nbr;
    int size = 0;
    int neg = 0;
    char *result;
    if(nb == 0)
    {
        result = malloc(2);
        result[0] = '0';
        result[1] ='\0';
        return result;
    }
    if(nb < 0)
    {
        nb = -nb;
        size++;
        neg = 1;
    }
    size += alloc_size(nb);
    if(!(result = malloc((size + 1) * sizeof(char))))
        return NULL;
    while(nb > 0)
    {
        result[i] = nb % 10 + '0';
        nb /= 10;
        i++;
    }
    if(neg)
    {
        result[i] = '-';
        i++;
    }
    result[i] = '\0';
    ft_strrev(result);
    return result;
}