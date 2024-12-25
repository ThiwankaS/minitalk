/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomacha <tsomacha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 13:54:02 by tsomacha          #+#    #+#             */
/*   Updated: 2024/12/23 15:01:46 by tsomacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_signal(int signum)
{
	if (signum == SIGUSR1)
		ft_printf("1");
	if (signum == SIGUSR2)
		ft_printf("0");
}

void	ft_sigaddset(sigset_t *set, int sig1, int sig2, int sig3)
{
	sigaddset(set, sig1);
	sigaddset(set, sig2);
	sigaddset(set, sig3);
}

int	main(void)
{
	int					pid;
	struct sigaction	sa;

	sa.sa_flags = 0;
	sa.sa_handler = handle_signal;
	sigemptyset(&sa.sa_mask);
	ft_sigaddset(&sa.sa_mask, SIGINT, SIGUSR1, SIGUSR2);
	sigaction(SIGINT, &sa, NULL);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	pid = getpid();
	ft_printf("PID : [%d]\n", pid);
	ft_printf("waiting message from the client...\n");
	while (1)
	{
		pause();
	}
	return (0);
}
