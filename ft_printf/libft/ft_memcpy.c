/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kguillem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:24:35 by kguillem          #+#    #+#             */
/*   Updated: 2024/11/27 17:30:56 by kguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (!dest && !src)
		return (NULL);
	while (i != n)
	{
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dest);
}
/*
int	main(void)
{
	ft_memcpy(((void*)0), ((void*)0), 3);
	printf("%p\n",str1);
	printf("%s\n",str1);
	printf("%p\n",str2);
	printf("%s\n",str2);
	return (0);

}
*/
/*
#include <stdio.h>
int	main(void)
{
	char	str1[] = "test";
	char	str2[] = "goal";

	ft_memcpy(str1, str2, 4);
	printf("%p\n",str1);
	printf("%s\n",str1);
	printf("%p\n",str2);
	printf("%s\n",str2);
	return (0);
}*/
