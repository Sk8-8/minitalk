/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kguillem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 20:48:39 by kguillem          #+#    #+#             */
/*   Updated: 2024/11/26 16:18:22 by kguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	sizer(int n)
{
	int	i;

	i = 1;
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		i ++;
		n = n * -1;
	}
	while (n >= 10)
	{
		n = n / 10;
		i ++;
	}
	return (i);
}

char	*fill(char *str, int n, int index)
{
	long	nu;

	nu = n;
	if (nu < 0)
	{
		str[0] = '-';
		nu = nu * -1;
	}
	if (nu >= 10)
		fill(str, nu / 10, index - 1);
	str[index -1] = (nu % 10) + '0';
	return (str);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		size;

	size = sizer(n);
	str = malloc(sizeof(*str) * (size + 1));
	if (str == NULL)
		return (NULL);
	str = fill(str, n, size);
	str[size] = '\0';
	return (str);
}
/*
#include <stdio.h>

int	main(void)
{
	int	test = -2850;

	printf("%s\n", ft_itoa(test));
	return (0);
}*/
