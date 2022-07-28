/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 09:32:13 by blefebvr          #+#    #+#             */
/*   Updated: 2022/07/27 14:44:42 by blefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_cur_line(char *tmp)
{
	int	i;
	char	*line;

	line = malloc(sizeof(char) * ft_strlen(tmp) + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (tmp[i++] != '\0')
		tmp[i] = line[i];
	line[i] = '\0';
	return (line);
}

char	*read_line(int fd, ssize_t reader, char *stash, char *tmp)
{
	int	i;
	int	j;
	char	*line;

	i = 0;
	j = 0;
	line = NULL;
	while (reader > 0)
	{
		reader = read(fd, stash, BUFFER_SIZE);
		while (stash[i] != '\n' && stash[i] != '\0')
			tmp[j++] = stash[i++];
		if (find_sep(stash) || stash[i] =='\0')
			break ;
		i = 0;
	}
	if (stash[i] == '\n')
		tmp[j++] = '\n';
	tmp[j] = '\0';
	line = get_cur_line(tmp);
	clean_tmp(tmp, 10000);
	return (line);
}

void	get_remaining_stash(char *stash)
{
	int	i;
	char	*tmp;

	i = 0;
	while (stash[i++] != '\0' || stash[i++] != '\n')
	{
		if (stash[i] == '\0' || (stash[i] == '\n' && stash[i + 1] == '\0'))
		{
			stash[0] = '\0';
			return ;
		}
	}
	tmp = &stash[i + 1];
	i = 0;
	while (tmp[i++] != '\0')
		stash[i] = tmp[i];
	stash[i] = '\0';
	return ;
}

char	*get_next_line(int fd)
{
	char	*line;
	char	tmp[10000];
	static char	stash[BUFFER_SIZE];
	ssize_t	reader;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (stash[0] == '\0')
		reader = read(fd, stash, BUFFER_SIZE);
	line = read_line(fd, reader, stash, tmp);
	if (!line || *line == '\0')
		return (NULL);
	get_remaining_stash(stash);
	return (line);
}

int main()
{
	int fd;
	int l;
	char *line;

	l = 0;
	fd = open("test_fd", O_RDONLY);
	while ((line = get_next_line(fd)) != NULL)
	{
		++l;
		printf("%d  %s\n", l, line);
		free(line);
	}
	return (0);
}
