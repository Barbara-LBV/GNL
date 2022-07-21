/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 09:23:33 by blefebvr          #+#    #+#             */
/*   Updated: 2022/07/21 17:03:58 by blefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>

//static size_t	ft_strlen(const char *s);
//static char	*ft_strcat(const char *dest, const char *src);
char	*find_sep(char *stash);
//static char	*get_remaining_stash(char *stash, char sep);
char	*join_line(char *line, char *stash);

#endif
