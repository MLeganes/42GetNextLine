/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorcill <amorcill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 13:10:52 by x250              #+#    #+#             */
/*   Updated: 2021/07/27 19:44:38 by amorcill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char *get_next_line(int fd)
{
	ssize_t		len;
	char		*buffer;

	buffer = calloc(BUFFER_SIZE + 1, (size_t)sizeof(void *));
	if (!buffer)
		return (NULL);
		
	len = read(fd, buffer, BUFFER_SIZE);
	
	printf("\nResult: %s", buffer);
	//write(fd, buffer, len);

	return (buffer);
}


int main()
{
	get_next_line(0);
	while(true)
	return 0;
}