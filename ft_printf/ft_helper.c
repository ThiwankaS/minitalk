/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomacha <tsomacha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 08:56:13 by tsomacha          #+#    #+#             */
/*   Updated: 2024/11/28 13:43:08 by tsomacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printchar(int c)
{
	return (write(1, &c, 1));
}

size_t	ft_strlen(const char *s)
{
	size_t	count;

	count = 0;
	while (*(s + count))
	{
		count++;
	}
	return (count);
}

int	ft_printstr(char *str)
{
	int	len;

	if (!str)
		return (write(1, "(null)", 6));
	len = ft_strlen(str);
	return (write(1, str, len));
}

int	ft_printdigit(int c, int set_case)
{
	if (c < 10)
	{
		return (ft_printchar(c + 48));
	}
	else if (c >= 10 && c <= 15)
	{
		if (set_case)
			return (ft_printchar(c + 55));
		else
			return (ft_printchar(c + 87));
	}
	return (-1);
}
