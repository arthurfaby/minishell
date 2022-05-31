/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaud <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 15:30:09 by vnaud             #+#    #+#             */
/*   Updated: 2022/05/03 18:03:20 by vnaud            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_gnl.h"

char	*read_fd(int fd, char *buffer)
{
	char	*read_buffer;
	int		ret;

	read_buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!read_buffer)
		return (read_buffer);
	ret = 1;
	*read_buffer = '\0';
	while (ret != 0 && !ft_strchr(read_buffer, '\n'))
	{
		ret = read(fd, read_buffer, BUFFER_SIZE);
		if (ret < 0)
		{
			free(read_buffer);
			read_buffer = NULL;
			return (NULL);
		}
		read_buffer[ret] = '\0';
		buffer = ft_strjoins(buffer, read_buffer);
	}
	free(read_buffer);
	read_buffer = NULL;
	return (buffer);
}

char	*get_line(char *buffer)
{
	int		index;
	char	*line;

	index = 0;
	if (!buffer[index])
		return (NULL);
	while (buffer[index] && buffer[index] != '\n')
		index++;
	if (buffer[index] == '\n')
		index++;
	line = malloc(sizeof(char) * (index + 1));
	if (!line)
		return (NULL);
	index = 0;
	while (buffer[index] && buffer[index] != '\n')
	{
		line[index] = buffer[index];
		index++;
	}
	if (buffer[index] == '\n')
		line[index++] = '\n';
	line[index] = '\0';
	return (line);
}

char	*clear_buffer(char *buffer)
{
	size_t	index;
	size_t	index_new;
	char	*new_buff;

	index = 0;
	while (buffer[index] && buffer[index] != '\n')
		index++;
	if (!buffer[index]
		|| (buffer[index] == '\n' && index == ft_strlen(buffer) - 1))
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	new_buff = malloc(sizeof(char) * (ft_strlen(buffer) - index + 1));
	if (!new_buff)
		return (new_buff);
	index_new = 0;
	index++;
	while (buffer[index])
		new_buff[index_new++] = buffer[index++];
	new_buff[index_new] = '\0';
	free(buffer);
	buffer = NULL;
	return (new_buff);
}

char	*get_next_line(int fd)
{
	static char	*buffer[1025];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 1024)
		return (NULL);
	buffer[fd] = read_fd(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	line = get_line(buffer[fd]);
	buffer[fd] = clear_buffer(buffer[fd]);
	return (line);
}
