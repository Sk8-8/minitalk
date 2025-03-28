/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kguillem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 17:38:47 by kguillem          #+#    #+#             */
/*   Updated: 2024/11/27 19:29:51 by kguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size < ft_strlen(src))
		return (ft_strlen(src));
	while (i < size && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (ft_strlen(src));
}
*/

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len;

	len = ft_strlen(src);
	i = 0;
	while (src[i] != '\0' && i + 1 < size)
	{
		dst[i] = src[i];
		i++;
	}
	if (i < size)
		dst[i] = '\0';
	return (len);
}
/*
#include <bsd/string.h>

int	main(void)
{
	int ret = 0;
	char 	src[] = "test";
	char	dst[4];
	char 	src1[] = "test";
	char	dst1[4];
	ret = strlcpy(dst, src, 78);
	printf("%d\n", ret);
	ret = ft_strlcpy(dst1, src1, 78);
	printf("%d\n", ret);
	//printf("%p\n", dst);
	printf("%s\n", dst);
	//printf("%p\n", dst1);
	printf("%s\n", dst1);
	return (0);
}*/
