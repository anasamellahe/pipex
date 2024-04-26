/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamella <anamella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:45:40 by anamella          #+#    #+#             */
/*   Updated: 2024/04/26 00:55:01 by anamella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	t;

	i = 0;
	t = 0;
	if (*needle == '\0')
		return ((char *)haystack);
	while (i < len && i < ft_strlen(haystack))
	{
		t = 0;
		while (needle[t] == haystack[i] && i < ft_strlen(haystack) && i < len)
		{
			i++;
			t++;
		}
		if (!needle[t])
			return (&((char *)haystack)[i - t]);
		i -= t;
		i++;
	}
	return (NULL);
}
