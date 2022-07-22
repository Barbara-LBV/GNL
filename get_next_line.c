/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 09:32:13 by blefebvr          #+#    #+#             */
/*   Updated: 2022/07/22 15:14:44 by blefebvr         ###   ########.fr       */
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
	static char	stash[BUFFER_SIZE];
	char	*buffer;
	int	i;

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
		stash[i] = '\0';
	}
	else if (reader == 0)
	{
		buffer = NULL;
		*stash = *buffer;
	}
	free(buffer);
	return (stash);
}

char	*get_new_line(char *stash, char *line)
{
	size_t	i;
	size_t	j;
	char	*tmp;

	i = 0;
	j = 0;
	while (stash[i] != '\0')
	{
		while (stash[i] != '\n')
			i++;
		tmp = malloc(sizeof(char) * i + 2);
		while (j < i)
		{
			tmp[j] = stash[j];
			j++;
		}
		tmp[j] = '\n';
		tmp[i] = '\0';
		line = join_line(line, tmp);
		//stash = get_remaining_stash(stash, '\n');
		i += 1;
	}
	free(tmp);
	return (line);
}

char	*get_line(char *stash, char *line)
{
	if (!find_sep(stash))
		line = join_line(line, stash);
	else if(find_sep(stash))
	{
		line = get_new_line(stash, line);
	}
	return (line);
}


/*char	*get_next_line(int fd)
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
	static char *stash;
	char *line;

	(void)argc;
	fd = open(argv[1], O_RDONLY);
	stash = read_line(fd);
	printf("%s\n", stash);
	line = get_line(stash, "\0");

	printf("%s\n", line);
	return 0;
}
