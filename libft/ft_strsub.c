/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlongfel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 14:28:54 by xlongfel          #+#    #+#             */
/*   Updated: 2019/09/20 13:48:00 by xlongfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*c;

	if (!s)
		return (0);
	c = ft_memalloc(len + 1);
	if (!c)
		return (0);
	c = ft_strncpy(c, (s + start), len);
	return (c);
}
