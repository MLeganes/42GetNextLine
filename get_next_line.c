/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorcill <amorcill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 13:10:52 by x250              #+#    #+#             */
/*   Updated: 2021/09/02 15:54:57 by amorcill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
//#define BUFFER_SIZE 32

// void	*ft_calloc(size_t nmemb, size_t size)
// {
// 	unsigned char	*pointer;

// 	pointer = malloc((nmemb * size + 1));
// 	if (pointer == NULL)
// 	{
// 		free(pointer);
// 		return (NULL);
// 	}
// 	while (size > 0)
// 	{
// 		*(pointer + size) = '\0';
// 		size--;
// 	}
// 	return (pointer);
// }


// char	*ft_get_line(char *fdbuff)
// {
// 	char	*line;
// 	int		i;
	
// 	i = 0;	
// 	if (fdbuff == NULL)
// 		return (NULL);
// 	while (fdbuff[i] && fdbuff[i] != '\n')
// 		i++;
// 	if (fdbuff[i] == '\n')
// 		i++;	// I want to copy \n too.
// 	line = malloc((i + 1) * sizeof(char)); //I know, char is 1, 1 * whatever = whatever.
// 	if (line == NULL)
// 		return (NULL);
// 	i = 0;
// 	while (fdbuff[i] && fdbuff[i] != '\n')
// 	{
// 		line[i] = fdbuff[i];
// 		i++;
// 	}
// 	if (fdbuff[i] == '\n')
// 		line[i] = fdbuff[i];
// 	return (line);
// }

// char	*ft_update_buff(char *fdbuff)
// {
// 	char	*new_fdbuff;
// 	int i;
// 	int j;

// 	i = 0;
// 	while (fdbuff[i] && fdbuff[i] != '\n')
// 		i++;
// 	//if ( fdbuff[i] == NULL || fdbuff[i + 1] == '\0')
// 	if ( fdbuff[i] == '\0' || fdbuff[i + 1] == '\0')
// 	{
// 		free(fdbuff);
// 		return (NULL);
// 	}
// 	//new_fdbuff = malloc( ft_strlen(fdbuff) - i) * sizeof(char));
// 	new_fdbuff = calloc( sizeof(char), ft_strlen(fdbuff) - i);
// 	if (new_fdbuff == NULL)
// 		return (NULL);
// 	i++; // I do not want to copy the \n, the frist one in the line.
// 	j = 0;
// 	while (fdbuff[i])
// 		new_fdbuff[j++] = fdbuff[i++];
// 	new_fdbuff[j] = '\0';
// 	free(fdbuff);
// 	//??????????fdbuff = new_fdbuff;
// 	return (new_fdbuff);	
// }



char	*ft_update_buff(char *buff)
{
	int	index;
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

/*
 * char	*get_next_line(int fd)
 * 
 * return line found in the readed file.
 * fd file descriptor
 *
 */
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
		else
		{
			buff[bytes_readed] = '\0';
			fd_buff = ft_strjoin(fd_buff, buff);
		}
	}
	// line = ft_get_line(fd_buff);
	line = ft_update_buff(fd_buff);
	return (line);
}
