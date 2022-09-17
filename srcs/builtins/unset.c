/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msebbane <msebbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 11:18:59 by lbally            #+#    #+#             */
/*   Updated: 2022/09/09 14:02:26 by msebbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	destroy(t_list **alst, t_exp **atc)
{
	t_list	*head;
	t_list	*temp;
	t_parse	*elem;
	t_exp	*head2;
	t_exp	*temp2;

	head = *alst;
	head2 = *atc;
	elem = g_global.parse;
	while (*alst && elem->arg[0] != NULL)
	{
		if ((*alst)->next && !ft_strcmp((*alst)->next->key, elem->arg[0]))
		{
			free((*alst)->next->content);
			free((*alst)->next->key);
			temp = (*alst)->next;
			(*alst)->next = (*alst)->next->next;
			free(temp);
			*alst = head;
			break ;
		}
		(*alst) = (*alst)->next;
	}
	while (*atc && elem->arg[0] != NULL)
	{
		if ((*atc)->next && !ft_strcmp((*atc)->next->name, elem->arg[0]))
		{
			free((*atc)->next->mean);
			free((*atc)->next->name);
			temp2 = (*atc)->next;
			(*atc)->next = (*atc)->next->next;
			free(temp2);
			*atc = head2;
			break ;
		}
		(*atc) = (*atc)->next;
	}
	g_global.status = 0;
}
