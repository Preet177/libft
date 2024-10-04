/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prsingh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 18:27:56 by prsingh           #+#    #+#             */
/*   Updated: 2023/04/10 12:34:05 by prsingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(const char *str, char c)
{
	int	i;
	int	hit;
	int	count;

	i = 0;
	hit = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] != c && hit == 0)
		{
			hit = 1;
			count++;
		}
		else if (str[i] == c)
			hit = 0;
			i++;
	}
	return (count);
}

char	*ft_strndup(const char *s, size_t n)
{
	char	*str;
	size_t	i;

	str = (char *)malloc(sizeof(char ) * (n + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (i < n)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	i;
	size_t	j;
	size_t	start;
	int		count;

	if (!s)
		return (NULL);
	count = ft_count(s, c);
	split = (char **)malloc(sizeof(char *) * (count + 1));
	if (!split)
		return (NULL);
	i = 0;
	j = 0;
	while (j < (size_t)count)
	{
		while (s[i] == c)
			i++;
		start = i;
		while (s[i] != c && s[i])
			i++;
		split[j++] = ft_strndup(s + start, i - start);
	}
	split[j] = NULL;
	return (split);
}
