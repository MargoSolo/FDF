/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_last.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlongfel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 14:27:22 by xlongfel          #+#    #+#             */
/*   Updated: 2019/09/17 13:00:52 by xlongfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_list_last(t_list *begin_list)
{
	t_list *old;

	old = begin_list;
	while (old->next != NULL)
		old = old->next;
	return (old);
}
