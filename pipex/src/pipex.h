/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamella <anamella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 01:26:04 by anamella          #+#    #+#             */
/*   Updated: 2024/04/26 06:00:31 by anamella         ###   ########.fr       */
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

typedef struct s_file
{
	int		pid;
	int		fd;
	int		cmd_f;
	int		free_flag;
	int		exit_status;
	char	*file_name;
	char	*cmd;
	char	**param;
}	t_file;

char	*search_for_path(char **env, char *cmd_n, t_file *cmd);
char	*get_valid_path(char **path, char *cmd_n, t_file *cmd);
char	*get_path(char **env);
void	set_t_file(t_file *cmd1, t_file *cmd2, char **av, char **env);
void	print_error(char *message, char *path, int path_flag);
void	child_proccess1(t_file *cmd1, t_file *cmd2, int *fd);
void	child_proccess2(t_file *cmd1, t_file *cmd2, int *fd);
void	get_exit_status(t_file *cmd1, t_file *cmd2);
void	get_fd(t_file *cmd1, t_file *cmd2);
void	join_path(char **path, char *cmd);
void	pipex(t_file *cmd1, t_file *cmd2);
void	free_fun(t_file *cmd1, t_file *cmd2);
void	free_cmd(t_file *cmd);

char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *s1);
void	ft_bzero(void *s, size_t n);
size_t	ft_strlen(const char *s);

#endif