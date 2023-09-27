/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_pipex.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerilee <yerilee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 13:02:15 by yerilee           #+#    #+#             */
/*   Updated: 2023/08/25 19:47:42 by yerilee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef M_PIPEX_H
# define M_PIPEX_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

void			child_process(char **argv, char **env, int *fd);
void			parent_process(char **argv, char **env, int *fd);
void			execute_cmd(char *argv, char **env);
char			*get_path(char *cmd, char **env);

int				ft_strlen(const char *s);
char			*ft_strjoin(char *s1, char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_error(char *s);

char			**ft_split_free(char **p);
unsigned int	word_count(char const *s, char c);
char			*word_alloc(char const *s, char c);
char			**ft_split(char const *s, char c);

#endif