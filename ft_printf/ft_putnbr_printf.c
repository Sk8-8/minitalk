/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_printf.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kguillem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 14:05:42 by kguillem          #+#    #+#             */
/*   Updated: 2025/01/27 20:16:26 by kguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	putchar_printf(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putnbr_printf(int n)
{
	int		len;
	char	c;

	len = 0;
	if (n == -2147483648)
	{
		len += write(1, "-2147483648", 11);
		return (len);
	}
	if (n < 0)
	{
		len += write(1, "-", 1);
		n = n * -1;
	}
	if (n >= 10)
	{
		len += ft_putnbr_printf(n / 10);
	}
	c = (n % 10) + '0';
	len += write(1, &c, 1);
	return (len);
}

int	ft_putstr_printf(char *str)
{
	int		i;

	i = 0;
	if (str == NULL)
	{
		i = 6;
		write(1, "(null)", 6);
	}
	else
	{
		while (str[i])
		{
			i += write(1, &str[i], 1);
		}
	}
	return (i);
}

int	ft_putunnbr_printf(unsigned int n)
{
	char	c;
	int		len;

	len = 0;
	if (n >= 10)
	{
		len += ft_putunnbr_printf(n / 10);
	}
	c = (n % 10) + '0';
	len += write(1, &c, 1);
	return (len);
}
