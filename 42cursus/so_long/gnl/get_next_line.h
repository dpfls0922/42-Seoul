/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerilee <yerilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 17:33:44 by yerilee           #+#    #+#             */
/*   Updated: 2023/07/28 20:14:34 by yerilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4242
# endif

# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*get_one_line(int fd, char *buf, char **backup);
char	*read_line(char *buf, char **backup);
char	*extract_line(char	*backup);
char	*meet_eof(char *buf, char **backup);

int		ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char *s1, char *s2, int len1, int len2);
char	*ft_strchr(const char *s, int c);
void	ft_free(char **p);

#endif