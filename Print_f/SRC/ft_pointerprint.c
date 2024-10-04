/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointerprint.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prsingh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 19:44:35 by prsingh           #+#    #+#             */
/*   Updated: 2023/05/27 16:29:49 by prsingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	ft_ptrlen(uintptr_t n)
{
	int	len;

	len = 0;
	while (n != 0)
	{
		n /= 16;
		len++;
	}
	return (len);
}

static void	ft_write_ptr(uintptr_t n)
{
	if (n >= 16)
	{
		ft_write_ptr(n / 16);
		ft_write_ptr(n % 16);
	}
	else if (n <= 9)
	{
		ft_putchar(n + 48);
	}
	else
	{
		ft_putchar(n - 10 + 97);
	}
}

int	ft_pointerprint(unsigned long long ptr)
{
	int	printed_chars;

	printed_chars = 0;
	printed_chars += write (1, "0x", 2);
	if (ptr == 0)
	{
		printed_chars += write(1, "0", 1);
	}
	else
	{
		ft_write_ptr(ptr);
		printed_chars += ft_ptrlen(ptr);
	}
	return (printed_chars);
}	
