/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlongfel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 15:02:50 by xlongfel          #+#    #+#             */
/*   Updated: 2019/09/20 15:55:49 by xlongfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	return (0);
}

char		*ft_strtrim(char const *s)
{
	int		i;
	char	*c;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	if (!s)
		return (0);
	j = ft_strlen(s);
	while (is_space(s[i]))
		i++;
	while (j > i && is_space(s[j - 1]))
		j--;
	if (!(c = (char *)malloc(sizeof(char) * (j - i + 1))))
		return (0);
	while (i < j)
	{
		c[k] = s[i];
		i++;
		k++;
	}
	c[k] = '\0';
	return (c);
}
