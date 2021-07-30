/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorcill <amorcill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 11:24:19 by amorcill          #+#    #+#             */
/*   Updated: 2021/07/30 12:01:05 by amorcill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
* Lib fcntl.h (sys/fcntl.h) is for open(2) files with file status flag
* O_RDONLY	0x0000	open-for-reading-only
*/
#include <fcntl.h> 

#include "get_next_line.h"
// needed?
#include <stdlib.h>
#include <stdio.h>

/*
* The main function is for testing porpouse. It is not a part of the proyect.
* 
*/
int	main(void)
{
	int		fd;
	int		len;
	char	*line;

	line = NULL;
	fd = open("texts/gnl_text1.txt", O_RDONLY, 0);
	if (fd < 0)
	{
		write(1, "Error occurred when try to open fd", 33);
		return (-1);
	}	
	len = 1;
	line = get_next_line(fd);
	while (!line)
	{
		printf("%s", line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}
