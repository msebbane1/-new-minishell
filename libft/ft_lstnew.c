/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbally <lbally@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 12:32:13 by lbally            #+#    #+#             */
/*   Updated: 2022/08/12 15:34:27 by lbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content, char *key)
{
	t_list	*element;

	if (!(element = malloc(sizeof(*element))))
		return (NULL);
	element->content = content;
	element->key = key;
	element->next = NULL;
	return (element);
}
