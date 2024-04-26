/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamella <anamella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 03:45:54 by anamella          #+#    #+#             */
/*   Updated: 2024/04/26 23:41:17 by anamella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_fun(t_file *cmd1, t_file *cmd2)
{
	free_cmd(cmd1);
	free_cmd(cmd2);
}

void	free_cmd(t_file *cmd)
{
	int	i;

	i = 0;
	while (cmd->param[i] != NULL)
		free(cmd->param[i++]);
	free(cmd->param);
	if (cmd->free_flag == 0)
		free(cmd->cmd);
	free(cmd);
}

void	print_error(char *message, char *path, int path_flag)
{
	write(2, message, ft_strlen(message));
	if (path_flag == 1)
		write(2, path, ft_strlen(path));
	write(2, "\n", 1);
}

void	get_exit_status(t_file *cmd1, t_file *cmd2)
{
	int	status1;
	int	status2;

	waitpid(cmd1->pid, &status1, 0);
	waitpid(cmd2->pid, &status2, 0);
	if (WIFEXITED(status1))
		cmd1->exit_status = WEXITSTATUS(status1);
	if (WIFEXITED(status2))
		cmd2->exit_status = WEXITSTATUS(status2);
}
