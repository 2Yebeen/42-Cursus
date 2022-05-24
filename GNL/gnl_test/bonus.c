#include "../get_next_line_bonus.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int     fd1;
    int     fd2;
    int     fd3;
    char    *prt;
    char    *file_name1;
    char    *file_name2;
    char    *file_name3;

    file_name1 = "test1.txt";
    file_name2 = "test2.txt";
    file_name3 = "test3.txt";

    fd1 = open(file_name1,O_RDONLY);
    fd2 = open(file_name2,O_RDONLY);
    fd3 = open(file_name3,O_RDONLY);

    prt = get_next_line(fd1);
    printf("%d, test[\"%s\"] : %s\n", fd1, file_name1, prt);
    free(prt);
 
    prt = get_next_line(fd2);
    printf("%d, test[\"%s\"] : %s\n", fd2, file_name2, prt);
    free(prt);
 
    prt = get_next_line(fd3);
    printf("%d, test[\"%s\"] : %s\n", fd3, file_name3, prt);
    free(prt);
 
    prt = get_next_line(fd1);
    printf("%d, test[\"%s\"] : %s\n", fd1, file_name1, prt);
    free(prt);

    prt = get_next_line(fd1);
    printf("%d, test[\"%s\"] : %s\n", fd1, file_name1, prt);
    free(prt);

    prt = get_next_line(fd2);
    printf("%d, test[\"%s\"] : %s\n", fd2, file_name2, prt);
    free(prt);

    prt = NULL;
    close(fd1);
    close(fd2);
    close(fd3);

    system("leaks a.out");
    return (0);
}