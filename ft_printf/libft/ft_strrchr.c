/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kguillem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:56:30 by kguillem          #+#    #+#             */
/*   Updated: 2024/11/27 20:23:06 by kguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*res;

	res = NULL;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (unsigned char)c)
			res = (char *)&s[i];
		i ++;
	}
	if (s[i] == (unsigned char)c)
		res = (char *)&s[i];
	return (res);
}
/*
#include <stdio.h>

int	main(void)
{
	printf("%p\n", ft_strrchr("test", 'e'));
	printf("%p\n", ft_strrchr("test", 's'));
	printf("%p\n", ft_strrchr("test", 't'));
	printf("%p\n", ft_strrchr("test", '0'));
	return (0);
}*/
