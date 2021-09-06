/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorcill <amorcill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 20:27:36 by amorcill          #+#    #+#             */
/*   Updated: 2021/09/06 10:34:02 by amorcill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <stdio.h>

char	*ft_update_buff(char *buff)
{
	int		index;
	size_t	x;
	size_t	len;
	char	*line;

	len = ft_strlen(buff);
	index = ft_find_index(buff, '\n');
	line = ft_substr(buff, 0, index + 1);
	x = 0;
	while (x <= len)
	{
		buff[x] = buff[index + x + 1];
		x++;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*fd_buffs[FD_MAX_SIZE];
	char		*line;
	int			bytes_readed;
	char		buff[BUFFER_SIZE + 1];

	while (ft_find_index(fd_buffs[fd], '\n') == -1)
	{		
		bytes_readed = read(fd, buff, BUFFER_SIZE);
		if (bytes_readed <= 0)
		{
			if (fd_buffs[fd] != NULL && fd_buffs[fd][0] == '\0')
			{
				free(fd_buffs[fd]);
				return (NULL);
			}
			line = fd_buffs[fd];
			fd_buffs[fd] = NULL;
			return (line);
		}
		buff[bytes_readed] = '\0';
		fd_buffs[fd] = ft_strjoin(fd_buffs[fd], buff);
	}
	line = ft_update_buff(fd_buffs[fd]);
	return (line);
}
