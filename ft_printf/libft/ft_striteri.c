/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kguillem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 12:20:13 by kguillem          #+#    #+#             */
/*   Updated: 2024/11/16 15:13:05 by kguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	if (s && f)
	{
		while (*s)
		{
			f(i, s);
			i++;
			s++;
		}
	}
}
/*
#include <stdio.h>

void	test(unsigned int i, char *c)
{
	if (c[i] >= '0' && c[i] <= '9')
		printf("%c\n", c[i]);
}

int	main(void)
{
	char	*str = "0123456789";
	ft_striteri(str, &test);
	return (0);
}*/
