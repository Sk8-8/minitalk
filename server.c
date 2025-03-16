/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kguillem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 17:00:41 by kguillem          #+#    #+#             */
/*   Updated: 2025/03/16 21:13:02 by kguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <signal.h>
#include <unistd.h>

static char	*g_msg;
// SIGUSR1
// SIGUSR2
// SIGINT
// SIGTERM

struct	sigaction {
void	(*sa_handler) (int);
void	(*sa_sigaction) (int, siginfo_t *, void *);
sigset_t	SIGINFo;
int	sa_flags;
void	(*sa_restorer) (void);
};

void	msghandler(char *g_msg)
{
	unsigned int	i;
	unsigned int	bit;

	i = 0;
	bit = 0;
	while (g_msg)
	{
		while (bit < 7)
		{
			g_msg[i] = g_msg[i] + signal_handler();	
			g_msg[i] << 1;
			bit ++;
		}
		g_msg[i] = g_msg[i] + signal_handler();	
		bit = 0;
		i ++;
	}
}

void	signal_handler(int signum)
{
	int	bit;
	char ascii;

	bit = 0;
	ascii = 0;
	while (bit < 8)
	{
		if (signum == SIGUSR1)
		{
			ascii = ascii + 1;
			ascii << 1;
			bit ++;
		}
		if (signum == SIGUSR2)
		{
			ascii << 1;
			bit ++;
		}
	}
	if (signum == SIGINT || signum == SIGTERM)
		;
	else
		ft_printf("signal received!\n%d\n", signum);
}

void	initialize(void)
{
	int	pid;

	pid = getpid();
	ft_printf("%d", pid); 
	pause();
}

int	main(void)
{
	initialize();
	
}
