int max(int *tab, unsigned int len)
{
    int max = 0;
    int i = 0;
    if(!tab)
        return 0;
    while(tab[i])
    {
        if(max < tab[i])
            max = tab[i];
        i++;
    }
    return max;
}