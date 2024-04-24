/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamella <anamella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 01:26:04 by anamella          #+#    #+#             */
/*   Updated: 2024/04/24 03:28:44 by anamella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <unistd.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>
# include <errno.h>
#include "../libft/libft.h"

typedef struct s_file
{
	int		fd;
	int		cmd_flag;
	char	*file_name;
	char	*cmd;
	char	**param;
}	t_file;

char	*search_for_path(char **env, char *cmd, char *arg, int *flag);
char	*get_valid_path(char **path, char *cmd);
char	*get_path(char **env);
void	set_t_file(t_file *cmd1, t_file *cmd2, char **av, char **env);
void	child_proccess1(t_file *cmd1, t_file *cmd2,int *fd);
void	child_proccess2(t_file *cmd1, t_file *cmd2,int *fd);
void	get_fd(t_file *cmd1, t_file *cmd2);
void	join_path(char **path, char *cmd);
void	pipex(t_file *cmd1, t_file *cmd2);

#endif