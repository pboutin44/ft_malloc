/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboutin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/26 15:37:51 by pboutin           #+#    #+#             */
/*   Updated: 2017/10/18 18:55:02 by pboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

/*int			main(void)
{
	malloc(1024);
	malloc(1024 * 32);
	malloc(1024 * 1024);
	malloc(1024 * 1024 * 16);
	malloc(1024 * 1024 * 128);
	show_alloc_mem();
	return (0);
}*/

void		*large(size_t size)
{
	void *ret;

	if (g_zone.large)
	{
		ret = already_large(size);
		return (ret);
	}
	else
	{
		ret = first_large(size);
		return (ret);
	}
}

void		*small(size_t size)
{
	void *ret;

	if (g_zone.small)
	{
		ret = already_small(size);
		return (ret);
	}
	else
	{
		ret = first_small(size);
		return (ret);
	}
}

void		*tiny(size_t size)
{
	void *ret;

	if (g_zone.tiny)
	{
		ret = already_tiny(size);
		return (ret);
	}
	else
	{
		ret = first_tiny(size);
		return (ret);
	}
}

void		*malloc(size_t size)
{
	if (size <= 0)
		return (NULL);
	else if (size < 65)
		return (tiny(size));
	else if (size < 1025)
		return (small(size));
	else
		return (large(size));
}
