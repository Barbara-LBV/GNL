/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 09:32:13 by blefebvr          #+#    #+#             */
/*   Updated: 2022/07/05 17:43:32 by blefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
// ssize_t read(int fd, void *buf, size_t nbyte);

#include "get_next_line.h"

void	free(void *ptr)
{
	
}

char	*read_line(int fd)
{
	ssize_t	reader;
	static char	*stash;
	char	*buffer;
	unsigned int	i;

	i = 0;
	buffer = malloc(sizeof *buffer * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);

	reader = read(fd, buffer, BUFFER_SIZE);
	while (reader != 0)
	{
		stash[i] = buffer[i];
		i++; 
		reader--;
	}
	return (stash);
}

char	*get_line(static char *stash)
{
	unsigned int	i;
	char	*line;

	i = 0;
	while (stash[i] != '\n')
	{
		line[i] = stash[i];
		i++;
	}
	return (line);
}

char	*keep_stash(static char *stash)
{
	char	*stash;
	unsigned int	i;

	
	return (stash);
}

char	*get_next_line(int fd)
{
	char	*next_line;
	

	return (next_line);
}

int	main(int argc, char **argv)
{
	int	fd;
	char	*line;

	(void)argc;
	fd = open(argv[1], O_RDONLY);
	line = "";
	while (line != NULL)
	{
		line = get_next_line(fd);
		printf("%s", line);
	}
	fd = close(fd);
	return (0);
}
