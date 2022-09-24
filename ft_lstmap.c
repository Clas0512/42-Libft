/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anargul <anargul@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/08 00:04:58 by anargul           #+#    #+#             */
/*   Updated: 2022/07/08 04:16:34 by anargul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lst_map;
	t_list	*new;

	lst_map = NULL;
	while (lst)
	{
		new = ft_lstnew(f(lst->content));
		if (new)
			ft_lstadd_back(&lst_map, new);
		else
			ft_lstclear(&new, del);
		lst = lst->next;
	}
	return (lst_map);
}
