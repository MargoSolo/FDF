/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlongfel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 14:05:45 by xlongfel          #+#    #+#             */
/*   Updated: 2019/09/20 13:59:29 by xlongfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*c;
	char			*ss;

	i = 0;
	if (s == NULL || f == NULL)
		return (0);
	ss = (char *)s;
	c = (char *)malloc(sizeof(char) * (ft_strlen(ss) + 1));
	if (!c)
		return (0);
	while (ss[i])
	{
		c[i] = f(i, ss[i]);
		i++;
	}
	c[i] = '\0';
	return (c);
}
