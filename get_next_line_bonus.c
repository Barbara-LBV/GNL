/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 09:32:13 by blefebvr          #+#    #+#             */
/*   Updated: 2022/07/29 18:53:44 by blefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_line(char *tmp)
{
	int		i;
	int		size;
	char	*line;

	size = ft_strlen(tmp) + 1;
	line = malloc(sizeof(char) * size);
	if (!line)
		return (NULL);
	i = 0;
	while (tmp[i] != '\0')
	{
		line[i] = tmp[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*get_cur_line(int fd, ssize_t reader, char *stash, char *tmp)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (stash[i] != '\n' && stash[i] != '\0')
	{
		tmp[j++] = stash[i++];
		if (stash[i] == '\0')
		{
			if (reader == i && reader != BUFFER_SIZE)
				break ;
			i = 0;
			reader = read(fd, stash, BUFFER_SIZE);
			stash[reader] = '\0';
			if (reader == 0)
				break ;
		}
	}
	if (stash[i] == '\n')
		tmp[j++] = '\n';
	tmp[j] = '\0';
	return (get_line(tmp));
}

void	get_remaining_stash(char *stash)
{
	int		i;
	char	*tmp;

	i = 0;
	while (stash[i] != '\n' && stash[i] != '\0')
		i++;
	if ((stash[i] == '\n' && stash[i + 1] == '\0') || stash[i] == '\0')
	{
		clean_var(stash, BUFFER_SIZE);
		return ;
	}
	tmp = &stash[i + 1];
	i = 0;
	while (tmp[i] != '\0')
	{
		stash[i] = tmp[i];
		i++;
	}
	stash[i] = '\0';
	return ;
}

char	*get_next_line(int fd)
{
	char		*line;
	char		tmp[1000000];
	static char	stash[1024][BUFFER_SIZE];
	ssize_t		reader;

	clean_var(tmp, 1000000);
	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	reader = 0;
	if (stash[fd][0] == '\0')
	{
		reader = read(fd, &stash[fd], BUFFER_SIZE);
		if (reader == 0)
			return (NULL);
	}
	line = get_cur_line(fd, reader, stash[fd], tmp);
	if (!line || *line == '\0')
	{
		free(line);
		return (NULL);
	}
	get_remaining_stash(stash[fd]);
	return (line);
}

/*int main()
{
	int fd;
	int l;
	char *line;

	l = 0;
	fd = open("test_fd2", O_RDONLY);
	if (fd < 0)
		printf("error\n");
	while ((line = get_next_line(fd)) != NULL)
	{
		++l;
		printf("%d  %s", l, line);
		free(line);
	}
	fd = close(fd);
	return (0);
}*/
