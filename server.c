/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kguillem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 17:00:41 by kguillem          #+#    #+#             */
/*   Updated: 2025/03/17 21:21:25 by kguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <signal.h>
#include <unistd.h>

static char	*g_msg;
/*
struct	sigaction {
void	(*sa_handler) (int);
void	(*sa_sigaction) (int, siginfo_t *, void *);
sigset_t	SIGINFO;
int	sa_flags;
void	(*sa_restorer) (void);
};
*/
void	msghandler(char *g_msg)
{
	unsigned int	i;
	unsigned int	bit;

struct	sigaction {
void	(*signal_handler) (int);
void	(*sa_sigaction) (int, siginfo_t *, void *);
int	SIGINFO;
sigset_t	SIGINFO;
void	(*sa_restorer) (void);

	i = 0;
	bit = 0;
	while (g_msg)
	{
		while (bit < 7)
		{
			g_msg[i] = g_msg[i] +
			g_msg[i] << 1;
			bit ++;
		}
		g_msg[i] = g_msg[i] +
		bit = 0;
		i ++;
	}
}

void	signal_handler(int signum, siginfo_t *info, ucontext_t *uap)
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
