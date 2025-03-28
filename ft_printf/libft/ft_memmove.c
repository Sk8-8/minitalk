/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kguillem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:35:31 by kguillem          #+#    #+#             */
/*   Updated: 2024/11/15 20:01:53 by kguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if (!dest && !src)
		return (NULL);
	if ((size_t)src <= (size_t)dest)
	{
		while (n > 0)
		{
			((char *)dest)[n - 1] = ((char *)src)[n - 1];
			n--;
		}
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
/*
#include <stdio.h>

int	main(void)
{
	char	str1[] = "test";
	//char	str2[] = "goal";
	printf("%s\n", str1);
	ft_memmove(str1, str1 + 1, 4);
	//printf("%p\n", str1);
	printf("%s\n", str1);
	//printf("%p\n", str2);
	//printf("%s\n", str2);
	return (0);
}
*/