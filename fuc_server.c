/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serrrr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asekkak <asekkak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 14:49:24 by asekkak           #+#    #+#             */
/*   Updated: 2022/12/06 15:45:15 by asekkak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		ft_putchar(s[i]);
		i++;
	}
}

char	*convert_to_str(int x)
{
	static char	str[10];
	char		tmp;
	int			i;
	int			j;

	j = 0;
	i = 0;
	while (x > 0)
	{
		str[i++] = (x % 10) + 48;
		x /= 10;
	}
	--i;
	while (j < i)
	{
		tmp = str[j];
		str[j] = str[i];
		str[i] = tmp;
		j++;
		i--;
	}
	str[j + i + 1] = '\0';
	return (str);
}
