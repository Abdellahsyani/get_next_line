/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyani <asyani@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 10:42:11 by asyani            #+#    #+#             */
/*   Updated: 2024/11/26 17:03:38 by asyani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#define BUFFER_SIZE 10

/**
 * ft_strjoin - helper function to join two strings
 * @s1: the string that will has joined
 * @s2: the string that will join to s1
 *
 * return: the joined strings
 */
char	*ft_strjoin(char *s1, char *s2)
{
	char	*concat;
	int		s1_size;
	int		s2_size;

	if (s1 == NULL && s2 == NULL)
		return (NULL);
	if (s1 == NULL)
		return (ft_strdup(s2));
	if (s2 == NULL)
		return (ft_strdup(s1));
	s1_size = ft_strlen(s1);
	s2_size = ft_strlen(s2);
	concat = malloc(sizeof(char) * (s1_size + s2_size) + 1);
	if (!concat)
		return (NULL);
	concat = strcat(s1, s2);
	return (concat);
}

/**
 * extract_line - the function to extract line before new line
 * @static_str: the static variable to remember where we are in the line
 *
 * return: the extract line
 */

char	*ft_extract_line(char **static_str)
{
	char	*newline_pos;
	char	*line;
	char	*temp;
	size_t	line_len;

	newline_pos = ft_strchr(*static_str, '\n');
	if (newline_pos)
	{
		line_len = newline_pos - *static_str + 1;
		line = malloc(line_len + 1);
		if (!line)
			return (NULL);
		ft_strncpy(line, *static_str, line_len);
		line[line_len] = '\0';
		temp = ft_strdup(newline_pos + 1);
		if (!temp)
		{
			free(line);
			return (NULL);
		}
		free(*static_str);
		*static_str = temp;
	}
	else
	{
		line = ft_strdup(*static_str);
		if (!line)
			return (NULL);
		free(*static_str);
		*static_str = NULL;
	}
	return (line);
}
/**
 * get_next_line - the function to get next line from a file
 * @fd: the file that we want to extract
 *
 * return: on success- the line - on failure NULL
 */

char	*ft_get_next_line(int fd)
{
	static char	*static_str;
	char		buffer[BUFFER_SIZE];
	ssize_t		bytes_read;

	while (!static_str || !ft_strchr(static_str, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(static_str);
			return (NULL);
		}
		if (bytes_read == 0)
			break ;
		buffer[bytes_read] = '\0';
		static_str = ft_strjoin(static_str, buffer);
		if (!static_str)
			return (NULL);
	}
	if (static_str && *static_str)
		return (ft_extract_line(&static_str));
	free(static_str);
	static_str = NULL;
	return (NULL);
}
