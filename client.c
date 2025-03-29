/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kguillem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 17:09:30 by kguillem          #+#    #+#             */
/*   Updated: 2025/03/29 15:25:19 by kguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include "ft_printf/ft_printf.h"

int	clientatoi(char	*str)
{
	int	num;
	int	i;
	int	sign;

	num = 0;
	i = 0;
	sign = 1;
	while (str[i] != '\0')
	{
		if (str[i] == '-')
		{
			sign = -1;
			i ++;
		}
		num = (num * 10) + (str[i] - '0');
		i ++;
	}
	return (num * sign);
}

void	convsender(int pid, char ascii)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		if ((ascii << bit) & 128)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(800);
		bit ++;
	}
}

void	ending(int pid)
{
	int	bit;

	bit = 0;
	while (bit < 8)
	{
		kill(pid, SIGUSR2);
		bit ++;
		usleep(800);
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	if (argc != 3)
	{
		ft_printf("invalid number of args");
		return (0);
	}
	else
	{
		pid = clientatoi(argv[1]);
		i = 0;
		while (argv[2][i] != '\0')
		{
			convsender(pid, argv[2][i]);
			i ++;
		}
		ending(pid);
		return (1);
	}
}
