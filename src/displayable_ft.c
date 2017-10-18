/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   displayable_ft.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboutin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 16:46:48 by pboutin           #+#    #+#             */
/*   Updated: 2017/10/18 16:54:21 by pboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "malloc.h"

int		ft_putchar(char c)
{
	write(1, &c, 1);
	return (0);
}

void	ft_putstr(const char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

int		ft_ulli_len_base(unsigned long long int nbr, int base)
{
	int result;

	result = 0;
	if (nbr == 0)
		return (1);
	while (nbr != 0)
	{
		nbr /= base;
		result++;
	}
	return (result);
}

char	*ft_addr(void *v)
{
	unsigned long int	nbr;
	int					len;
	char				*str;
	char				*b;

	b = "0123456789abcdef";
	nbr = (unsigned long int)v;
	len = ft_ulli_len_base(nbr, 16) + 2;
	str = (char*)malloc(sizeof(char) * len + 1);
	str[len] = '\0';
	str[0] = '0';
	str[1] = 'x';
	len--;
	if (nbr == 0)
		str[2] = '0';
	while (nbr != 0)
	{
		str[len] = b[nbr % 16];
		len--;
		nbr /= 16;
	}
	return (str);
}

void	ft_putnbr(int n)
{
	if (n == -2147483648)
		ft_putstr("-2147483648");
	else
	{
		if (n < 0)
		{
			ft_putchar('-');
			n = -n;
		}
		if (n >= 10)
		{
			ft_putnbr(n / 10);
			ft_putnbr(n % 10);
		}
		else
		{
			ft_putchar(n + 48);
		}
	}
}
