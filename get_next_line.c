/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyani <asyani@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 15:57:07 by asyani            #+#    #+#             */
/*   Updated: 2024/11/23 16:36:03 by asyani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#define BUFFER 10

char	*get_next_line(int fd)
{
	ssize_t	read_bytes;
	t_list	*head =NULL;
	t_list	*line_node;
	char	buffer[BUFFER];
	ssize_t	i;

	while ((read_bytes = read(fd, buffer, BUFFER)) > 0)
	{
		i = 0;
		while (buffer[i] != '\n')
			i++;
		line_node = malloc(sizeof(t_list));
		if (!line_node)
			return (NULL);
		line_node->data = malloc(i + 1);
		if (!line_node->data)
		{
			free(line_node);
			return (NULL);
		}
		memcpy(line_node->data, buffer, i);
		line_node->data[i] = '\0';
		add_back(&head, line_node);
		//printf("this is a head: %s\n", head->data);
		if (buffer[i] == '\n')
			break;
	}
	if (read_bytes <= 0)
		return (NULL);
	return (head->data);
}
