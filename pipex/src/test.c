#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

// Driver code
int main(void)
{
	// pid_t pid = fork();
	
	// if ( pid == 0 )
	// {
	// /* The pathname of the file passed to execl()
	// 	is not defined */
	// printf("test ==\n");
	// }

	// int status;
	
	// waitpid(pid, &status, 0);

    // int test = WIFEXITED(status);
    // printf("test == %d\n", test);
    
	// if (test)
	// {
	// 	int exit_status = WEXITSTATUS(status);	 
	// 	printf("Exit status of the child was %d\n", 
	// 								exit_status);
	// }
	// return 0;
    int pid = fork();

    if (pid == 0)
    {
        printf("child\n");
        for (int i = 0; i < 10; i++){printf("child == %d pid == [%d]\n", i, pid);}
    }
    waitpid(pid, 0, 0);
    for (int i = 0; i < 10; i++){printf("parent == %d pid == [%d]\n", i, pid);}
    printf("parent\n");
    return (0);
}
