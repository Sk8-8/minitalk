/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kguillem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 15:01:59 by kguillem          #+#    #+#             */
/*   Updated: 2024/11/25 19:19:45 by kguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*dup;
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(s);
	dup = malloc(sizeof(char) * (len + 1));
	if (dup == NULL)
		return (NULL);
	while (i <= len)
	{
		dup[i] = s[i];
		i ++;
	}
	return (dup);
}
/*
#include <stdio.h>

int	main(void)
{
	const char	*test;

	test = "test";
	printf("%p\n", test);
	printf("%p\n", ft_strdup(test));
	return (0);
}*/
