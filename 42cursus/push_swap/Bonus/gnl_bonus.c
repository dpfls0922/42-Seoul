/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerilee <yerilee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/27 21:16:11 by yerilee           #+#    #+#             */
/*   Updated: 2023/09/28 16:00:04 by yerilee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

char	*get_next_line(int fd)
{
	char		*buf;
	static char	*backup;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
	{
		ft_gnl_free(&backup);
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
			ft_gnl_free(&buf);
			ft_gnl_free(backup);
			return (0);
		}
		buf[read_size] = '\0';
		*backup = ft_strjoin(*backup, buf, ft_strlen(*backup), ft_strlen(buf));
		if (!*backup)
		{
			ft_gnl_free(&buf);
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
		ft_gnl_free(backup);
		ft_gnl_free(&buf);
		return (0);
	}
	*backup = ft_strdup(ft_strchr(tmp, '\n') + 1);
	if (!*backup)
	{
		ft_gnl_free(&line);
		ft_gnl_free(&tmp);
		ft_gnl_free(backup);
		ft_gnl_free(&buf);
		return (0);
	}
	ft_gnl_free(&tmp);
	ft_gnl_free(&buf);
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

	ft_gnl_free(&buf);
	if (ft_strlen(*backup) == 0)
	{
		ft_gnl_free(backup);
		return (0);
	}
	else
	{
		line = *backup;
		*backup = 0;
		return (line);
	}
}
