/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kguillem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 18:31:13 by kguillem          #+#    #+#             */
/*   Updated: 2024/11/28 17:24:19 by kguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

size_t	starttrim(char const *s1, char const *set)
{
	size_t	iset;
	size_t	i;

	iset = 0;
	i = 0;
	while (set[iset] != '\0')
	{
		if (s1[i] == '\0')
			return (i);
		if (s1[i] == set[iset])
		{
			i ++;
			iset = 0;
		}
		else
			iset ++;
	}
	return (i);
}

size_t	endtrim(char const *s1, char const *set)
{
	size_t	iset;
	size_t	i;

	iset = 0;
	i = ft_strlen(s1) - 1;
	while (set[iset] != '\0')
	{
		if (i == 0)
			return (0);
		if (s1[i] == set[iset])
		{
			i --;
			iset = 0;
		}
		else
			iset ++;
	}
	return (i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimed;
	size_t	start;
	size_t	end;
	size_t	i;

	i = 0;
	end = endtrim(s1, set);
	start = starttrim(s1, set);
	if (s1[0] == '\0')
		return (ft_strdup(""));
	if (end < start)
	{
		end = 0;
		start = 1;
	}
	trimed = malloc(sizeof(*trimed) * (end - start + 2));
	if (trimed == NULL)
		return (NULL);
	while (i + start <= end)
	{
		trimed[i] = s1[start + i];
		i ++;
	}
	trimed[i] = '\0';
	return (trimed);
}
/*
#include <stdio.h>

int	main(void)
{
	printf("%s\n", ft_strtrim("", "abc"));
	return (0);
}*/
