/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlongfel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 14:20:26 by xlongfel          #+#    #+#             */
/*   Updated: 2019/09/18 10:56:58 by xlongfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	lend;
	size_t	lens;
	size_t	i;

	lend = 0;
	lens = 0;
	i = 0;
	while (dst[lend] != '\0')
		lend++;
	while (src[lens] != '\0')
		lens++;
	if (lend >= size)
		lens += size;
	else
		lens += lend;
	while (src[i] != '\0' && lend + 1 < size)
	{
		dst[lend] = src[i];
		i++;
		lend++;
	}
	dst[lend] = '\0';
	return (lens);
}
