/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorcill <amorcill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 13:10:52 by x250              #+#    #+#             */
/*   Updated: 2021/07/30 19:50:09 by amorcill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*ft_get_line(const char *line)
{	
	char	*ret_line;
	int		ret_line_len;
	char	*update_line;
	char	*eol;

	// 1. get subline
	eol = ft_strchr(line, '\n');

	ret_line = ft_substr(line, 0, (int)(eol - (char *)line) );
	ret_line_len = ft_strlen(ret_line);
	// 2. update line with the rest-line if exist.
	
	//1 const char * -- string ok
	//2 unsigned int -- star point => No pointer, strlen 
	//3 size_t 		 -- len

	update_line = ft_substr(line, ret_line_len, ft_strlen(line) - ret_line_len);
	//free((char *)line);
	line = update_line;
	return(ret_line);	
}

char *get_next_line(int fd)
{
	ssize_t		len;
	char		buffer[BUFFER_SIZE + 1];
	char		*buffer_aux;
	static char	*line;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	//buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));


	len = read(fd, buffer, BUFFER_SIZE);	
	while (len > 0)
	{
		if (line == NULL)
			line = ft_strdup(buffer);
		else
		{
			buffer_aux = ft_strjoin(line, buffer);
			free(line);
			line = buffer_aux;
			//free(buffer_aux);
		}
		if (ft_strchr(line, '\n'))
			break ;
		len = read(fd, buffer, BUFFER_SIZE);			
	}
	return (ft_get_line((const char *)line));
}
