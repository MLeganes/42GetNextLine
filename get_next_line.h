/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorcill <amorcill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/26 13:13:10 by x250              #+#    #+#             */
/*   Updated: 2021/09/01 19:38:18 by amorcill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# define FILE_DESCRIPTOR_MAX 2024

typedef struct s_gnl_buffer
{	
	int			read_return;
	char		*buf_rest;
	char		*line;			//
	int			line_len;
	int			fd;
	int			send_null_termination;
	int			eof;
}t_gnl_buffer;

char	*get_next_line(int fd);
char	*ft_get_line(char *fdbuff);
char	*ft_update_buff(char *fdbuff);
//void	ft_read_line(int fd, t_gnl_buffer *buff);
//char	*ft_get_line(t_gnl_buffer *buff);

/* get utils*/
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlen(const char *ch);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif
