/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomacha <tsomacha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 13:54:02 by tsomacha          #+#    #+#             */
/*   Updated: 2024/12/26 17:32:40 by tsomacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*ft_encode(unsigned char c)
{
	int				count;
	char			*result;
	unsigned char	mask;

	count = 0;
	mask = 0x80;
	result = malloc(8 * sizeof(char));
	if (!result)
		return (NULL);
	while (count < 8)
	{
		if (c & mask)
			result[count] = '1';
		else
			result[count] = '0';
		count++;
		mask = mask >> 1;
	}
	return (result);
}

void	ft_sendnull(char *str, int pid)
{
	int	count;

	count = 0;
	while (count < 8)
	{
		if (str[count] - '0' == 0)
			kill(pid, SIGUSR1);
		if (str[count] - '0' == 1)
			kill(pid, SIGUSR2);
		usleep(100);
		count++;
	}
}

void	ft_sendmessage(char *str, int pid)
{
	static int	count;
	static int	step;
	static char	*msg;

	count = 0;
	while (str && str[count])
	{
		msg = ft_encode(str[count]);
		step = 0;
		while (step < 8)
		{
			if (msg[step] - '0' == 0)
				kill(pid, SIGUSR1);
			if (msg[step] - '0' == 1)
				kill(pid, SIGUSR2);
			usleep(100);
			step++;
		}
		free(msg);
		count++;
	}
	ft_sendnull(ft_encode('\0'), pid);
}

int	main(int argc, char *argv[])
{
	int		pid;
	char	*str;

	if (argc != 3)
	{
		ft_printf("Invalid format : ./client <PID> <string>\n");
		return (0);
	}
	if (!ft_isvalid(argv[2]))
	{
		ft_printf("PID contains invalid characters!\n");
		return (0);
	}
	pid = ft_atoi(argv[2]);
	str = argv[1];
	ft_sendmessage(str, pid);
	return (0);
}
