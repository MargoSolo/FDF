/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlongfel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 10:37:08 by xlongfel          #+#    #+#             */
/*   Updated: 2019/09/19 13:57:09 by xlongfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int mas;
	int us;

	mas = 0;
	us = 0;
	while (*str == '\n' || *str == ' ' || *str == '\r' ||
			*str == '\v' || *str == '\f' || *str == '\t')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			us = 1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		mas = mas * 10;
		mas = mas + (*str - '0');
		str++;
	}
	if (us == 1)
		mas = -mas;
	return (mas);
}
