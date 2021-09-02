/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorcill <amorcill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 13:10:52 by x250              #+#    #+#             */
/*   Updated: 2021/09/02 20:16:03 by amorcill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
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
	static char	*fd_buff;
	char		*line;
	int			bytes_readed;
	char		buff[BUFFER_SIZE + 1];

	while (ft_find_index(fd_buff, '\n') == -1)
	{		
		bytes_readed = read(fd, buff, BUFFER_SIZE);
		if (bytes_readed <= 0)
		{
			if (fd_buff != NULL && fd_buff[0] == '\0')
			{
				free(fd_buff);
				return (NULL);
			}
			line = fd_buff;
			fd_buff = NULL;
			return (line);
		}
		buff[bytes_readed] = '\0';
		fd_buff = ft_strjoin(fd_buff, buff);
	}
	line = ft_update_buff(fd_buff);
	return (line);
}
