/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorcill <amorcill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 13:10:52 by x250              #+#    #+#             */
/*   Updated: 2021/09/01 19:51:02 by amorcill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
//#define BUFFER_SIZE 32

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*pointer;

	pointer = malloc((nmemb * size + 1));
	if (pointer == NULL)
	{
		free(pointer);
		return (NULL);
	}
	while (size > 0)
	{
		*(pointer + size) = '\0';
		size--;
	}
	return (pointer);
}

// char	*ft_get_line(t_gnl_buffer *buff)
// {
// 	char	*newline;
// 	char	*tofree;
// 	char	*eol;

// 	newline = NULL;
// 	if (buff->line == NULL)
// 		return NULL;
// 	if (buff->line == NULL)
// 		return (NULL);
// 	eol = ft_strchr(buff->line, '\n');
// 	if (eol)
// 	{
// 		tofree = buff->line;
// 		// New line to return.
// 		newline = ft_substr(buff->line, 0, (int)(eol - (char *)(buff->line)));
// 		// Keep the rest of the line.
// 		buff->line = ft_strdup(eol + 1);
// 		free(tofree);
// 	}	
// 	else if (buff->read_return == 0 && buff->line_len != 0 )
// 	{
// 		buff->line_len = 0;
// 		newline = ft_strdup(buff->line);
// 		free(buff->line);
// 		buff->line = NULL;
// 	}
// 	return (newline);
// }


/*
 * Function to read-file with buffer-size until the line \n is found.
 *
 *
 */
// void	ft_read_line(t_gnl_buffer *buff)
// {
// 	char	buffer[BUFFER_SIZE + 1];
// 	char	*tofree;
// 	char	*line_to_ret;
	
// 	line_to_ret = NULL;
// 	buff->read_return = read(buff->fd, buffer, BUFFER_SIZE);
// 	while (buff->read_return > 0)
// 	{
// 		buffer[buff->read_return] = '\0';
// 		if (buff->line == NULL)
// 			buff->line = ft_strdup(buffer);
// 		else
// 		{
// 			tofree = buff->line;
// 			buff->line = ft_strjoin(buff->line, buffer);
// 			buff->line_len = ft_strlen(buff->line);
// 			free(tofree);
// 		}
// 		if (ft_strchr(buff->line, '\n'))
// 		{
// 			line_to_ret = ft_get_line(buff);
// 			break ;
// 		}
// 		buff->read_return = read(buff->fd, buffer, BUFFER_SIZE);
// 	}
// 	// check if the buffer and read_return is 0, case eof
// 	if (buff->read_return == 0 && buff->line == NULL)
// 		buff->eof = 1;
// 	return (line_to_ret);	
// }



char	*ft_get_line(char *fdbuff)
{
	char	*line;
	int		i;
	
	i = 0;	
	if (fdbuff == NULL)
		return (NULL);
	while (fdbuff[i] && fdbuff[i] != '\n')
		i++;
	if (fdbuff[i] == '\n')
		i++;	// I want to copy \n too.
	line = malloc((i + 1) * sizeof(char)); //I know, char is 1, 1 * whatever = whatever.
	if (line == NULL)
		return (NULL);
	i = 0;
	while (fdbuff[i] && fdbuff[i] != '\n')
	{
		line[i] = fdbuff[i];
		i++;
	}
	if (fdbuff[i] == '\n')
		line[i] = fdbuff[i];
	return (line);
}

char	*ft_update_buff(char *fdbuff)
{
	char	*new_fdbuff;
	int i;
	int j;

	i = 0;
	while (fdbuff[i] && fdbuff[i] != '\n')
		i++;
	if ( fdbuff[i] == NULL || fdbuff[i + 1] == '\0')
	{
		free(fdbuff);
		return (NULL);
	}
	//new_fdbuff = malloc( ft_strlen(fdbuff) - i) * sizeof(char));
	new_fdbuff = calloc( ft_strlen(fdbuff) - i) * sizeof(char));
	if (new_fdbuff == NULL)
		return (NULL);
	i++;
	j = 0;
	while (fdbuff[i])
		new_fdbuff[j++] == fdbuff[i];
	new_fdbuff[j] = '\0';
	free(fdbuff);
	//??????????fdbuff = new_fdbuff;
	return (new_fdbuff);	
}


/*
 * char	*get_next_line(int fd)
 * 
 * return line found in the readed file.
 * fd file descriptor
 *
 */
char	*get_next_line(int fd)
{
	static char	fd_buffs[FILE_DESCRIPTOR_MAX];
	char		*line;
	int			bytes_readed;
	char		buff[BUFFER_SIZE + 1];

	bytes_readed = 1;
	while (bytes_readed > 0 && ft_strchr(fd_buffs[fd], '\n') == -1)
	{
		bytes_readed = read(fd, buff, BUFFER_SIZE);
		if (bytes_readed == -1 || bytes_readed == 0 && fd_buffs[fd])
			return (NULL);
		buff[bytes_readed] = '\0';
		fd_buffs[fd] = ft_strjoin(fd_buffs[fd], buff);
	}
	line = ft_get_line(fd_buffs[fd]);
	fd_buffs[fd] = ft_update_buff(fd_buffs[fd]);
	return (line);	

	// To Delete!!!!
	// static t_gnl_buffer buffs[FILE_DESCRIPTOR_MAX];	
	// if (fd < 0 || BUFFER_SIZE < 0)
	// 	return (NULL);	
	// buffs[fd].fd = fd;
	// ft_read_line(&buffs[fd]);
	// return (buffs[fd].line);		
}
