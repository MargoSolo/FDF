/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlongfel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 17:29:22 by xlongfel          #+#    #+#             */
/*   Updated: 2019/09/21 13:22:40 by xlongfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	int		flag;

	i = -1;
	j = 0;
	flag = 0;
	while (haystack[++i] && needle[j] && i < len)
	{
		if (haystack[i] == needle[j])
		{
			if (j == 0)
				flag = i + 1;
			j++;
		}
		else if (flag > 0)
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
