/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlongfel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 13:22:09 by xlongfel          #+#    #+#             */
/*   Updated: 2019/09/20 13:50:07 by xlongfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	unsigned char *s11;
	unsigned char *s22;

	s11 = (unsigned char *)s1;
	s22 = (unsigned char *)s2;
	while (*s11 == *s22)
	{
		if (*s11 == 0)
			return (0);
		s11++;
		s22++;
	}
	return ((int)(*s11 - *s22));
}
