/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyani <asyani@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 15:13:45 by asyani            #+#    #+#             */
/*   Updated: 2024/12/02 15:19:10 by asyani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	concat = malloc(sizeof(char) * (s1_size + s2_size + 1));
	if (!concat)
		return (NULL);
	ft_strcat(concat, s1, s2);
	free(s1);
	return (concat);
}

/**
 * extract_line - the function to extract line before new line
 * @static_str: the static variable to remember where we are in the line
 *
 * return: the extract line
 */

char	*extract_line(char **static_str)
{
	char	*newline_pos;
	char	*line;
	char	*temp;

	line = NULL;
	temp = NULL;
	if (*static_str && **static_str)
	{
		newline_pos = ft_strchr(*static_str, '\n');
		if (!newline_pos)
			newline_pos = ft_strchr(*static_str, '\0');
		line = malloc(((newline_pos - *static_str) + 1) * sizeof(char));
		ft_strncpy(line, *static_str, (newline_pos - *static_str));
		temp = ft_strdup(newline_pos);
	}
	free(*static_str);
	*static_str = temp;
	return (line);
}

/**
 * get_next_line - the function to get next line from a file
 * @fd: the file that we want to extract
 *
 * return: on success- the line - on failure NULL
 */

char	*get_next_line(int fd)
{
	static char	*static_str[1024];
	char		*buffer;
	ssize_t		bytes_read;
	char		*line;

	if (fd < 0 || fd > 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(sizeof(char) * ((size_t)BUFFER_SIZE + 1));
	while (buffer && !ft_strchr(static_str[fd], '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			return (free(static_str[fd]), static_str[fd] = NULL,
				free(buffer), NULL);
		buffer[bytes_read] = '\0';
		if (bytes_read == 0 && !buffer[bytes_read])
			break ;
		static_str[fd] = ft_strjoin(static_str[fd], buffer);
		if (!static_str[fd])
			break ;
	}
	line = extract_line(&static_str[fd]);
	return (free(buffer), line);
}
