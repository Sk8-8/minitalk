/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kguillem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:34:15 by kguillem          #+#    #+#             */
/*   Updated: 2024/11/08 14:57:26 by kguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <strings.h>
#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i != n)
	{
		((unsigned char *)s)[i] = '\0';
		i++;
	}
}
/*
#include <stdio.h>
int	main(void)
{
	char	str[]  = "test";
	ft_bzero(str, 4);
	printf("%p\n", str);
	printf("%s\n", str);
	return (0);
}*/
