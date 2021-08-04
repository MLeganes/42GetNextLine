/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorcill <amorcill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 13:10:52 by x250              #+#    #+#             */
/*   Updated: 2021/08/04 15:50:16 by amorcill         ###   ########.fr       */
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
	char	*eol;

	newline = NULL;
	if ( (eol = ft_strchr(*line, '\n')) )
	{
		*eol = '\0';
		tofree = *line;
		newline = ft_substr(*line, 0, (int)(eol - (char *)(*line)) );		
		*line = ft_strdup(eol + 1);
		free(tofree);
	}
	else if (*line)
	{
		/*
		 * Last pieze of the string without \n or only one read time.
		 */ 		
		newline = ft_strdup(*line);
		//&(*line) = '\0';		
		//free(*line);
		//*line = NULL;
	}	
 	return(newline);
}

char *get_next_line(int fd)
{
	ssize_t		len;
	char		buffer[BUFFER_SIZE + 1];
	char		*tofree;
	char		*ret;
	static char	*line;
	
	if (fd < 0 || BUFFER_SIZE < 0 )
		return (NULL);
	while ( (len = read(fd, buffer, BUFFER_SIZE)))
	{
		buffer[len] = '\0';
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
	}
	if ( len > 0 )
	{
		ret = ft_get_line(&line);
		return (ret);
	}
	//else if (ft_strlen(line) > 0 && line)
	else if (line)
	{
		ret = ft_get_line(&line);
		free(line);
		line = NULL;
		return (ret);
	}
	return (NULL);
}
