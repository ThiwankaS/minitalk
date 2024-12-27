/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomacha <tsomacha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 13:54:02 by tsomacha          #+#    #+#             */
/*   Updated: 2024/12/26 17:34:50 by tsomacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# define WORD_SIZE 8
# define MASK_DEC 0x01
# define MASK_ENC 0x80

# include <signal.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

# include "ft_printf.h"
# include "libft.h"

bool	ft_isvalid(char *str);
char	*ft_straddchar(char *str, char ch);

#endif
