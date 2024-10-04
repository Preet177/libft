/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prsingh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 12:21:11 by prsingh           #+#    #+#             */
/*   Updated: 2023/04/10 17:58:00 by prsingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*a;	
	char	*b;
	size_t	i;

	if (!dst && !src)
		return (NULL);
	a = (char *)dst;
	b = (char *)src;
	i = 0;
	while (i < len)
	{
		if (dst > src)
				a[len - 1 - i] = b[len - 1 - i];
		else
				a[i] = b [i];
			i++;
	}
	return (dst);
}
