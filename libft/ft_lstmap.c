/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlongfel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 13:59:31 by xlongfel          #+#    #+#             */
/*   Updated: 2019/09/21 14:54:42 by xlongfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*one;
	t_list		**two;
	t_list		*root;

	if (!f)
		return (NULL);
	root = NULL;
	two = &root;
	while (lst)
	{
		one = f(lst);
		if (!one)
			return (0);
		one->next = NULL;
		*two = one;
		two = &one->next;
		lst = lst->next;
	}
	return (root);
}
