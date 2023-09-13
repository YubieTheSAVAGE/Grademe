#include <unistd.h>

int main(int argc, char **argv)
{
    int i = 0;
    int space = -1;
    if(argc == 2)
    {
        while(argv[1][i])
        {
            if(argv[1][i] != ' ' && argv[1][i] != '\t')
            {
                if(space == 1)
                {
                    write(1, " ", 1);
                }
                write(1, &argv[1][i], 1);
                    space = 0;
            }
            else if(space == 0)
                space = 1;
            i++;
        }
    }
    write(1, "\n", 1);
    return 0;
}