/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlongfel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 10:12:32 by xlongfel          #+#    #+#             */
/*   Updated: 2019/09/20 15:43:17 by xlongfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			len;
	unsigned char	*s11;
	unsigned char	*s22;

	len = 0;
	s11 = (unsigned char *)s1;
	s22 = (unsigned char *)s2;
	while (len < n)
	{
		if (*s11 != *s22)
			return (*s11 - *s22);
		if (*s11 == 0)
			break ;
		s11++;
		s22++;
		len++;
	}
	return (0);
}
