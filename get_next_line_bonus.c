/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpadovan <dpadovan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 16:04:54 by dpadovan          #+#    #+#             */
/*   Updated: 2021/07/02 22:52:41 by dpadovan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static int		ft_split_line(int ret, char **save, char **line);
static void		ft_strfree(char **str);

int	get_next_line(int fd, char **line)
{
	static char	*save[OPEN_MAX];
	char		*buffer;
	char		*tmp;
	int			ret;

	buffer = (char *)malloc(BUFFER_SIZE + 1);
	ret = read(fd, buffer, BUFFER_SIZE);
	while (ret > 0)
	{
		buffer[ret] = '\0';
		if (!save[fd])
			save[fd] = ft_strdup(buffer);
		else
		{
			tmp = ft_strjoin(save[fd], buffer);
			free(save[fd]);
			save[fd] = tmp;
		}
		if (ft_strchr(save[fd], '\n'))
			break ;
		ret = read(fd, buffer, BUFFER_SIZE);
	}
	free(buffer);
	return (ft_split_line(ret, &save[fd], line));
}

static int	ft_split_line(int ret, char **save, char **line)
{
	char	*tmp;
	int		i;

	if (ret < 0 || BUFFER_SIZE < 1)
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
