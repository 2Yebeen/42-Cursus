#include "../get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int     i;
    int     fd;
    char    *prt;
    char    *file_name1;
    char    *file_name2;
    char    *file_name3;

    file_name1 = "test1.txt";
    file_name2 = "test2.txt";
    file_name3 = "test3.txt";

    fd = open(file_name1,O_RDONLY);

    i = 5;
    prt = NULL;
    while (i--)
    {
        prt = get_next_line(fd);
        printf("%d, test[\"%s\"] : %s\n", fd, file_name1, prt);
        free(prt);
    }
    prt = NULL;
    close(fd);

    system("leaks a.out");
    return (0);
}