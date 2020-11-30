/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlongfel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 14:30:20 by xlongfel          #+#    #+#             */
/*   Updated: 2019/09/16 14:32:31 by xlongfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_max(int *tab, unsigned int len)
{
	int				max;
	unsigned int	i;

	i = 0;
	if (len == 0)
		return (0);
	max = tab[i];
	while (i < len - 1)
	{
		if (tab[i] < tab[i + 1])
			max = tab[i + 1];
	}
	return (max);
}
