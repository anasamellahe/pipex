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
int main(int ac, char *av[], char *env[])
{

	char **str =  ft_split(get_path(env), ':');
	str[0] = ft_strtrim(str[0], "PATH=");
	int i = 0;
	// while (str[i])
	// {
	// 	free(str[i++]);
	// }
	return (0);
}