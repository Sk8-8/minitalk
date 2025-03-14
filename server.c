/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kguillem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 17:00:41 by kguillem          #+#    #+#             */
/*   Updated: 2025/03/14 19:59:40 by kguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <signal.h>
#include <unistd.h>

static char	*msg; //

void	signal_handler(int	signum)
{
	ft_printf("%s", "signal received!\n");
	ft_printf("%d", signum);
}

int	initialize(void)
{
	int	pid;

	pid = getpid(void);
	ft_printf("%d",pid);
	//sigaction(SIGUSR1, 
	return (0);
}


int	main(void)
{
	initialize;
}
