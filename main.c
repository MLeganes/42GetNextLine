/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorcill <amorcill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/30 11:24:19 by amorcill          #+#    #+#             */
/*   Updated: 2021/08/05 16:40:16 by amorcill         ###   ########.fr       */
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

	line = NULL;
	//fd = open("files/gnl_text1.txt", O_RDONLY, 0);
	//fd = open("gnlTester/files/41_no_nl", O_RDONLY, 0);
	//fd = open("gnlTester/files/41_with_nl", O_RDONLY, 0);
	// fd = open("gnlTester/files/42_no_nl", O_RDONLY, 0);
	// fd = open("gnlTester/files/42_with_nl", O_RDONLY, 0);
	//fd = open("gnlTester/files/alternate_line_nl_no_nl", O_RDONLY, 0);
	//fd = open("gnlTester/files/multiple_line_no_nl", O_RDONLY, 0);
	fd = open("gnlTester/files/multiple_line_with_nl", O_RDONLY, 0);
	if (fd < 0)
	{
		write(1, "\nerror: occurred when try to open fd\n", 37);
		return (-1);
	}	
	line = get_next_line(fd);
	while (line)
	{
		printf("\n%s", line);
 		line = get_next_line(fd);
	}
	close(fd);

	/*
	*  Check memory
	*/
	system ("leaks a.out");
	return (0);
}
