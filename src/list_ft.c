/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_ft.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboutin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 17:25:18 by pboutin           #+#    #+#             */
/*   Updated: 2017/10/18 18:02:52 by pboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;

	if (!(new = (t_list *)content))
		return (NULL);
	if (content == NULL)
	{
		new->content = NULL;
		new->content_size = 0;
	}
	else
	{
		new->content = (char *)content;
		new->content_size = content_size;
	}
	new->next = NULL;
	return (new);
}

t_list		*ft_lstiter(t_list *lst, int (f)(t_list *elem))
{
	t_list	*tmp;

	if (lst && f)
	{
		tmp = lst;
		while (tmp)
		{
			if (f(tmp) == 1)
			{
				return (tmp);
			}
			tmp = tmp->next;
		}
	}
	return (NULL);
}
