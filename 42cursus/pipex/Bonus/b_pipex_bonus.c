/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_pipex_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerilee <yerilee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 19:10:13 by yerilee           #+#    #+#             */
/*   Updated: 2023/09/01 18:00:36 by yerilee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "b_pipex_bonus.h"

int	main(int argc, char **argv, char **env)
{
	int	i;
	int	infile;
	int	outfile;

	if (argc < 5)
		ft_error("Argc error");
	if (ft_strncmp(argv[1], "here_doc", 8) == 0 && ft_strlen(argv[1]) == 8)
	{
		i = 3;
		outfile = file_open(argv[argc - 1], 2);
		here_doc(argv);
	}
	else
	{
		i = 2;
		infile = file_open(argv[1], 0);
		outfile = file_open(argv[argc - 1], 1);
		dup2(infile, 0);
	}
	while (i < argc - 2)
		get_pipe_and_exec(argv[i++], env);
	dup2(outfile, 1);
	execute_cmd(argv[i], env);
	return (0);
}

int	file_open(char *file, int i)
{
	int	open_file;

	if (i == 0)
		open_file = open(file, O_RDONLY);
	if (i == 1)
		open_file = open(file, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (i == 2)
		open_file = open(file, O_WRONLY | O_CREAT | O_APPEND, 0644);
	if (open_file == -1)
		ft_error("Permission denied error");
	return (open_file);
}

void	get_pipe_and_exec(char *cmd, char **env)
{
	int	pid;
	int	fd[2];

	if (pipe(fd) == -1)
		ft_error("Pipe error");
	pid = fork();
	if (pid == -1)
		ft_error("Fork error");
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], 1);
		close(fd[1]);
		execute_cmd(cmd, env);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], 0);
		close(fd[0]);
	}
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
	else
	{
		path = get_path(cmd[0], env);
		if (path == NULL)
			ft_error("Path error");
		if (execve(path, cmd, env) == -1)
			ft_error("Command error");
	}
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
