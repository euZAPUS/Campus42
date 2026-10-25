/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsanch3 <alsanch3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/23 14:45:31 by alsanch3          #+#    #+#             */
/*   Updated: 2026/10/24 15:13:52 by alsanch3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_fill_stash(int fd, char *stash)
{
	char	*buf;
	ssize_t	n;

	buf = malloc(BUFFER_SIZE + 1);
	if (buf == NULL)
		return (ft_clean(NULL, stash));
	n = 1;
	while (n > 0 && ft_strchr(stash, '\n') == NULL)
	{
		n = read(fd, buf, BUFFER_SIZE);
		if (n < 0)
			return (ft_clean(buf, stash));
		buf[n] = '\0';
		stash = ft_append(stash, buf);
		if (stash == NULL)
			return (ft_clean(buf, NULL));
	}
	free(buf);
	return (stash);
}

static char	*ft_get_line(char *stash)
{
	int		i;
	int		j;
	char	*string;

	j = 0;
	i = 0;
	if (stash == NULL || stash[0] == '\0')
		return (NULL);
	while (stash[i] != '\n' && stash[i] != '\0')
	{
		i++;
	}
	if (stash[i] == '\n')
		i++;
	string = malloc(i + 1);
	if (string == NULL)
		return (NULL);
	while (j < i)
	{
		string[j] = stash[j];
		j++;
	}
	string[j] = '\0';
	return (string);
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
