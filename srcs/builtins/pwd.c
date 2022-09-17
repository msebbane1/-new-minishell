/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msebbane <msebbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 14:02:00 by lbally            #+#    #+#             */
/*   Updated: 2022/09/09 14:02:22 by msebbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_pwd(t_list *alst)
{
	t_list	*elem;

	elem = alst;
	while (elem)
	{
		if (!ft_strcmp(elem->key, "PWD"))
			printf("%s\n", elem->content);
		elem = elem->next;
	}
	g_global.status = 0;
}
