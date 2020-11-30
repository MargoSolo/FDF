/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlongfel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 17:12:47 by xlongfel          #+#    #+#             */
/*   Updated: 2019/09/19 14:01:53 by xlongfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_len(unsigned int tmp)
{
	int len;

	len = 0;
	if (tmp == 0)
		return (1);
	while (tmp)
	{
		len++;
		tmp = tmp / 10;
	}
	return (len);
}

char			*ft_itoa(int n)
{
	char			*s;
	int				len;
	int				negative;
	long long		z;

	len = 0;
	negative = 0;
	z = n;
	if (n < 0)
	{
		z = -z;
		negative = 1;
	}
	len = ft_len((unsigned int)(z)) + negative;
	if (!(s = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	s[len] = '\0';
	while (--len >= 0)
	{
		s[len] = (z % 10) + '0';
		z = z / 10;
	}
	if (negative == 1)
		s[0] = '-';
	return (s);
}
