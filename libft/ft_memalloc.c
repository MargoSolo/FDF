/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlongfel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 12:27:18 by xlongfel          #+#    #+#             */
/*   Updated: 2019/09/20 13:48:27 by xlongfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	unsigned char	*t;
	size_t			i;

	i = 0;
	t = malloc(sizeof(char) * (size));
	if (!t)
		return (0);
	while (i < size)
	{
		t[i] = '\0';
		i++;
	}
	return (t);
}
