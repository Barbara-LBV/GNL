/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 09:23:33 by blefebvr          #+#    #+#             */
/*   Updated: 2022/07/22 14:57:04 by blefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>

size_t	ft_strlen(const char *s);
char	*ft_strcat(const char *dest, const char *src);
int	find_sep(char *stash);
char	*get_remaining_stash(char *stash, char sep);
char	*join_line(char *line, char *stash);

#endif
