/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamella <anamella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 01:24:56 by anamella          #+#    #+#             */
/*   Updated: 2024/04/26 23:31:18 by anamella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	set_t_file(t_file *cmd1, t_file *cmd2, char **av, char **env)
{
	cmd1->file_name = av[1];
	cmd1->param = ft_split(av[2], ' ');
	cmd1->cmd = search_for_path(env, cmd1->param[0], cmd1);
	cmd2->file_name = av[4];
	cmd2->param = ft_split(av[3], ' ');
	cmd2->cmd = search_for_path(env, cmd2->param[0], cmd2);
}

void	child_proccess1(t_file *cmd1, t_file *cmd2, int *fd)
{
	cmd1->pid = fork();
	if (cmd1->pid < 0)
	{
		perror("fork");
		exit(0);
	}
	if (cmd1->pid == 0 && (cmd1->fd == -1 || cmd1->cmd_f == 1))
	{
		free_fun(cmd1, cmd2);
		exit(0);
	}
	if (cmd1->pid == 0)
	{
		close(fd[0]);
		dup2(cmd1->fd, STDIN_FILENO);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
		if (execve(cmd1->cmd, cmd1->param, NULL) == -1)
		{
			print_error("command not found: ", cmd1->cmd, cmd1->cmd != 0);
			free_fun(cmd1, cmd2);
			exit(127);
		}
	}
}

void	child_proccess2(t_file *cmd1, t_file *cmd2, int *fd)
{
	cmd2->pid = fork();
	if (cmd2->pid < 0)
	{
		perror("fork");
		exit(0);
	}
	if (cmd2->pid == 0 && cmd2->cmd_f == 1)
	{
		free_fun(cmd1, cmd2);
		exit(126);
	}
	if (cmd2->pid == 0)
	{
		close(fd[1]);
		dup2(cmd2->fd, STDOUT_FILENO);
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
		if (execve(cmd2->cmd, cmd2->param, NULL) == -1)
		{
			print_error("command not found: ", cmd2->cmd, cmd2->cmd != 0);
			free_fun(cmd1, cmd2);
			exit(127);
		}
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
	child_proccess1(cmd1, cmd2, fd);
	child_proccess2(cmd1, cmd2, fd);
	close(fd[0]);
	close(fd[1]);
	close(cmd1->fd);
	get_exit_status(cmd1, cmd2);
}

int	main(int ac, char *av[], char *env[])
{
	t_file	*cmd1;
	t_file	*cmd2;
	int		exit_status;

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
	exit_status = cmd2->exit_status;
	free_fun(cmd1, cmd2);
	exit(exit_status);
	return (0);
}
