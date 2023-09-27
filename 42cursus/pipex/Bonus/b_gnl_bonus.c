/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_gnl_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerilee <yerilee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/23 15:22:04 by yerilee           #+#    #+#             */
/*   Updated: 2023/08/24 15:42:46 by yerilee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include "b_pipex_bonus.h"

char	*get_next_line(int fd)
{
	char		*buf;
	static char	*backup;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
	{
		ft_free(&backup);
		return (0);
	}
	return (get_one_line(fd, buf, &backup));
}

char	*get_one_line(int fd, char *buf, char **backup)
{
	int	read_size;

	while (!ft_strchr(*backup, '\n'))
	{
		read_size = read(fd, buf, BUFFER_SIZE);
		if (read_size == -1)
		{
			ft_free(&buf);
			ft_free(backup);
			return (0);
		}
		buf[read_size] = '\0';
		*backup = ft_strjoin(*backup, buf);
		if (!*backup)
		{
			ft_free(&buf);
			return (0);
		}
		if (read_size == 0)
			return (meet_eof(buf, backup));
	}
	return (read_line(buf, backup));
}

char	*read_line(char *buf, char **backup)
{
	char	*tmp;
	char	*line;

	tmp = (*backup);
	line = extract_line(*backup);
	if (!line)
	{
		tmp = 0;
		ft_free(backup);
		ft_free(&buf);
		return (0);
	}
	*backup = ft_strdup(ft_strchr(tmp, '\n') + 1);
	if (!*backup)
	{
		ft_free(&line);
		ft_free(&tmp);
		ft_free(backup);
		ft_free(&buf);
		return (0);
	}
	ft_free(&tmp);
	ft_free(&buf);
	return (line);
}

char	*extract_line(char	*backup)
{
	int		i;
	int		len;
	char	*str;

	i = 0;
	while (backup[i] != '\n')
		i++;
	len = i + 1;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	i = 0;
	while (i < len)
	{
		str[i] = backup[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*meet_eof(char *buf, char **backup)
{
	char	*line;

	ft_free(&buf);
	if (ft_strlen(*backup) == 0)
	{
		ft_free(backup);
		return (0);
	}
	else
	{
		line = *backup;
		*backup = 0;
		return (line);
	}
}
