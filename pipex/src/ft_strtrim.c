/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamella <anamella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:47:35 by anamella          #+#    #+#             */
/*   Updated: 2024/04/26 00:52:35 by anamella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	int		t;
	int		arr[256];
	char	*str;

	if (!s1)
		return (NULL);
	i = 0;
	ft_bzero(arr, 256 * sizeof(int));
	while (set && set[i])
		arr[(int)((unsigned char)set[i++])] = 1;
	i = 0;
	while (s1[i] && arr[(int)((unsigned char)s1[i])])
		i++;
	j = i;
	t = 0;
	while (s1[i])
	{
		t = (t * arr[(int)((unsigned char)s1[i])])
			+ arr[(int)((unsigned char)s1[i])];
		i++;
	}
	str = ft_substr(s1, j, i - (j + t));
	return (str);
}
