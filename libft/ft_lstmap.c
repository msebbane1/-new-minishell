/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbally <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 12:32:00 by lbally            #+#    #+#             */
/*   Updated: 2022/07/22 12:32:01 by lbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*new_elem;

	new_elem = NULL;
	new_lst = new_elem;
	if (!lst || !f)
		return (NULL);
	while (lst)
	{
		if (!(new_elem = ft_lstnew(f(lst->content), lst->key)))
		{
			ft_lstclear(&lst, del);
		}
		lst = lst->next;
		ft_lstadd_back(&new_lst, new_elem);
	}
	return (new_lst);
}
