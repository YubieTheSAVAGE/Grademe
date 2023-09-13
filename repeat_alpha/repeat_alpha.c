#include <unistd.h>

int main(int argc, char **argv)
{
    int i = 0;
    int j;
    int re;
    if(argc == 2)
    {
        while(argv[1][i])
        {
            j = 0;
            re = 1;
            if(argv[1][i] >= 'a' && argv[1][i] <= 'z')  
                re = argv[1][i] - 96;
            else if(argv[1][i] >= 'A' && argv[1][i] <= 'Z')
                re = argv[1][i] - 64;
            while(j < re)
            {
                write(1, &argv[1][i], 1);
                j++;
            }
            i++;
        }
    }
    write(1, "\n", 1);
    return 0;
}