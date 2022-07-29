/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blefebvr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/05 09:23:33 by blefebvr          #+#    #+#             */
/*   Updated: 2022/07/29 14:20:11 by blefebvr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>

# define SIZE 4294967295
char	*get_next_line(int fd);
char	*get_cur_line(int fd, ssize_t reader, char *stash, char *tmp);
char	*get_line(char *tmp);
char	*read_line(int fd, ssize_t reader, char *stash, char *tmp);
void	clean_var(char *tmp, int size);
void	get_remaining_stash(char *stash);
size_t	ft_strlen(const char *s);

#endif