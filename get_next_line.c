/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorcill <amorcill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 13:10:52 by x250              #+#    #+#             */
/*   Updated: 2021/08/03 20:53:21 by amorcill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*pointer;

	pointer = malloc((nmemb * size));
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

static char	*ft_get_line(char **line)
{	
	char	*newline;
	char	*tofree;
	//int		newline_len;
	//char	*update_line;
	char	*eol;

	eol = ft_strchr(*line, '\n');
	*eol = '\0';

	tofree = *line;
	newline = ft_substr(*line, 0, (int)(eol - (char *)(*line)) );
	
	*line = ft_strdup(eol + 1);
	free(tofree);
	
	return(newline);	
}

char *get_next_line(int fd)
{
	ssize_t		len;
	char		buffer[BUFFER_SIZE];
	//char		*buffer;
	char		*tofree;
	static char	*line;
	char		*ret;
	
	//buffer = (char *)calloc(1, BUFFER_SIZE + 1);

	if (fd < 0 || BUFFER_SIZE < 0 )
		return (NULL);
	
	len = read(fd, buffer, BUFFER_SIZE);	
	while (len > 0)
	{
		if (line == NULL)
			line = ft_strdup(buffer);
		else
		{
			tofree = line;  
			line = ft_strjoin(line, buffer);
			free(tofree);
		}
		if (ft_strchr(line, '\n'))
			break ;
		len = read(fd, buffer, BUFFER_SIZE);			
	}
	//free(buffer);
	if ( len > 0)
		ret = ft_get_line(&line);
	else
		ret = NULL;	
	return (ret);
}
