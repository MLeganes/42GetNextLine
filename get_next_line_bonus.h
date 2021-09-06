/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorcill <amorcill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/02 20:27:50 by amorcill          #+#    #+#             */
/*   Updated: 2021/09/06 10:31:29 by amorcill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

# ifndef FD_MAX_SIZE
#  define FD_MAX_SIZE 4024
# endif

char	*get_next_line(int fd);
char	*ft_update_buff(char *fdbuff);

/* get utils*/
int		ft_find_index(const char *buff, int c);
char	*ft_strdup(const char *s);
size_t	ft_strlen(const char *ch);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif
