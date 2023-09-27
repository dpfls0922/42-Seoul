/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_here_doc_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerilee <yerilee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 15:28:58 by yerilee           #+#    #+#             */
/*   Updated: 2023/08/25 15:18:14 by yerilee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "b_pipex_bonus.h"

void	here_doc(char **argv)
{
	int	pid;
	int	fd[2];

	if (pipe(fd) == -1)
		ft_error("Pipe error");
	pid = fork();
	if (pid == -1)
		ft_error("Fork error");
	if (pid == 0)
		here_doc_into_pipe(argv, fd);
	else
	{
		close(fd[1]);
		dup2(fd[0], 0);
		close(fd[0]);
	}
}

void	here_doc_into_pipe(char **argv, int *fd)
{
	char	*line;

	close(fd[0]);
	while (1)
	{
		write(1, "heredoc> ", 9);
		line = get_next_line(0);
		if (!line)
			ft_error("Line malloc error");
		if (ft_strncmp(line, argv[2], ft_strlen(argv[2])) == 0
			&& ft_strlen(argv[2]) == ft_strlen(line) - 1)
		{
			free(line);
			exit(0);
		}
		write(fd[1], line, ft_strlen(line));
		free(line);
	}
	free(line);
}
