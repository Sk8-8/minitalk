/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kguillem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 17:00:41 by kguillem          #+#    #+#             */
/*   Updated: 2025/03/29 17:42:35 by kguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include "ft_printf/ft_printf.h"

static char	g_octet;

char	*oneupper(char *str)
{
	char	*expanded;
	int		i;

	i = 0;
	if (str == NULL)
	{
		expanded = malloc(sizeof(char) * 2);
		expanded[i + 1] = '\0';
	}
	else
	{
		while (str[i] != '\0')
			i ++;
		expanded = malloc(sizeof(char) * (i + 2));
		expanded[i + 1] = '\0';
		while (i - 1 != 0)
		{
			expanded[i - 1] = str[i - 1];
			i --;
		}
		expanded[i - 1] = str[i - 1];
	}
	return (expanded);
}

void	bitoperation(int signum)
{
	if (signum == SIGUSR1)
	{
		g_octet = g_octet + 1;
	}
	if (signum == SIGUSR2)
	{
		g_octet = g_octet + 0;
	}
}

int	endmsg(char	*msg)
{
	ft_printf("%s\n", msg);
	free(msg);
	return (0);
}

void	signal_handler(int signum)
{
	static char		*msg = NULL;
	static int		i = 0;
	static int		bit = 0;

	if (bit < 7)
	{
		if (bit == 0)
			g_octet = '\0';
		bitoperation(signum);
		g_octet = g_octet << 1;
		bit ++;
	}
	else
	{
		bitoperation(signum);
		msg = oneupper(msg);
		msg[i] = g_octet;
		bit = 0;
		if (g_octet == '\0')
			i = endmsg(msg);
		else
			i ++;
	}
}

int	main(void)
{
	struct sigaction	signalusr;
	int					pid;

	pid = getpid();
	ft_printf("%d\n", pid);
	signalusr.sa_handler = signal_handler;
	signalusr.sa_flags = 0;
	sigemptyset(&signalusr.sa_mask);
	sigaction(SIGUSR1, &signalusr, NULL);
	sigaction(SIGUSR2, &signalusr, NULL);
	while (1)
		pause();
	exit(1);
	return (0);
}
