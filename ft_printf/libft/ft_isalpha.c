/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kguillem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 12:34:32 by kguillem          #+#    #+#             */
/*   Updated: 2024/11/15 17:03:40 by kguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (1);
	else
		return (0);
}
/*

#include <unistd.h>
int	main(void)
{
	int	i;

	i = ft_isalpha('?');
	if (i == 1)
		write(1, "1", 1);
	else
		write(1, "Nuhuh", 5);
	return (0);
}*/
