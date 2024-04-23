#ifndef PIPEX_H
#define PIPEX_H
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <errno.h>

typedef struct s_file
{
	int		fd;
	char	*file_name;
	char	*cmd;
	char	**param;
} t_file;
#endif