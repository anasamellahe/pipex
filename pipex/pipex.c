#include "pipex.h"
#include "libft/libft.h"

char *get_path(char **env)
{
	int i;

	i = 0;
	while (ft_strnstr(env[i], "PATH", 4) == NULL)
		i++;
	if (env[i] != NULL)
		return (env[i]);
	return (0);
}
void join_path(char **path, char *cmd)
{
	char *new_path;
	int i;

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
char *get_valid_path(char **path, char *cmd)
{
	int i;

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
				return(path[i]);
			i++;
		}
		return (0);
	}
}
char *search_for_path(char **env, char *cmd, char *arg)
{
	char	*full_path;
	char	**path;
	char	*va_path;
	int		i;

	full_path = ft_strtrim(get_path(env), "PATH=");
	path = ft_split(full_path, ':');
	free(full_path);
	va_path = ft_strdup(get_valid_path(path, cmd));
	if (va_path == NULL)
	{
		write(2, "command not found: ", 19);
		write(2, arg, ft_strlen(arg));
		write(2, "\n", 1);
	}
	i = 0;
	while(path[i] != NULL)
		free(path[i++]);
	free(path);
	return (va_path);
}
void set_t_file(t_file *cmd1, t_file *cmd2, char **av, char **env)
{
	
	cmd1->file_name = av[1];
	cmd1->param = ft_split(av[2], ' ');
	cmd1->cmd = search_for_path(env, cmd1->param[0], av[2]);
	cmd2->file_name = av[4];
	cmd2->param = ft_split(av[3], ' ');
	cmd2->cmd = search_for_path(env, cmd2->param[0], av[3]);
}
void get_fd(t_file *cmd1, t_file *cmd2)
{
	cmd1->fd = open(cmd1->file_name, O_RDONLY);
	if (cmd1->fd < 0)
	{
		write(2, strerror(errno), ft_strlen(strerror(errno)));
		write (2, ": ", 2);
		write(2, cmd1->file_name, ft_strlen(cmd1->file_name));
		write(2, "\n", 1);
	}
	cmd2->fd = open(cmd2->file_name, O_CREAT | O_TRUNC, 0644);
	if (cmd2->fd < 0)
	{
		write(2, strerror(errno), ft_strlen(strerror(errno)));
		write (2, ": ", 2);
		write(2, cmd2->file_name, ft_strlen(cmd2->file_name));
		write(2, "\n", 1);
	}
}
int main(int ac, char *av[], char *env[])
{
	if (ac < 5)
	{
		write(2, "invalid number of args\n", 23);
		exit(0);	
	}
	t_file *cmd1;
	t_file *cmd2;

	cmd1 = malloc(sizeof(t_file));
	cmd2 = malloc(sizeof(t_file));
	set_t_file(cmd1, cmd2, av, env);
	get_fd(cmd1, cmd2);

	return (0);
}