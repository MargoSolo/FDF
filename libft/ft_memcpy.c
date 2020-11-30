/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlongfel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 13:25:07 by xlongfel          #+#    #+#             */
/*   Updated: 2019/09/17 12:50:58 by xlongfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dest;
	unsigned char	*srcs;

	i = 0;
	dest = (unsigned char *)dst;
	srcs = (unsigned char *)src;
	if (dst != src)
	{
		while (i < n)
		{
			dest[i] = srcs[i];
			i++;
		}
	}
	return (dst);
}
