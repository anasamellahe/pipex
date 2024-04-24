#include "pipex.h"

int main ()
{
    char *av[] = {"awk", "/akj/{print}", "infile", NULL};
    char *envp[] = {NULL};
    execve("/usr/bin/awk", av, envp);
    return 0;
}