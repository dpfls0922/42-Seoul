/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   m_pipex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerilee <yerilee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 17:59:17 by yerilee           #+#    #+#             */
/*   Updated: 2023/09/01 17:57:30 by yerilee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "m_pipex.h"

int	main(int argc, char **argv, char **env)
{
	int	pid;
	int	fd[2];

	if (argc == 5)
	{
		if (pipe(fd) == -1)
			ft_error("Pipe error");
		pid = fork();
		if (pid == -1)
			ft_error("Fork error");
		if (pid == 0)
			child_process(argv, env, fd);
		else
			parent_process(argv, env, fd);
		close(fd[0]);
		close(fd[1]);
	}
	else
		ft_error("Argc error");
	return (0);
}

void	child_process(char **argv, char **env, int *fd)
{
	int	infile;

	infile = open(argv[1], O_RDONLY);
	if (infile == -1)
		ft_error("Permission denied error");
	close(fd[0]);
	dup2(infile, 0);
	dup2(fd[1], 1);
	execute_cmd(argv[2], env);
}

void	parent_process(char **argv, char **env, int *fd)
{
	int	outfile;

	outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfile == -1)
		ft_error("Permission denied error");
	close(fd[1]);
	dup2(fd[0], 0);
	dup2(outfile, 1);
	execute_cmd(argv[3], env);
}

void	execute_cmd(char *argv, char **env)
{
	char	**cmd;
	char	**backup_cmd;
	char	*path;
	int		i;

	i = 0;
	cmd = ft_split(argv, ' ');
	if (access(cmd[0], X_OK) == 0)
	{
		backup_cmd = ft_split(argv, ' ');
		cmd = ft_split(argv, '/');
		while (cmd[i])
			i++;
		cmd = ft_split(cmd[i - 1], ' ');
		execve(backup_cmd[0], cmd, env);
	}
	path = get_path(cmd[0], env);
	if (path == NULL)
		ft_error("Path error");
	if (execve(path, cmd, env) == -1)
		ft_error("Command error");
}

char	*get_path(char *cmd, char **env)
{
	int		i;
	char	**paths;
	char	*path;
	char	*res;

	i = 0;
	if (env == NULL)
		exit (1);
	while (env[i] && ft_strncmp(env[i], "PATH=", 5) != 0)
		i++;
	if (env[i] == NULL)
		return (0);
	paths = ft_split(env[i] + 5, ':');
	i = -1;
	while (paths[++i])
	{
		path = ft_strjoin(paths[i], "/");
		res = ft_strjoin(path, cmd);
		if (access(res, F_OK) == 0)
			return (res);
		else
			free(res);
	}
	return (0);
}
