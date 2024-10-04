/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prsingh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 15:11:19 by prsingh           #+#    #+#             */
/*   Updated: 2023/05/31 17:11:11 by prsingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_handle_specifier(va_list args, const char format)
{
	int	len;

	len = 0;
	if (format == '%')
		len += ft_putchar('%');
	else if (format == 'c')
		len += ft_charprint(va_arg(args, int));
	else if (format == 's')
		len += ft_stringprint(va_arg(args, char *));
	else if (format == 'p')
		len += ft_pointerprint(va_arg(args, unsigned long long));
	else if (format == 'd' || format == 'i')
		len += ft_intprint(va_arg(args, int));
	else if (format == 'u')
		len += ft_unsignedprint(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		len += ft_hexprint(va_arg(args, unsigned int), format);
	return (len);
}

int	ft_printf(const char *format, ...)
{
	int			printed_chars;
	va_list		args;
	int			i;

	printed_chars = 0;
	i = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			printed_chars += ft_handle_specifier(args, format[i + 1]);
			i++;
		}
		else
			printed_chars += ft_putchar(format[i]);
		i++;
	}
	va_end(args);
	return (printed_chars);
}
/*
#include <stdio.h>

int main()
{
	printf(" %lx ", LONG_MAX);
	ft_printf(" %x ", LONG_MAX);

	printf(" %lx ", LONG_MIN);
	ft_printf(" %x ", LONG_MIN);

	printf(" %lx ", ULONG_MAX);
	ft_printf(" %x ", ULONG_MAX);

	printf("%llx\n", 9223372036854775807LL);
	ft_printf("%x\n", 9223372036854775807LL);
}
		int printed_chars;

	printed_chars = ft_printf("%s\n", "Hello, world!");
	ft_printf("Printed characters: %d\n", printed_chars);

	unsigned int num = 12345;
	printed_chars = ft_printf(" %u\n", num);
	ft_printf("Printed characters: %d\n", printed_chars);

	return 0;
} */
