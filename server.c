/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kguillem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 17:00:41 by kguillem          #+#    #+#             */
/*   Updated: 2025/03/14 22:55:14 by kguillem         ###   ########.fr       */
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

void	signal_handler(int signum)
{
	sigaction();
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
