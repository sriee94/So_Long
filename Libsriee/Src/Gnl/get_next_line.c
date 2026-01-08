/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sariee <sariee@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 14:14:27 by sariee            #+#    #+#             */
/*   Updated: 2026/01/01 18:46:27 by sariee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libsriee.h"

static char	*extract_line(char *stash)
{
	int		i;
	char	*line;

	if (!stash || !stash[0])
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\n')
		line = ft_substr(stash, 0, i + 1);
	else
		line = ft_substr(stash, 0, i);
	return (line);
}

static char	*update_stash(char *stash)
{
	int		i;
	char	*new_stash;

	if (!stash)
		return (NULL);
	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (stash[i] == '\0')
	{
		free(stash);
		return (NULL);
	}
	new_stash = ft_strdup(stash + i + 1);
	free(stash);
	if (new_stash && new_stash[0] == '\0')
	{
		free(new_stash);
		new_stash = NULL;
	}
	return (new_stash);
}

char	*ft_read(int fd, char *stash)
{
	char	buffer[BUFFER_SIZE + 1];
	char	*tmp;
	int		bytes;

	bytes = 1;
	while (!ft_strchr(stash, '\n') && bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes == -1)
		{
			free(stash);
			return (NULL);
		}
		buffer[bytes] = '\0';
		tmp = ft_strjoin(stash, buffer);
		free(stash);
		stash = tmp;
	}
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
	{
		if (fd < 0 && stash)
		{
			free(stash);
			stash = NULL;
		}
		return (NULL);
	}
	stash = ft_read(fd, stash);
	if (!stash)
		return (NULL);
	line = extract_line(stash);
	if (!line)
	{
		free(stash);
		stash = NULL;
	}
	else
		stash = update_stash(stash);
	return (line);
}
/*#include <fcntl.h> // open
#include <stdio.h> // printf

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("giant_line.txt", O_RDONLY);
	if (fd < 0)
	{
		perror("Erreur d'ouverture");
		return (1);
	}
	line = get_next_line(fd);
	while (line)
	{
		printf(">>> %s", line); // pas de \n car gnl le garde
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}*/
