/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msebbane <msebbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 11:26:14 by lbally            #+#    #+#             */
/*   Updated: 2022/09/07 12:49:24 by msebbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	dollar(t_list *alst, char *str)
{
	t_list	*list;
	int		i;

	list = alst;
	i = 0;
	if (!str[0])
		printf(" $: command not found\n");
	while (list)
	{
		if (!ft_strcmp(str, list->key))
			printf("%s: is a directory\n", list->content);
		list = list->next;
	}
	if (ft_isdigit(str[i]))
	{
		i++;
		if (str[i])
			printf(" %s: command not found\n",
				ft_substr(str, i, ft_strlen(str)));
	}
	g_global.status = 0;
}
