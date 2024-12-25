/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomacha <tsomacha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 13:54:02 by tsomacha          #+#    #+#             */
/*   Updated: 2024/12/23 15:01:46 by tsomacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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
	kill(pid, SIGUSR2);
	ft_printf("PID : %d\n", pid);
	ft_printf("String : %s\n", str);
	return (0);
}
