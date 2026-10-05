/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsanch3 <alsanch3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/24 13:31:45 by alsanch3          #+#    #+#             */
/*   Updated: 2026/09/25 15:12:54 by alsanch3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	size_t	i;
	size_t	counter;

	i = 0;
	counter = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			counter++;
		i++;
	}
	return (counter);
}

char	**ft_split(char const *s, char c)
{
	char	**boxes;
	size_t	j;
	size_t	len;

	if (s == NULL)
		return (NULL);
	boxes = (char **) malloc((sizeof(char *) * (count_words(s, c) + 1)));
	if (!boxes)
		return (NULL);
	j = 0;
	while (*s != '\0')
	{
		if (*s != c)
		{
			len = 0;
			while (s[len] != '\0' && s[len] != c)
				len++;
			boxes[j++] = ft_substr(s, 0, len);
			s += len;
		}
		else
			s++;
	}
	boxes[j] = NULL;
	return (boxes);
}
