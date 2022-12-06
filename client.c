/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cl.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asekkak <asekkak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 13:21:11 by asekkak           #+#    #+#             */
/*   Updated: 2022/12/06 15:44:34 by asekkak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	send_null(int pid)
{
	int	j;

	j = 0;
	while (j < 8)
	{
		kill(pid, SIGUSR2);
		usleep(100);
		j++;
	}
}

void	function_send_signale(int pid, char *string)
{
	int		i;
	int		j;
	char	*str;

	j = 0;
	i = 0;
	while (string[i])
	{
		str = convert_int_binary(string[i]);
		j = 0;
		while (str[j])
		{
			if (str[j] == '1')
				kill(pid, SIGUSR1);
			else if (str[j] == '0')
				kill(pid, SIGUSR2);
			usleep(100);
			j++;
		}
		i++;
	}
	if (string[i] == '\0')
		send_null(pid);
}

int	main(int ac, char **av)
{
	int	pid;

	if (ac != 3)
		return (0);
	signal(SIGUSR2, rec_messg);
	pid = convert_str_to_int(av[1]);
	function_send_signale(pid, av[2]);
	return (0);
}
