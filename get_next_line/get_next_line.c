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

static char	*ft_fill_stash(int fd, char *stash)
{
	char		*buf;
	char		*temp;
	ssize_t		n;

	buf = malloc(BUFFER_SIZE + 1);
	if (buf == NULL)
	{
		free(stash);
		return (NULL);
	}
	n = read(fd, buf, BUFFER_SIZE);
	if (n < 0)
	{
		free(buf);
		free(stash);
		return (NULL);
	}
	buf[n] = '\0';
	temp = stash;
	stash = ft_strjoin(temp, buf);
	free(temp);
	free(buf);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash = ft_fill_stash(fd, stash);
	if (stash == NULL)
		return (NULL);
	line = NULL;
	return (line);
}
