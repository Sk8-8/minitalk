/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kguillem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:43:54 by kguillem          #+#    #+#             */
/*   Updated: 2024/11/27 19:32:21 by kguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	lendst;
	size_t	lensrc;

	i = 0;
	lendst = ft_strlen(dst);
	lensrc = ft_strlen((char *)src);
	if (size <= lendst)
		return (lensrc + size);
	while (src[i] != '\0' && i < size - lendst - 1)
	{
		dst[i + lendst] = src[i];
		i ++;
	}
	dst[i + lendst] = '\0';
	return (lendst + lensrc);
}
/*
#include <stdio.h>

int	main(void)
{
	const char	*src = "ing";
	char	dst[100] = "test";

	ft_strlcat(dst, src, 10);
	printf("%s\n", dst);
	return (0);
}*/
