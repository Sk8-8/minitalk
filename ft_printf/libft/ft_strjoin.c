/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kguillem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 18:00:07 by kguillem          #+#    #+#             */
/*   Updated: 2024/11/16 15:38:11 by kguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	size_t	i;
	size_t	s1len;
	size_t	s2len;

	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	i = 0;
	join = malloc((sizeof(char)) * (s1len + s2len + 1));
	if (join == NULL)
		return (NULL);
	while (i <= s1len)
	{
		join[i] = s1[i];
		i ++;
	}
	i = 0;
	while (i <= s2len)
	{
		join[s1len + i] = s2[i];
		i ++;
	}
	join[s1len + i] = '\0';
	return (join);
}
/*
#include <stdio.h>

int	main(void)
{
	printf("%s\n", ft_strjoin("test", "ing"));
	printf("%p\n", ft_strjoin("test", "ing"));
	return (0);
}*/
