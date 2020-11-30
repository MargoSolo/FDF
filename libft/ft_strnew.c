/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlongfel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 13:24:13 by xlongfel          #+#    #+#             */
/*   Updated: 2019/09/21 14:14:05 by xlongfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*t;

	if (size + 1 == 0)
		return (NULL);
	t = (char *)malloc(sizeof(char) * (size + 1));
	if (!t)
		return (0);
	ft_memset(t, 0, size + 1);
	return (t);
}
