/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kguillem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 17:09:30 by kguillem          #+#    #+#             */
/*   Updated: 2025/03/14 19:59:49 by kguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <signal.h>
#include <unistd.h>

int	atoi(char	*str)
{
	int	num;
	int	i;
	int	sign;

	num = 0;
	i = 0;
	sign = 1;
	while(str[i] != '\0')
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
/*
void	convsender(int pid, char ascii)
{
	kill(pid, SIGUSR1); // 1
	kill(pid, SIGUSR2); // 0
}
*/
void	ending(int pid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		kill(pid, SIGUSR2); // 0
		i ++;
		usleep(4000);
	}
}

int	main(int argc,char **argv)
{
	int	pid;
	int	i;

	if (argc != 3)
		return (0);
	else
	{
		pid = atoi(argv[1]);
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
