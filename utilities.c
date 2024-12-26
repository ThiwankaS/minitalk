/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomacha <tsomacha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 13:54:02 by tsomacha          #+#    #+#             */
/*   Updated: 2024/12/26 17:36:08 by tsomacha         ###   ########.fr       */
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

char	*ft_straddchar(char *str, char ch)
{
	char	*buffer;
	int		length;
	int		count;

	count = 0;
	if (!str)
		length = 0;
	else
		length = ft_strlen((const char *)str);
	buffer = malloc((length + 2) * sizeof(char));
	if (!buffer)
		return (NULL);
	while (str && str[count])
	{
		buffer[count] = str[count];
		count++;
	}
	buffer[count] = ch;
	buffer[count + 1] = '\0';
	if (str)
		free(str);
	return (buffer);
}
