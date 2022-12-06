/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ser.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asekkak <asekkak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 13:21:26 by asekkak           #+#    #+#             */
/*   Updated: 2022/12/06 15:44:28 by asekkak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	power(int pow)
{
	int	res;

	res = 1;
	while (pow > 0)
	{
		res = 2 * res;
		pow--;
	}
	return (res);
}

void	convert_binary_to_decimal(char *binary, int pid)
{
	int	pow;
	int	num;

	(void)pid;
	num = 0;
	pow = 0;
	while (binary[pow])
	{
		num += (binary[pow] - 48) * (power(7 - pow));
		pow++;
	}
	if (num == '\0')
		kill(pid, SIGUSR2);
	ft_putchar(num);
}

void	function_handle(int sig, siginfo_t *info, void *c)
{
	static char	s[9];
	static int	count;

	(void)c;
	if (sig == SIGUSR1)
		s[count] = '1';
	else if (sig == SIGUSR2)
		s[count] = '0';
	count++;
	if (count == 8)
	{
		convert_binary_to_decimal(s, info->si_pid);
		count = 0;
	}
}

int	main(int ac, char **av)
{
	struct sigaction	sa;
	pid_t				pid;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = function_handle;
	pid = getpid();
	ft_putstr(convert_to_str(pid));
	ft_putchar('\n');
	sigaction(SIGUSR2, &sa, NULL);
	sigaction(SIGUSR1, &sa, NULL);
	(void)av;
	(void)ac;
	while (1)
		pause();
}
