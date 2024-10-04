/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prsingh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:47:26 by prsingh           #+#    #+#             */
/*   Updated: 2023/06/09 15:44:38 by prsingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int			ft_printf(const char *format, ...);
int			ft_charprint(char c);
int			ft_stringprint(char *str);
int			ft_unsignedprint(unsigned int n);
int			ft_hexprint(unsigned long long n, const char format);
int			ft_intprint(int n);
int			ft_pointerprint(unsigned long long ptr);
int			ft_putchar(char c);
int			ft_putnbr(int n);

#endif
