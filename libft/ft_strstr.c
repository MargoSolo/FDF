/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlongfel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 15:16:15 by xlongfel          #+#    #+#             */
/*   Updated: 2019/09/20 20:15:43 by xlongfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strstr(const char *haystack, const char *needle)
{
	size_t	i;
	size_t	j;
	int		flag;

	i = -1;
	j = 0;
	flag = 0;
	while (haystack[++i] && needle[j])
	{
		if (haystack[i] == needle[j])
		{
			if (j == 0)
				flag = i + 1;
			j++;
		}
		else if (flag)
		{
			j = 0;
			i = flag - 1;
			flag = 0;
		}
	}
	if (needle[j] == '\0')
		return ((char *)(haystack + i - j));
	return (0);
}
