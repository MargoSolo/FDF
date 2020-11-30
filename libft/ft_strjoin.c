/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlongfel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 14:45:41 by xlongfel          #+#    #+#             */
/*   Updated: 2019/09/24 15:38:31 by xlongfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*c;
	size_t	l1;
	size_t	l2;

	l1 = s1 ? ft_strlen(s1) : 0;
	l2 = s2 ? ft_strlen(s2) : 0;
	c = (char *)malloc(sizeof(char) * (l1 + l2 + 1));
	if (!c)
		return (0);
	if (s1)
		ft_strcpy(c, s1);
	if (s2)
		ft_strcpy(c + l1, s2);
	return (c);
}
