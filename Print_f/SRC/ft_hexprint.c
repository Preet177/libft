/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prsingh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 20:15:31 by prsingh           #+#    #+#             */
/*   Updated: 2023/08/23 17:07:32 by prsingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_hex_length(unsigned long long n)
{
	int	i;

	i = 0;
	while (n)
	{
		i++;
		n /= 16;
	}
	return (i);
}

void	ft_convert_hex(unsigned long long n, const char format)
{
	if (n >= 16)
	{
		ft_convert_hex(n / 16, format);
		ft_convert_hex(n % 16, format);
	}
	else
	{
		if (n <= 9)
			ft_putchar(n + '0');
		else
		{
			if (format == 'x')
				ft_putchar(n - 10 + 'a');
			else if (format == 'X')
				ft_putchar(n - 10 + 'A');
		}
	}
}

int	ft_hexprint(unsigned long long n, const char format)
{
	if (n == 0)
		return (ft_putchar('0'));
	else
	{
		ft_convert_hex(n, format);
		return (ft_hex_length(n));
	}
}
