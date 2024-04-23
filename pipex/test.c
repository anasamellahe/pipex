#include "pipex.h"

int main ()
{
    char *s = 0;
    char *av[] = {"ls", "-l",NULL};
    execve(s, av, NULL);
}