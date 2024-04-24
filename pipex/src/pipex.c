/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamella <anamella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 01:24:56 by anamella          #+#    #+#             */
/*   Updated: 2024/04/24 03:29:35 by anamella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	set_t_file(t_file *cmd1, t_file *cmd2, char **av, char **env)
{
	cmd1->file_name = av[1];
	cmd1->param = ft_split(av[2], ' ');
	cmd1->cmd = search_for_path(env, cmd1->param[0], av[2], &(cmd1->cmd_flag));
	cmd2->file_name = av[4];
	cmd2->param = ft_split(av[3], ' ');
	cmd2->cmd = search_for_path(env, cmd2->param[0], av[3], &(cmd2->cmd_flag));
}
void free_fun(t_file *cmd)
{
	int i;

	i = 0;
	while (cmd->param[i] != NULL)
		free(cmd->param[i++]);
	free(cmd->param);
	if (cmd->cmd_flag == 0)
		free(cmd->cmd);
	free(cmd);
}
void	child_proccess1(t_file *cmd1,t_file *cmd2 ,int *fd)
{
	int	pid1;

	pid1 = fork();
	if (pid1 < 0)
	{
		perror("fork");
		exit(0);
	}
	if (pid1 == 0 && cmd1->fd == -1)
		exit(0);
	if (pid1 == 0)
	{
		close(fd[0]);
		dup2(cmd1->fd, STDIN_FILENO);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
		if (execve(cmd1->cmd, cmd1->param, NULL) == -1)
		{
			write(2, "command not found: ", 19);
			write(2, cmd1->cmd, ft_strlen(cmd1->cmd));
			write(2, "\n", 1);
			free_fun(cmd1);
			free_fun(cmd2);
			exit(0);
		}
		free_fun(cmd1);
		free_fun(cmd2);
	}
}

void	child_proccess2(t_file *cmd1, t_file *cmd2,int *fd)
{
	int	pid2;

	pid2 = fork();
	if (pid2 < 0)
	{
		perror("fork");
		exit(0);
	}
	if (pid2 == 0)
	{
		close(fd[1]);
		dup2(cmd2->fd, STDOUT_FILENO);
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		if (execve(cmd2->cmd, cmd2->param, NULL) == -1)
		{
			write(2, "command not found: ", 19);
			write(2, cmd2->cmd, ft_strlen(cmd2->cmd));
			write(2, "\n", 1);
			free_fun(cmd1);
			free_fun(cmd2);
			exit(0);
		}
		free_fun(cmd1);
		free_fun(cmd2);
	}
}

void	pipex(t_file *cmd1, t_file *cmd2)
{
	int	fd[2];

	if (pipe(fd) < 0)
	{
		perror("pipe");
		exit(1);
	}
	child_proccess1(cmd1, cmd2,fd);
	child_proccess2(cmd1, cmd2, fd);
	close(fd[0]);
	close(fd[1]);
	close(cmd1->fd);
}

int	main(int ac, char *av[], char *env[])
{
	t_file	*cmd1;
	t_file	*cmd2;
	int		i;
	if (ac < 5)
	{
		write(2, "invalid number of args\n", 23);
		exit(0);
	}
	cmd1 = malloc(sizeof(t_file));
	cmd2 = malloc(sizeof(t_file));
	set_t_file(cmd1, cmd2, av, env);
	get_fd(cmd1, cmd2);
	pipex(cmd1, cmd2);
	free_fun(cmd1);
	free_fun(cmd2);
	return (0);
}
