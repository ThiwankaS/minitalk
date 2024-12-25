/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomacha <tsomacha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 13:54:02 by tsomacha          #+#    #+#             */
/*   Updated: 2024/12/23 15:01:46 by tsomacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

bool	ft_isvalid(char *str)
{
	int	count;

	count = 0;
	while (str && str[count])
	{
		if (!ft_isdigit(str[count]))
			return (false);
		count++;
	}
	return (true);
}
