/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlongfel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 13:52:20 by xlongfel          #+#    #+#             */
/*   Updated: 2019/09/20 12:55:51 by xlongfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*c;

	i = 0;
	if (!s || !f)
		return (0);
	c = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!c)
		return (0);
	while (s[i])
	{
		c[i] = f(s[i]);
		i++;
	}
	c[i] = '\0';
	return (c);
}
