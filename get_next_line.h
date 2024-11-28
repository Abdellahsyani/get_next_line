/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asyani <asyani@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 17:34:24 by asyani            #+#    #+#             */
/*   Updated: 2024/11/23 17:36:57 by asyani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <stddef.h>

char	*ft_get_next_line(int fd);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_extract_line(char **static_str);
size_t	ft_strlen(char *str);
char	*ft_strcat(char *dest, const char *src);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(char *s);
char	*ft_strncpy(char *dest, const char *src, size_t n);

#endif
