/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prsingh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 21:03:35 by prsingh           #+#    #+#             */
/*   Updated: 2023/06/18 11:12:19 by prsingh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int		i;
	int		bytes_read;
	char	character;
	char	line_buffer[7000000];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	i = 0;
	bytes_read = read(fd, &character, 1);
	while (bytes_read > 0)
	{
		line_buffer[i] = character;
		i++;
		if (character == '\n')
			break ;
		bytes_read = read(fd, &character, 1);
	}
	line_buffer[i] = '\0';
	if (bytes_read <= 0 && i == 0)
		return (NULL);
	return (ft_strdup(line_buffer));
}

/*
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
	int fd = open("input.txt", O_RDONLY);
	if (fd == -1)
	{
		perror("Failed to open file");
		return (1);
	}

	char *line;

	while ((line = get_next_line(fd)) != NULL)
	{
		printf("%s\n", line);
		free (line);
	}
	close (fd);
	return (0);
}
*/
