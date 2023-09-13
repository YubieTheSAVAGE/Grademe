#include <unistd.h>

void str_lowcaser(char *str)
{
    int i = 0;
    while(str[i])
    {
        if(str[i] >= 'A' && str[i] <= 'Z')
            str[i] += 32;
        i++;
    }
}

int main(int argc, char **argv)
{
    int i = 0;
    int j = 1;
    if(argc >= 2)
    {
        while(argv[j])
        {
            i = 0;
            str_lowcaser(argv[j]);
            if(argv[j][i] >= 'a' && argv[j][i] <= 'z')
                argv[j][i] -= 32;
            while(argv[j][i])
            {
                if((argv[j][i] >= 'a' && argv[j][i] <= 'z') && (argv[j][i - 1] == ' ' || argv[j][i - 1] == '\t'))
                    argv[j][i] -= 32;
                i++;
            }
            i = 0;
            while(argv[j][i])
            {
                write(1, &argv[j][i], 1);
                i++;
            }
            write(1, "\n", 1);
            j++;
        }
    }else
        write(1, "\n", 1);
    return 0;
}