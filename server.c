/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kguillem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 17:00:41 by kguillem          #+#    #+#             */
/*   Updated: 2025/03/21 21:51:28 by kguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

static char	g_octet;

struct	sigaction {
	void	(*sa_handler) (int);
	void	(*sa_sigaction) (int, siginfo_t *,  void *);
	sigset_t	sa_mask;
	int		sa_flags;
	void	(*sa_restorer) (void);
};

void	signal_handler(int signum)
{
	if (signum == SIGUSR1)
		g_octet = g_octet + 1;
	if (signum == SIGUSR2)
		g_octet = g_octet + 0;
}

char	*oneupper(char	*msg)
{
	char	*oneupper;
	int		i;

	i = 0;
	while (msg)
		i ++;
	oneupper = malloc(sizeof(char) * (i + 1));
	if (oneupper == NULL)
		return (NULL);
	while (i != 0)
	{
		oneupper[i] = msg[i];
		i --;
	}
	free(msg);
	return (oneupper);
}

char	*msghandler(void)
{
	char	*msg;
	int		i;
	int		bit;

	i = 0;
	bit = 0;
	g_octet = '?';
	while (g_octet != '\0')
	{
		g_octet = '\0';
		msg = oneupper(msg);
		while (bit < 7)
		{
			signal_handler();
			g_octet = g_octet << 1;
			bit ++;
		}
		signal_handler();
		msg[i] = g_octet;
		bit = 0;
		i ++;
	}
	return (msg);
}

void	initialize(void)
{
	int	pid;

	pid = getpid();
	printf("%d", pid);
	pause();
}

int	main(void)
{
	char	*msg;

	initialize();
	while (1)
	{
		msg = msghandler();
		printf("%s\n", msg);
	}
}
