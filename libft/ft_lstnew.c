/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xlongfel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 12:35:37 by xlongfel          #+#    #+#             */
/*   Updated: 2019/09/20 15:06:30 by xlongfel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*pop;

	pop = (t_list *)malloc(sizeof(t_list));
	if (!pop)
		return (NULL);
	pop->next = NULL;
	if (content == NULL || content_size == 0)
	{
		pop->content = NULL;
		pop->content_size = 0;
	}
	else
	{
		pop->content = malloc(sizeof(char) * (content_size));
		if (!(pop->content))
		{
			free(pop);
			return (NULL);
		}
		pop->content_size = content_size;
		ft_memcpy(pop->content, content, content_size);
	}
	return (pop);
}
