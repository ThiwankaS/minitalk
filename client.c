/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomacha <tsomacha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 13:54:02 by tsomacha          #+#    #+#             */
/*   Updated: 2025/01/23 18:24:29 by tsomacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static volatile int	g_received = 0;

void	response_handler(int signum)
{
	if (signum == SIGUSR1)
		g_received = 1;
}

void	ft_error(void)
{
	ft_printf("Message sending failed : Invalid PID!\n");
	exit(0);
}

void	ft_encode(pid_t pid, char c)
{
	int	count;

	count = 0;
	while (count < 8)
	{
		g_received = 0;
		if ((c >> count) & 1)
		{
			if (kill(pid, SIGUSR2) < 0)
				ft_error();
		}
		else
		{
			if (kill(pid, SIGUSR1) < 0)
				ft_error();
		}
		while (!g_received)
			pause();
		count++;
	}
}

void	ft_send_message(pid_t pid, char *str)
{
	int	count;

	count = 0;
	while (str && str[count])
	{
		ft_encode(pid, str[count]);
		count++;
	}
	ft_encode(pid, '\0');
}

int	main(int argc, char *argv[])
{
	pid_t	pid;
	char	*str;

	if (argc != 3)
	{
		ft_printf("Invalid format : ./client <PID> <string>\n");
		return (0);
	}
	if (!ft_isvalid(argv[1]))
	{
		ft_printf("PID contains invalid characters!\n");
		return (0);
	}
	pid = ft_atoi(argv[1]);
	str = argv[2];
	signal(SIGUSR1, response_handler);
	ft_send_message(pid, str);
	if (g_received)
		ft_printf("message send succesfully!\n");
	return (0);
}
