/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlongfel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 14:06:52 by xlongfel          #+#    #+#             */
/*   Updated: 2019/09/16 14:40:22 by xlongfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strcspn(const char *s, const char *reject)
{
	size_t i1;
	size_t i2;

	i1 = 0;
	while (s[i1] != '\0')
	{
		i2 = 0;
		while (reject[i2] != '\0')
		{
			if (s[i1] == reject[i2])
				return (i1);
			i2++;
		}
		i1++;
	}
	i1 = 0;
	while (s[i1] != '\0')
		i1++;
	return (i1);
}
