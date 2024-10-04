/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prsingh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 14:56:02 by prsingh           #+#    #+#             */
/*   Updated: 2023/04/10 17:25:14 by prsingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	isset(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	len_trim(char const *s1, char const *set)
{
	int	len;
	int	i;
	int	j;

	len = ft_strlen(s1);
	i = 0;
	while (s1[i] && isset(s1[i], set))
	{
			i++;
			len--;
	}
	j = ft_strlen(s1) - 1;
	while (j >= 0 && isset(s1[j], set))
	{
		j--;
		len--;
	}
	if (len < 0)
		len = 0;
	return (len);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*new;
	int		len;
	int		i;
	int		j;

	if (!s1 || !set)
		return (NULL);
	len = len_trim(s1, set);
	new = malloc(sizeof(char) * (len + 1));
	if (!new)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] && isset(s1[i], set))
		i++;
	while (j < len)
	{
		new[j] = s1[i];
		i++;
		j++;
	}
	new[j] = '\0';
	return (new);
}
