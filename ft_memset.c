/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prsingh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 15:49:47 by prsingh           #+#    #+#             */
/*   Updated: 2023/03/25 18:14:26 by prsingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char	*p;

	p = (char *)b;
	while (len > 0)
	{
			*p = c;
			p++;
			len --;
	}
	return (b);
}
/*
int main ()
{
	char str[] = "Bananas";

	ft_memset (str, 'Z', 3 *sizeof(char));
	printf("%s\n", str);
	return (0);
}*/
