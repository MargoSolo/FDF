/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlongfel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 15:42:20 by xlongfel          #+#    #+#             */
/*   Updated: 2019/09/22 21:57:04 by xlongfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_count_words(const char *str, char c)
{
	int flag;
	int i;
	int count;

	count = 0;
	i = 0;
	flag = 1;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			flag = 1;
		else
		{
			if (flag == 1)
			{
				count++;
				flag = 0;
			}
		}
		i++;
	}
	return (count);
}

static const char	*ft_words(const char *str, int counter, char c)
{
	int i;
	int flag;

	i = 0;
	flag = 1;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			flag = 1;
		else
		{
			if (flag == 1)
			{
				if (counter == 0)
					return (str + i);
				counter--;
			}
			flag = 0;
		}
		i++;
	}
	return (str);
}

static char			*ft_space_for_words(const char *str, char c)
{
	int		i;
	int		j;
	char	*x;

	i = 0;
	j = 0;
	while (str[i] != c && str[i] != '\0')
		i++;
	x = (char *)malloc(sizeof(char) * (i + 1));
	if (!x)
		return (NULL);
	while (j < i)
	{
		x[j] = str[j];
		j++;
	}
	x[j] = '\0';
	return (x);
}

static void			ft_zero(char **common, size_t i)
{
	while (i--)
	{
		ft_strdel(&(common[i]));
		free(*common);
	}
}

char				**ft_strsplit(char const *s, char c)
{
	char	**masmal;
	int		count;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	count = ft_count_words(s, c);
	masmal = (char **)malloc(sizeof(char *) * (count + 1));
	if (!masmal)
		return (NULL);
	while (i < count)
	{
		masmal[i] = ft_space_for_words(ft_words(s, i, c), c);
		if (!(masmal[i]))
		{
			while (i--)
				ft_zero(masmal, i);
		}
		i++;
	}
	masmal[i] = 0;
	return (masmal);
}
