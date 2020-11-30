/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlongfel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 14:20:19 by xlongfel          #+#    #+#             */
/*   Updated: 2019/09/16 14:24:16 by xlongfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_list_size(t_list *begin_list)
{
	t_list	*old;
	int		count;

	count = 0;
	old = begin_list;
	while (old)
	{
		old = old->next;
		count++;
	}
	return (count);
}
