/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsanch3 <alsanch3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 14:45:31 by alsanch3          #+#    #+#             */
/*   Updated: 2026/10/24 14:06:17 by alsanch3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;
	char		*buf;
	char		*temp;
	ssize_t		n;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = malloc(BUFFER_SIZE + 1);
	if (buf == NULL)
		return (NULL);
	n = read(fd, buf, BUFFER_SIZE);
	if (n < 0)
	{
		free(buf);
		return (NULL);
	}
	else
		buf[n] = '\0';
	temp = stash;
	stash = ft_strjoin(temp, buf);
	free(temp);
	if (stash == NULL)
	{
		free(buf);
		return (NULL);
	}
	line = NULL;
	free(buf);
	return (line);
}
