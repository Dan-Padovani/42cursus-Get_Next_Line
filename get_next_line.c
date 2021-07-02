/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpadovan <dpadovan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 15:44:19 by dpadovan          #+#    #+#             */
/*   Updated: 2021/07/02 15:44:24 by dpadovan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int		ft_read_buffer(int fd, char **line);
static int		ft_split_line(int ret, char **save, char **line);
static void		ft_strfree(char **str);

int	get_next_line(int fd, char **line)
{
	if (fd < 0 || BUFFER_SIZE < 1)
		return (-1);
	return (ft_read_buffer(fd, line));
}

static int	ft_read_buffer(int fd, char **line)
{
	int			ret;
	char		*buffer;
	char		*tmp;
	static char	*save;

	buffer = (char *)malloc(BUFFER_SIZE + 1);
	ret = read(fd, buffer, BUFFER_SIZE);
	while (ret > 0)
	{
		buffer[ret] = '\0';
		if (!save)
			save = ft_strdup(buffer);
		else
		{
			tmp = ft_strjoin(save, buffer);
			free(save);
			save = tmp;
		}
		if (ft_strchr(save, '\n'))
			break ;
		ret = read(fd, buffer, BUFFER_SIZE);
	}
	free(buffer);
	return (ft_split_line(ret, &save, line));
}

static int	ft_split_line(int ret, char **save, char **line)
{
	int		i;
	char	*tmp;

	if (ret < 0)
		return (-1);
	else if (ret == 0 && *save == 0)
	{
		*line = ft_strdup("");
		ft_strfree(save);
		return (0);
	}
	i = 0;
	while ((*save)[i] != '\n' && (*save)[i])
		i++;
	*line = ft_substr(*save, 0, i);
	if (ft_strchr (*save, '\n'))
	{
		tmp = ft_strdup(*save + i + 1);
		free(*save);
		*save = tmp;
		return (1);
	}
	ft_strfree(save);
	return (0);
}

static void	ft_strfree(char **str)
{
	if (*str && str)
	{
		free(*str);
		*str = NULL;
	}
}
