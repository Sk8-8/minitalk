/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kguillem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:30:33 by kguillem          #+#    #+#             */
/*   Updated: 2024/11/07 19:06:32 by kguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i != n)
	{
		((unsigned char *)s)[i] = c;
		i++;
	}
	return (s);
}
/*

#include <stdio.h>
int	main(void)
{
	char	str[] = "test";
	ft_memset(str, 75, 4);
	printf("%p\n", str);
	printf("%s\n", str);
	return (0);
}*/
