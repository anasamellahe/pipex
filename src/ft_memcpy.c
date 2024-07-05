/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamella <anamella@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:43:35 by anamella          #+#    #+#             */
/*   Updated: 2024/04/26 00:56:10 by anamella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	void	*t;

	t = dst;
	if (dst == src)
		return (t);
	while (n)
	{
		*((unsigned char *)dst++) = *((unsigned char *)src++);
		n--;
	}
	return (t);
}
