/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykifadji <ykifadji@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 11:10:16 by ykifadji          #+#    #+#             */
/*   Updated: 2022/11/27 13:11:49 by ykifadji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*liste;
	t_list	*next;

	if (lst && del)
	{
		liste = *lst;
		while (liste)
		{
			next = liste->next;
			ft_lstdelone(liste, del);
			liste = next;
		}
		*lst = NULL;
	}
}
