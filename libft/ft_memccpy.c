/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlongfel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 13:27:29 by xlongfel          #+#    #+#             */
/*   Updated: 2019/09/19 12:38:15 by xlongfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*dest;
	unsigned char	*srcs;

	i = 0;
	dest = (unsigned char *)dst;
	srcs = (unsigned char *)src;
	while (i < n)
	{
		dest[i] = srcs[i];
		if (dest[i] == (unsigned char)c)
			return ((void *)(dest + i + 1));
		i++;
	}
	return (0);
}
