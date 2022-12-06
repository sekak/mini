/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cllll.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asekkak <asekkak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 14:52:26 by asekkak           #+#    #+#             */
/*   Updated: 2022/12/06 15:44:50 by asekkak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	convert_str_to_int(char *str)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + str[i] - 48;
		i++;
	}
	if (str[i])
	{
		write(1, "error PID\n", 10);
		exit(1);
	}
	return (res);
}

char	*convert_int_binary(unsigned char c)
{
	int			i;
	static char	str[9];

	i = 7;
	while (i >= 0)
	{
		str[i] = "01"[c % 2];
		c /= 2;
		i--;
	}
	return (str);
}

void	rec_messg(int sig)
{
	(void)sig;
	write(1, "recieved message", 17);
}
