/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: x250 <x250@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 13:13:10 by x250              #+#    #+#             */
/*   Updated: 2021/08/05 21:59:47 by x250             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# define FILE_DESCRIPTOR_MAX 2024

typedef struct s_gnl_buffer
{
	char		*buffer;
	int			buf_rest;
	int			read_return;
	char		*line;
	int			line_len;
	int			fd;
	int			send_null_termination;
}t_gnl_buffer;



char	*get_next_line(int fd);

/* get utils*/
char	*ft_strchr(const char *s, int c);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_get_line(char **line, t_gnl_buffer *buff);
char	*ft_read(int fd, char **line, t_gnl_buffer *buff);

char	*ft_strdup(const char *s);
size_t	ft_strlen(const char *ch);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif
