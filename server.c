/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomacha <tsomacha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 13:54:02 by tsomacha          #+#    #+#             */
/*   Updated: 2024/12/26 17:59:55 by tsomacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#define _POSIX_C_SOURCE 200809L
#include "minitalk.h"

unsigned char	ft_decode(char *str)
{
	int				count;
	int				result;
	unsigned char	mask;

	count = 7;
	result = 0;
	mask = 0x01;
	while (count >= 0)
	{
		result = result + ((str[count] - '0') * (mask << (7 - count)));
		count--;
	}
	return ((unsigned char)result);
}

void	handle_signal(int signum)
{
	char			buffer[8];
	static int		count;
	unsigned char	ch;
	static char		*str;

	if (!str)
		str = ft_strdup("");
	if (signum == SIGUSR1)
		buffer[count] = '0';
	else if (signum == SIGUSR2)
		buffer[count] = '1';
	count++;
	if (count == 8)
	{
		ch = ft_decode(buffer);
		str = ft_straddchar(str, ch);
		if (ch == '\0')
		{
			ft_printf("%s\n", str);
			str = NULL;
		}
		count = 0;
	}
}

int	main(void)
{
	int					pid;
	struct sigaction	sa;

	sa.sa_flags = 0;
	sa.sa_handler = handle_signal;
	sigemptyset(&sa.sa_mask);
	sigaddset(&sa.sa_mask, SIGINT);
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
