int ft_strlen(char *str)
{
    if(*str == '\0')
        return 0;
    return (1 + ft_strlen(++str));
}