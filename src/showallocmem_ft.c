/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   showallocmem_ft.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboutin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 16:55:50 by pboutin           #+#    #+#             */
/*   Updated: 2017/10/18 17:22:43 by pboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

t_list		*browse_lst(t_list *lst)
{
	if (lst)
	{
		while (lst->next)
		{
			lst = lst->next;
		}
		return (lst);
	}
	return (NULL);
}

void		norm_display(t_list *lst, int off_set, int size)
{
	int		i;

	i = 25;
	while (i < 145)
	{
		if (lst->content[i] == TRUE)
		{
			ft_putstr("\n");
			ft_putstr(ft_addr(&lst->content[(i - 25) * size + off_set]));
			ft_putstr(" - ");
			ft_putstr(ft_addr(&lst->content[((i + 1) - 25) * size + off_set]));
			ft_putstr(" : ");
			ft_putnbr(size);
		}
		i++;
	}
}

void		browse_lst2(t_list *lst, int off_set, int size)
{
	int		i;

	if (lst)
	{
		while (lst->next)
		{
			ft_putstr(ft_addr(lst->content));
			norm_display(lst, off_set, size);
			lst = lst->next;
		}
		ft_putstr(ft_addr(lst->content));
		norm_display(lst, off_set, size);
	}
}

void		browse_lst3(t_list *lst)
{
	int		i;

	if (lst)
	{
		ft_putstr(ft_addr(lst->content));
		while (lst->next)
		{
			ft_putstr("\n");
			ft_putstr(ft_addr(&lst->content[25]));
			ft_putstr(" - ");
			ft_putstr(ft_addr(&lst->content[25 + lst->content_size]));
			ft_putstr(" : ");
			ft_putnbr(lst->content_size);
			lst = lst->next;
		}
		ft_putstr("\n");
		ft_putstr(ft_addr(&lst->content[25]));
		ft_putstr(" - ");
		ft_putstr(ft_addr(&lst->content[25 + lst->content_size]));
		ft_putstr(" : ");
		ft_putnbr(lst->content_size);
	}
}

void		show_alloc_mem(void)
{
	ft_putstr("TINY :");
	browse_lst2(g_zone.tiny, 192, 64);
	ft_putstr("\nSMALL :");
	browse_lst2(g_zone.small, 1023, 1024);
	ft_putstr("\nLARGE :");
	browse_lst3(g_zone.large);
}
