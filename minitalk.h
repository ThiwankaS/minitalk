/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsomacha <tsomacha@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 13:54:02 by tsomacha          #+#    #+#             */
/*   Updated: 2025/01/22 17:01:48 by tsomacha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

# include "ft_printf.h"
# include "libft.h"

bool	ft_isvalid(char *str);
void	response_handler(int signum);
void	ft_encode(pid_t server_pid, char c);
void	ft_send_message(pid_t server_pid, char *str);
void	handle_signal(int sig, siginfo_t *info, void *context);

#endif
