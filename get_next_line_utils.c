/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amorcill <amorcill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/29 14:53:36 by amorcill          #+#    #+#             */
/*   Updated: 2021/09/02 20:16:42 by amorcill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_find_index(const char *s, int c)
{
	int	index;

	index = 0;
	if (s != NULL)
	{
		while (s[index] != '\0')
		{
			if (s[index] == (char)c)
				return (index);
			index++;
		}
		if (s[index] == (char)c)
			return (index);
	}
	return (-1);
}

char	*ft_strdup(const char *s)
{
	int		len;
	int		count;
	char	*ret;

	count = 0;
	len = ft_strlen(s);
	ret = (char *)malloc(len + 1);
	if (ret)
	{
		while (count < len)
		{
			ret[count] = s[count];
			count++;
		}
		ret[count] = '\0';
	}
	return (ret);
}

size_t	ft_strlen(const char *ch)
{
	int	count;

	if (ch == NULL)
		return (0);
	count = 0;
	while (*(ch + count))
	{
		count++;
	}
	return (count);
}

char	*ft_strjoin(char *s1, char *s2)
{	
	size_t	index;
	size_t	i;
	char	*strjoin;

	strjoin = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!strjoin)
		return (0);
	index = 0;
	if (s1 != NULL)
	{
		while (s1[index] != '\0')
		{
			strjoin[index] = s1[index];
			index++;
		}
		free(s1);
	}
	i = 0;
	while (s2[i] != '\0')
		strjoin[index++] = s2[i++];
	strjoin[index] = '\0';
	return (strjoin);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char			*substr;
	unsigned int	counter;

	counter = 0;
	substr = NULL;
	if (s == NULL)
		return (NULL);
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (s != NULL)
	{
		substr = malloc(sizeof(char) * len + 1);
		if (substr == 0)
			return (NULL);
		while (counter < len && s[start + counter] != '\0')
		{
			substr[counter] = s[start + counter];
			counter++;
		}
		substr[counter] = '\0';
	}
	return (substr);
}
