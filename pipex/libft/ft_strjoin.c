/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamella <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:44:59 by anamella          #+#    #+#             */
/*   Updated: 2023/11/19 01:34:14 by anamella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	size_t	len;
	size_t	len1;

	if (!s1 && !s2)
		return (NULL);
	if (s1)
		len = ft_strlen(s1);
	else
		len = 0;
	if (s2)
		len1 = ft_strlen(s2);
	else
		len1 = 0;
	ptr = malloc(len + len1 + 1);
	if (!ptr)
		return (NULL);
	if (s1)
		ft_memcpy(ptr, s1, len);
	if (s2)
		ft_memcpy((ptr + len), s2, len1);
	ptr[len + len1] = '\0';
	return (ptr);
}
