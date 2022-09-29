/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmdi3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbally <lbally@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 09:42:10 by lbally            #+#    #+#             */
/*   Updated: 2022/09/29 09:49:09 by lbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	cmdi_10(t_parse *parse, t_remp *remp, char *doll, t_exp *atc)
{
	doll = cmdi5(parse, remp, doll);
	while (atc)
	{
		if (!ft_strcmp(doll, atc->name))
		{
			doll = atc->mean;
			remp->d++;
		}
		atc = atc->next;
	}
	if (remp->d == 0)
		doll = NULL;
	else
	{
		remp->d = 0;
		while (doll[remp->d])
			remp->d++;
	}
	cmdi7(parse, remp, doll);
}

void	cmdi_11(t_parse *parse, t_remp *remp, char *doll, t_exp *atc)
{
	if (!ft_cmpchar(parse->cmd[remp->i], '\''))
		remp->d++;
	if (!ft_cmpchar(parse->cmd[remp->i], '$') || remp->d != 0)
	{
		remp->i++;
		if (!ft_cmpchar(parse->cmd[remp->i], '?'))
			parse->cmd = ft_itoa(g_global.status);
		else if (!parse->cmd[remp->i])
			parse->cmd = parse->cmd;
		else if (ft_isdigit(parse->cmd[remp->i])
			|| (remp->d != 0 && remp->c != 0))
		{
			doll = dollar(parse->cmd, remp->c);
			parse->cmd = doll;
		}
		else
			cmdi_10(parse, remp, doll, atc);
	}
}
