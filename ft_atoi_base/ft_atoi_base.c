int base_to_dec(char c)
{
    if(c >= '0' && c <= '9')
        return c - '0';
    else if(c >= 'a' && c <= 'f')
        return c - 'a' + 10;
    else if(c >= 'A' && c <= 'F')
        return c - 'A' + 10;
    return -1;
}

int ft_atoi_base(const char *str, int str_base)
{
    int i = 0;
    int neg = 1;
    int nbr = 0;
    if(!(str_base >= 2 && str_base <= 16))
        return 0;
    while(str[i] && ((str[i] >= 9 && str[i] <= 13) || str[i] == 32))
        i++;
    while(str[i] && (str[i] == '-' || str[i] == '+'))
    {
        if(str[i] == '-')
            neg = -1;
        i++;
    }
    while(str[i] && base_to_dec(str[i]) != -1)
    {
        nbr *= str_base;
        nbr += base_to_dec(str[i]);
        i++; 
    }
    return nbr * neg;
}