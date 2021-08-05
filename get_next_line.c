/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorcill <amorcill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 13:10:52 by x250              #+#    #+#             */
/*   Updated: 2021/08/05 20:39:17 by amorcill         ###   ########.fr       */
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

char	*ft_get_line(char **line, t_gnl_buffer *buff)
{
	char	*newline;
	char	*tofree;
	char	*eol;

	newline = NULL;
	if (buff->line == NULL)
		return NULL;
	if (*line == NULL)
		return (NULL);
	eol = ft_strchr(buff->line, '\n');
	if (eol)
	{
		//*eol = '\0';
		tofree = buff->line;
		newline = ft_substr(buff->line, 0, (int)(eol - (char *)(buff->line)));
		buff->line = ft_strdup(eol + 1);
		free(tofree);
	}
	//else if (*line != NULL && ft_strchr(*line, '\0'))
	else if (buff->read_rest == 0 && buff->line_len > 0)
	{
		buff->line_len = 0;
		newline = ft_strdup(buff->line);
		free(buff->line);
		buff->line = NULL;
		buff->send_null_termination = 1;
	}
	else if (buff->line_len == 0 && buff->send_null_termination == 1)
	{	
		newline = NULL;
	}
	return (newline);
}

char	*ft_read(int fd, char **line, t_gnl_buffer *buff)
{
	char	buffer[BUFFER_SIZE + 1];
	char	*tofree;
	//int		len;

	
	if ( line == NULL)
		return (NULL);
	//len = read(fd, buffer, BUFFER_SIZE);
	buff->read_rest = read(fd, buffer, BUFFER_SIZE);
	//while (len > 0)
	while (buff->read_rest > 0)
	{
		buffer[buff->read_rest] = '\0';
		if (buff->line == NULL)
			buff->line = ft_strdup(buffer);
		// if (*line == NULL && len > 0)
		// 	*line = ft_strdup(buffer);
		else
		{
			tofree = buff->line;
			buff->line = ft_strjoin(buff->line, buffer);
			buff->line_len = ft_strlen(buff->line);			
			free(tofree);
		}
		// else
		// {
		// 	tofree = *line;
		// 	*line = ft_strjoin(*line, buffer);
		// 	free(tofree);
		// }
		if (ft_strchr(buff->line, '\n'))
			break ;
		buff->read_rest = read(buff->fd, buffer, BUFFER_SIZE);
	}
	return (buff->line);
}

char	*get_next_line(int fd)
{
	char				*ret;
	static char			*line;
	static t_gnl_buffer buffs[FILE_DESCRIPTOR_MAX];
	// void 	*add_amper;
	// int 	add_ast;
	
	line = NULL;
	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	buffs[fd].fd = fd;
	
	//add_amper = &line;
	//printf(" this is ast:%p", *line);
	
	line = ft_read(fd, &line, &buffs[fd]);
	ret = ft_get_line(&line, &buffs[fd]);
	return (ret);
}
