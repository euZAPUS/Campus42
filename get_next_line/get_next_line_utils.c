/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsanch3 <alsanch3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/24 13:16:24 by alsanch3          #+#    #+#             */
/*   Updated: 2026/10/24 13:50:36 by alsanch3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	cc;

	if (s == NULL)
		return (NULL);
	cc = (unsigned char) c;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == cc)
			return ((char *)(&s[i]));
		i++;
	}
	if (s[i] == cc)
		return ((char *)(&s[i]));
	return (0);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (s == NULL)
		return (0);
	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*l;
	int		i;
	int		j;

	l = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (l == NULL)
		return (NULL);
	j = 0;
	i = 0;
	while (s1 != NULL && s1[i] != '\0')
	{
		l[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		l[i] = s2[j];
		i++;
		j++;
	}
	l[i] = '\0';
	return (l);
}
