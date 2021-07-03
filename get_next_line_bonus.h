/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpadovan <dpadovan@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 16:06:01 by dpadovan          #+#    #+#             */
/*   Updated: 2021/07/02 22:59:04 by dpadovan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# define OPEN_MAX 256

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

size_t			ft_strlen(const char *s);
char			*ft_substr(const char *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strdup(const char *s);
char			*ft_strchr(const char *s, int c);
int				get_next_line(int fd, char **line);

#endif
