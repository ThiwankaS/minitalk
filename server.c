/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomacha <tsomacha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 13:54:02 by tsomacha          #+#    #+#             */
/*   Updated: 2025/01/22 17:00:19 by tsomacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static volatile unsigned char	g_signal_data = 0;

void	handle_signal(int sig, siginfo_t *info, void *context)
{
	static int	step;

	(void)context;
	step = 0;
	if (sig == SIGUSR1)
		g_signal_data |= (0 << step);
	else if (sig == SIGUSR2)
		g_signal_data |= (1 << step);
	step++;
	if (step == 8)
	{
		if (g_signal_data == '\0')
			write(1, "\n", 1);
		else
			write(1, (const void *)&g_signal_data, 1);
		g_signal_data = 0;
		step = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	pid_t				pid;
	struct sigaction	sa;

	pid = getpid();
	ft_printf("Server PID: %d\n", pid);
	sa.sa_sigaction = handle_signal;
	sa.sa_flags = SA_SIGINFO | SA_RESTART;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
