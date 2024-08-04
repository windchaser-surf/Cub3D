/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwechsle <fwechsle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 13:58:59 by felix             #+#    #+#             */
/*   Updated: 2024/02/26 18:25:04 by fwechsle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

char	*return_line(int index, char **safe_line)
{
	char	*result;
	size_t	len;

	if (!*safe_line)
		return (NULL);
	if (index <= 0)
	{
		if (**safe_line == 0 || index < 0)
		{
			free(*safe_line);
			*safe_line = NULL;
			return (NULL);
		}
		result = *safe_line;
		*safe_line = NULL;
		return (result);
	}
	len = ft_strlen(*safe_line) - index;
	result = *safe_line;
	*safe_line = ft_substr(*safe_line, index, len);
	if (*safe_line == NULL)
		return (free(result), NULL);
	result[index] = 0;
	return (result);
}

char	*get_current_line(char **safe_line, char *buffer, int fd)
{
	ssize_t	bytes_read;
	char	*next_line;
	char	*result;
	char	*new_safe_line;

	next_line = ft_strchr(*safe_line, '\n');
	while (next_line == NULL)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read <= 0)
			return (return_line(bytes_read, safe_line));
		buffer[bytes_read] = '\0';
		new_safe_line = ft_strjoin(*safe_line, buffer);
		if (!*safe_line)
			return (free(*safe_line), NULL);
		free(*safe_line);
		*safe_line = new_safe_line;
		next_line = ft_strchr(*safe_line, '\n');
	}
	result = return_line(next_line - *safe_line + 1, safe_line);
	return (result);
}

char	*get_next_line(int fd)
{
	static char	*safe_line;
	char		*buffer;
	char		*result;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!safe_line)
		safe_line = ft_strdup("");
	if (!safe_line)
		return (NULL);
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(buffer));
	if (!buffer)
		return (free(safe_line), NULL);
	result = get_current_line(&safe_line, buffer, fd);
	free(buffer);
	return (result);
}
