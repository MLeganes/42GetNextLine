/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorcill <amorcill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 11:24:19 by amorcill          #+#    #+#             */
/*   Updated: 2021/09/06 14:29:55 by amorcill         ###   ########.fr       */
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
	char	*line;
	int		index;
		
	fd = open("files/dracula.txt", O_RDONLY, 0);
	line = get_next_line(fd);
	index = 0;
	while (line)
	{
		printf("%d %s", index++, line);
		free(line);
 		line = get_next_line(fd);		
	}
	close(fd);
	/*
	*  Check memory
	*/
	//system ("leaks a.out");
	return (0);
}
