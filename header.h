/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asekkak <asekkak@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 13:18:42 by asekkak           #+#    #+#             */
/*   Updated: 2022/12/06 15:04:11 by asekkak          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <signal.h>
# include <unistd.h>
# include <stdlib.h>

void	ft_putchar(char c);
void	ft_putstr(char *s);
char	*convert_to_str(int x);
int		convert_str_to_int(char *str);
char	*convert_int_binary(unsigned char c);
void	rec_messg(int sig);

#endif