/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsignedprint.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prsingh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 20:16:52 by prsingh           #+#    #+#             */
/*   Updated: 2023/05/27 19:54:31 by prsingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	ft_u_len(unsigned int n)
{
	int	len;

	len = 0;
	while (n > 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static char	*ft_unitoa(unsigned int n)
{
	int		len;
	char	*str;

	len = ft_u_len(n);
	str = (char *)malloc((len + 1) * sizeof(char));
	if (str == NULL)
	{
		return (NULL);
	}
	str[len] = '\0';
	while (len > 0)
	{
		len--;
		str[len] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}

int	ft_putstr(char *str)
{
	int	len;

	len = 0;
	while (*str)
	{
		len += write(1, str, 1);
		str++;
	}
	return (len);
}

int	ft_unsignedprint(unsigned int un)
{
	int		pt_len;
	char	*nb;

	pt_len = 0;
	if (un == 0)
	{
		pt_len += write(1, "0", 1);
	}
	else
	{
		nb = ft_unitoa(un);
		pt_len += ft_putstr(nb);
		free(nb);
	}
	return (pt_len);
}
