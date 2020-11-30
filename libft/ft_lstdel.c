/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlongfel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 13:50:38 by xlongfel          #+#    #+#             */
/*   Updated: 2019/09/17 12:03:34 by xlongfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*abc;
	t_list	*bcd;

	abc = *alst;
	bcd = abc;
	while (abc)
	{
		bcd = abc->next;
		del((abc->content), (abc->content_size));
		free(abc);
		abc = bcd;
	}
	*alst = NULL;
}
