/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlongfel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 14:15:51 by xlongfel          #+#    #+#             */
/*   Updated: 2019/09/09 11:57:49 by xlongfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*dest;
	unsigned char	*srcs;

	i = 0;
	dest = (unsigned char *)s1;
	srcs = (unsigned char *)s2;
	while (i < n)
	{
		if (srcs[i] != dest[i])
			return (dest[i] - srcs[i]);
		i++;
	}
	return (0);
}
