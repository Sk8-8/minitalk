/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kguillem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 11:50:04 by kguillem          #+#    #+#             */
/*   Updated: 2024/11/16 14:30:29 by kguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	size_t			len;
	unsigned int	i;

	i = 0;
	len = ft_strlen(s);
	str = malloc(sizeof(*str) * (len + 1));
	if (str == NULL)
		return (NULL);
	while (i < len)
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
/*
#include <stdio.h>

char	test(unsigned int i, char c)
{
	(void)i;
	if (c >= 'A' && c <= 'Z')
		c = c -17;
	return (c);
}

int	main(void)
{
	printf("%s\n", ft_strmapi("TEST", &test));
	return (0);
}*/
