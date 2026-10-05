/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsanch3 <alsanch3@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/25 14:43:52 by alsanch3          #+#    #+#             */
/*   Updated: 2026/09/25 15:14:14 by alsanch3         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temporal;

	if (!lst || !del)
		return ;
	while (*lst != NULL)
	{
		temporal = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = temporal;
	}
}
