/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamella <anamella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 01:25:58 by anamella          #+#    #+#             */
/*   Updated: 2024/04/24 02:57:25 by anamella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_path(char **env)
{
	int	i;

	i = 0;
	while (ft_strnstr(env[i], "PATH", 4) == NULL)
		i++;
	if (env[i] != NULL)
		return (env[i]);
	return (0);
}

void	join_path(char **path, char *cmd)
{
	char	*new_path;
	int		i;

	i = 0;
	while (path[i] != NULL)
	{
		new_path = ft_strjoin(path[i], "/");
		free(path[i]);
		path[i] = new_path;
		new_path = ft_strjoin(path[i], cmd);
		free(path[i]);
		path[i] = new_path;
		i++;
	}
}

char	*search_for_path(char **env, char *cmd, char *arg, int *flag)
{
	char	*full_path;
	char	**path;
	char	*va_path;
	int		i;

	full_path = ft_strtrim(get_path(env), "PATH=");
	path = ft_split(full_path, ':');
	free(full_path);
	va_path = ft_strdup(get_valid_path(path, cmd));
	*flag = 0;
	if (va_path == NULL)
	{
		*flag = 1;
		va_path = cmd;
	}
	i = 0;
	while (path[i] != NULL)
		free(path[i++]);
	free(path);
	return (va_path);
}

char	*get_valid_path(char **path, char *cmd)
{
	int	i;

	i = 0;
	if (!cmd)
		write(2, "Permission denied\n", 18);
	if (access(cmd, F_OK | X_OK) == 0)
		return (cmd);
	else
	{
		join_path(path, cmd);
		while (path[i] != NULL)
		{
			if (access(path[i], F_OK | X_OK) == 0)
				return (path[i]);
			i++;
		}
		return (0);
	}
}

void	get_fd(t_file *cmd1, t_file *cmd2)
{
	cmd1->fd = open(cmd1->file_name, O_RDONLY);
	if (cmd1->fd < 0)
	{
		write(2, strerror(errno), ft_strlen(strerror(errno)));
		write (2, ": ", 2);
		write(2, cmd1->file_name, ft_strlen(cmd1->file_name));
		write(2, "\n", 1);
	}
	cmd2->fd = open(cmd2->file_name, O_CREAT | O_TRUNC | O_RDWR, 0644);
	if (cmd2->fd < 0)
	{
		write(2, strerror(errno), ft_strlen(strerror(errno)));
		write (2, ": ", 2);
		write(2, cmd2->file_name, ft_strlen(cmd2->file_name));
		write(2, "\n", 1);
	}
}
