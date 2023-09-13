#include <unistd.h>

int search_dua(char *str, char c, int index)
{
    int i = 0;
    while(i < index)
    {
        if(str[i] == c)
            return 1;
        i++;
    }
    return 0;
}

int main(int argc, char **argv)
{
    int i = 0;
    int j = 0;
    if(argc == 3)
    {
        while(argv[1][i])
        {
            if(!search_dua(argv[1], argv[1][i], i))
                write(1, &argv[1][i], 1);
            i++;
        }
        while(argv[2][j])
        {
            if(!search_dua(argv[2], argv[2][j], j))
            {
                if(!search_dua(argv[1], argv[2][j], i))
                    write(1, &argv[2][j], 1);
            }
            j++;
        }
    }
    write(1, "\n", 1);
    return 0;
}