#ifndef PIPEX_H
#define PIPEX_H
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>

typedef struct s_file
{
	char *file_name;
	char *cmd;
} t_file;
#endif