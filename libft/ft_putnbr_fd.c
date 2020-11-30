/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlongfel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 12:26:26 by xlongfel          #+#    #+#             */
/*   Updated: 2019/09/16 13:25:26 by xlongfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int i, int fd)
{
	int			ti;
	char		c[60];
	long long	z;
	char		a;

	ti = 0;
	z = i;
	if (i < 0)
	{
		write(fd, "-", 1);
		z = z * (-1);
	}
	if (i == 0)
		write(fd, "0", 1);
	while (z > 0)
	{
		a = z % 10;
		z = z / 10;
		c[ti] = a + '0';
		ti++;
	}
	while (ti)
		write(fd, &c[ti-- - 1], 1);
}
