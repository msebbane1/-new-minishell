/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argi3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbally <lbally@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 10:44:25 by lbally            #+#    #+#             */
/*   Updated: 2022/09/29 11:49:22 by lbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*argi7(t_remp *remp, char *dolli, t_exp *atc)
{
	while (atc)
	{
		if (!ft_strcmp(dolli, atc->name))
		{
			dolli = atc->mean;
			remp->d++;
		}
		atc = atc->next;
	}
	if (remp->d == 0)
	{
		dolli = NULL;
		return (dolli);
	}
	else
	{
		remp->d = 0;
		while (dolli[remp->d])
			remp->d++;
	}
	return (dolli);
}

int	argi_11(char *arg, t_remp *remp, char *dolli, t_parse *parse)
{
	if (!ft_cmpchar(arg[remp->i], '?'))
	{
		parse->arg[remp->w] = ft_itoa(g_global.status);
		return (1);
	}
	else if (!arg[remp->i])
	{
		parse->arg[remp->w] = arg;
		return (1);
	}
	else if (ft_isdigit(arg[remp->i])
		|| (remp->d != 0 && remp->c != 0))
	{
		dolli = dollar(arg, remp->c);
		parse->arg[remp->w] = dolli;
		return (1);
	}	
	return (0);
}

void	init(t_remp *remp)
{
	remp->i = 0;
	remp->d = 0;
	remp->g = 0;
	remp->r = 0;
	remp->c = 0;
}
