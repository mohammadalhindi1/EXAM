#include <unistd.h>

int main(int ac, char *av[])
{
    if (ac == 3)
    {
        int used[256] = {0};
        int i = 0;
        int j;

        while (av[1][i])
        {
            j = 0;
            while (av[2][j])
            {
                if (av[1][i] == av[2][j] && used[(unsigned char)av[1][i]] == 0)
                {
                    write(1, &av[1][i], 1);
                    used[(unsigned char)av[1][i]] = 1;
                    break;
                }
                j++;
            }
            i++;
        }
    }
    write(1, "\n", 1);
}