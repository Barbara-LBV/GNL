/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 09:32:13 by blefebvr          #+#    #+#             */
/*   Updated: 2022/07/21 17:19:42 by blefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
// ssize_t read(int fd, void *buf, size_t nbyte);

#include "get_next_line.h"

/*static void	free(void *ptr)
{
	
}*/

char	*read_line(int fd)
{
	ssize_t	reader;
	static char	*stash;
	char	*buffer;
	ssize_t	i;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	reader = read(fd, buffer, BUFFER_SIZE);
	i = 0;
	if (reader != 0)
	{
		while (i < reader)
		{
			stash[i] = buffer[i];
			i++;
		}
	}
	if (reader == 0)
	{
		buffer = NULL;
		stash = buffer;
	}
	free(buffer);
	return (stash);
}

char	*check_stash(static char *stash)
{
	if (!find_sep(stash))
	{
		
	}
}

static char	*get_line(char *line, static char *stash)
{
	size_t	i;
	size_t	j;
	char	*tmp;

	i = 0;
	j = 0;
	if (!find_sep(stash))
		line = join_line(line, stash);
	return (line);
}

static char	*get new_line(static char stash, char *line)
{
	size_t	i;

	i = 0;
	while (stash[i] != '\0')
	{
		while (stash[i] != '\n')
			i++;
		tmp = malloc(sizeof(char) * i + 2;
		while (j < i)
			tmp[j++] = stash[j++];
		tmp[j] = '\n';
		tmp[i] = '\0';
		line = join_line(line, tmp);
		stash = get_remaining_stash(stash);
		i += 1;
	}
	free(tmp);
	return (line);
}

static char	*get_new_line(char *stash)
{
	size_t	size;
	size_t	i;

	size = ft_strlen(tmp);
	stash = malloc(sizeof(char *) * size);
	i = 0;
	while (!find_sep(stash))
	{
		
		stash[i++] = tmp[i++];
	free(tmp);
	return (stash);
}

char	*get_next_line(int fd)
{
	char	*line;
	char	*

	line = "\0";
	stash = read_line(fd);
	if (!find_sep(stash))
	{
		line = get_line(line, stash);
		stash = get_clean(stash);
	}
	else
	{
		line = get_new_line(stash);
		stash = get_remaining_stash;
	}
	if (
	return (line);
}*/

/*int	main(int argc, char **argv)
{
	int	fd;
	char	line[30];

	(void)argc;
	fd = open(argv[1], O_RDONLY);
	//while (line != NULL)
	//{
	line = read_line(fd);
	printf("%s", line);
	//}
	fd = close(fd);
	return (0);
}*/

int main(int argc, char **argv)
{
	//int reader;
	int fd;
	//int i;
	//int j;
	static char *line;
	//static char *stash;
	//char buff[BUFFER_SIZE];

	(void)argc;
	fd = open(argv[1], O_RDONLY);
	line = read_line(fd);
	//i = 0;
	/*j = 0;
	reader = read(fd, buff, BUFFER_SIZE);
	if (reader != 0)
	{
		while (i < reader)
		{
			line[i] = buff[i];
			i++;
		}
	}
	if (!find_sep(line))*/
		printf("%s", line);
	return 0;
}
