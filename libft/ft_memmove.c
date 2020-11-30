/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlongfel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 13:46:20 by xlongfel          #+#    #+#             */
/*   Updated: 2019/09/17 12:53:19 by xlongfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*dest;
	unsigned char	*srcs;

	dest = (unsigned char *)dst;
	srcs = (unsigned char *)src;
	i = 0;
	if (dest != srcs)
	{
		if (dest < srcs)
		{
			while (i < len)
			{
				dest[i] = srcs[i];
				i++;
			}
		}
		else
		{
			while (len--)
				dest[len] = srcs[len];
		}
	}
	return (dest);
}
