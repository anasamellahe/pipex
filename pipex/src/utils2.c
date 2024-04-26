/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamella <anamella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 03:45:54 by anamella          #+#    #+#             */
/*   Updated: 2024/04/26 03:46:00 by anamella         ###   ########.fr       */
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
