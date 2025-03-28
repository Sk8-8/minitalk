/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kguillem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 17:11:04 by kguillem          #+#    #+#             */
/*   Updated: 2025/01/24 18:51:01 by kguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	ptrprint(unsigned long long int ptr)
{
	unsigned long long int	remainder;
	char					c;
	char					digit;
	int						len;

	len = 1;
	c = 'a';
	digit = '0';
	remainder = ptr % 16;
	if (ptr > 15)
	{
		len += ptrprint(ptr / 16);
	}
	if (remainder > 9)
	{
		ft_putchar_fd((c + remainder - 10), 1);
	}
	else
	{
		ft_putchar_fd((digit + remainder), 1);
	}
	return (len);
}

int	ptrval(void *ptr)
{
	if (ptr == NULL)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	else
	{
		ft_putstr_fd("0x", 1);
		return (2 + ptrprint((unsigned long long int)ptr));
	}
}

int	lowhex(unsigned int nbr)
{
	unsigned int			remainder;
	char					c;
	char					digit;
	int						len;

	len = 1;
	c = 'a';
	digit = '0';
	remainder = nbr % 16;
	if (nbr > 15)
	{
		len += lowhex(nbr / 16);
	}
	if (remainder > 9)
	{
		ft_putchar_fd((c + remainder - 10), 1);
	}
	else
	{
		ft_putchar_fd((digit + remainder), 1);
	}
	return (len);
}

int	upphex(unsigned int nbr)
{
	unsigned int			remainder;
	char					c;
	char					digit;
	int						len;

	len = 1;
	c = 'A';
	digit = '0';
	remainder = nbr % 16;
	if (nbr > 15)
	{
		len += upphex(nbr / 16);
	}
	if (remainder > 9)
	{
		ft_putchar_fd((c + remainder - 10), 1);
	}
	else
	{
		ft_putchar_fd((digit + remainder), 1);
	}
	return (len);
}
