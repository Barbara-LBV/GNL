/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 16:18:39 by blefebvr          #+#    #+#             */
/*   Updated: 2022/07/20 18:40:05 by blefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (i);
	while (s[i] != '\0')
		i++;
	return (i);
}

static char	*ft_strcat(const char *dest, const char *src)
{
	size_t	i;
	size_t	j;
	char	*d;
	char	*s;

	d = (char *)dest;
	s = (char *)src;
	i = ft_strlen(d);
	j = 0;
	while (src[j] != '\0')
	{
		d[i] = s[j];
			j++;
			i++;
	}
	d[i] = '\0';
	return ((char *)dest);
}

static size_t	find_sep(char *stash)
{
	size_t	i;

	i = 0;
	while (stash[i])
	{
		if (stash[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
static char	*get_remaining_stash(char *stash, char sep)
{
	int	i;

	i = 0;
	if (find_sep(stash))
	{
		while (stash[i] != '\0')
		{
			if (stash[i] == sep)
				return (&stash[i + 1]);
			i++;
		}
	}
	else if (!find_sep(stash))
		return (stash);
	return (0);
}

static char	*join_line(char *line, char *stash)
{
	unsigned int	size;
	char		*joined;

	size = (ft_strlen(line) + ft_strlen(stash));
	if (size == 0)
	{
		joined = malloc(sizeof(char));
		if (joined == NULL)
			return (0);
		joined[0] = '\0';
		return (joined);
	}
	joined = malloc(sizeof(char) * size + 1);
	if (joined == NULL)
		return (0);
	joined[0] = '\0';
	ft_strcat(joined, line);
	ft_strcat(joined, stash);
	return (joined);
}

int main()
{
	//char s1[] = "Adam,";
	char s2[] = "Salut \ntoi";
	int i = 0;

	while (s2[i] != '\n')
		i++;
	printf("%d\n", i);
	i += 1;
	while (s2[i] != '\0')
		write(1, &s2[i++], 1);
	return (0);
}
