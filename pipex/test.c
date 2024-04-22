#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

int main(int argc, char* argv[]) {
    // int fd[2];
    char buff[20];
    // pipe(fd);
    // int pid = fork();
    // if (pid < 0)
    // {
    //     printf("error\n");
    //     return (0);
    // }
    // if (pid == 0)
    // {
    //     write (fd[1], "hello anas", 10);
    // }
    // else
    //     {
    //         wait(NULL);
    //         read(fd[0], buff, 10);
    //         printf("%s\n", buff);
    //     }
    

    int fd[2];
    int f = open("test.txt", O_RDWR);
    pipe(fd);
    int pid1 = fork();
    char *av[] = {"/bin/ls", "-l", NULL};
    char *av2[] = {"/bin/ls", "-l", NULL};
    if (pid1 < 0)
        return 0;
    if (pid1 == 0)
    {
        dup2(fd[0], 1);
        execve("/bin/ls", av, NULL);
        close(fd[0]);
        close(fd[1]);
       
    }
    int pid2 = fork();
    if (pid2 < 0)
        return (0);
    if (pid2 == 0)
    {
        //dup2(f, 1);
        dup2(fd[0], 0);
        execve("/usr/bin/ls", av2, NULL);
        close(fd[0]);
        close(fd[1]);
    }
    close(fd[0]);
    close(fd[1]);
    return 0;
}