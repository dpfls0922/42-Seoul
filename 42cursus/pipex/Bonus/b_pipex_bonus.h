/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_pipex_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerilee <yerilee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 20:57:23 by yerilee           #+#    #+#             */
/*   Updated: 2023/08/26 21:55:56 by yerilee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef B_PIPEX_BONUS_H
# define B_PIPEX_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

int				file_open(char *file, int i);
void			get_pipe_and_exec(char *cmd, char **env);
void			execute_cmd(char *argv, char **env);
char			*get_path(char *cmd, char **env);

void			here_doc(char **argv);
void			here_doc_into_pipe(char **argv, int *fd);

int				ft_strlen(const char *s);
char			*ft_strjoin(char *s1, char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_error(char *s);

# define BUFFER_SIZE 42

char			*get_next_line(int fd);
char			*get_one_line(int fd, char *buf, char **backup);
char			*read_line(char *buf, char **backup);
char			*extract_line(char	*backup);
char			*meet_eof(char *buf, char **backup);

char			*ft_strdup(const char *s1);
char			*ft_strchr(const char *s, int c);
void			ft_free(char **p);

char			**ft_split_free(char **p);
unsigned int	word_count(char const *s, char c);
char			*word_alloc(char const *s, char c);
char			**ft_split(char const *s, char c);

#endif