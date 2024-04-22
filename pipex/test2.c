#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <fcntl.h>

int main() 
{
    int fd[2];
    int f = open("test.txt", O_RDWR);
	int f2 =  open ("anas.txt", O_RDWR);
    if (f == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    if (pipe(fd) == -1) {
        perror("pipe");
        exit(EXIT_FAILURE);
    }

    int pid1 = fork();
    if (pid1 < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    // char *av[] = {"/bin/ls", "-l", NULL};
    char *av2[] = {"/usr/bin/grep", "anas", NULL};

    if (pid1 == 0) 
    {
		dup2(f2, STDOUT_FILENO);
		dup2(fd[1], f2);
		close(fd[0]);
		close(fd[1]);
	}

    int pid2 = fork();
    if (pid2 < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    printf("%d ")
    if (pid2 == 0) {
        close(fd[1]); // Close the write end of the pipe
        dup2(fd[0], STDIN_FILENO); // Redirect stdin to the pipe read end
        close(fd[0]); // Close the read end of the pipe
        dup2(f, STDOUT_FILENO); // Redirect stdout to the file "test.txt"
        execve("/usr/bin/grep", av2, NULL);
        perror("execve");
        exit(EXIT_FAILURE);
    }

    close(fd[0]); // Close both ends of the pipe in the parent process
    close(fd[1]);
    close(f); // Close the file descriptor for "test.txt"
    return 0;
}
