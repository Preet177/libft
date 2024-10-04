/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stringprint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prsingh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 20:22:55 by prsingh           #+#    #+#             */
/*   Updated: 2023/05/10 15:14:23 by prsingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	ft_stringprint(char *str)
{
	int	len;

	len = 0;
	if (!str)
	{
		str = "(null)";
	}
	while (str[len])
	{
		ft_putchar(str[len]);
		len++;
	}
	return (len);
}
