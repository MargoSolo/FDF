/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlongfel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 15:23:31 by xlongfel          #+#    #+#             */
/*   Updated: 2019/09/20 20:16:06 by xlongfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(const char *src)
{
	char	*s;
	char	*x;
	int		len;

	len = 0;
	while (src[len])
		len++;
	s = malloc(len + 1);
	if (!s)
		return (NULL);
	x = s;
	while (*src)
	{
		*x++ = *src++;
	}
	*x = '\0';
	return (s);
}
