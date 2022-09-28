/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbally <lbally@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/05 11:18:59 by lbally            #+#    #+#             */
/*   Updated: 2022/09/28 13:17:51 lbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	unset(t_list **alst, t_exp **atc)
{
	t_list	*head;
	t_list	*temp;
	t_parse	*elem;
	t_exp	*head2;
	t_exp	*temp2;
	int		i;

	head = *alst;
	head2 = *atc;
	elem = g_global.parse;
	i = 0;
	while (elem->arg[i])
	{
		while ((*alst)->next)
		{
			if ((*alst)->next && !ft_strcmp((*alst)->next->key, elem->arg[i]))
			{
				free((*alst)->next->content);
				free((*alst)->next->key);
				temp = (*alst)->next;
				(*alst)->next = (*alst)->next->next;
				free(temp);
				break ;
			}
			(*alst) = (*alst)->next;
		}
		*alst = head;
		i++;
	}
	i = 0;
	while (elem->arg[i])
	{
		while (*atc)
		{
			if ((*atc)->next && !ft_strcmp((*atc)->next->name, elem->arg[i]))
			{
				free((*atc)->next->mean);
				free((*atc)->next->name);
				temp2 = (*atc)->next;
				(*atc)->next = (*atc)->next->next;
				free(temp2);
				break ;
			}
			(*atc) = (*atc)->next;
		}
		*atc = head2;
		i++;
	}
	g_global.status = 0;
}
