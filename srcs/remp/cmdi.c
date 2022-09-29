/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmdi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbally <lbally@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 18:00:55 by lbally            #+#    #+#             */
/*   Updated: 2022/09/29 12:13:44 by lbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	cmdi4(t_parse *parse, t_remp *remp, char *doll)
{
	doll = malloc(sizeof(char) * (remp->h - remp->c + 1));
	while (parse->cmd[remp->i])
	{
		if (!ft_cmpchar(parse->cmd[remp->i], '\''))
		{
			remp->i++;
			continue ;
		}
		doll[remp->d] = parse->cmd[remp->i];
		remp->i++;
		remp->d++;
	}
	doll[remp->d] = '\0';
	parse->cmd = doll;
}

void	cmdi3(t_parse *parse, t_remp *remp, char *doll)
{
	if (remp->c == 0)
	{
		doll = NULL;
		doll = malloc(sizeof(char) * (remp->h - remp->r + 1));
		while (remp->i < remp->h)
		{
			if (!ft_cmpchar(parse->cmd[remp->i], '\"'))
			{
				remp->i++;
				continue ;
			}
			doll[remp->d] = parse->cmd[remp->i];
			remp->i++;
			remp->d++;
		}
		doll[remp->d] = '\0';
		free (parse->cmd);
		parse->cmd = NULL;
		parse->cmd = doll;
	}
	else
		cmdi4(parse, remp, doll);
}

void	cmdi2(t_parse *parse, t_remp *remp)
{
	while (parse->cmd[remp->i])
	{
		if (!ft_cmpchar(parse->cmd[remp->i], '\"'))
			remp->r++;
		if (!ft_cmpchar(parse->cmd[remp->i], '\'') && remp->r == 0)
			remp->c++;
		if (!ft_cmpchar(parse->cmd[remp->i], '$'))
		{
			while (parse->cmd[remp->i])
			{
				if (!ft_cmpchar(parse->cmd[remp->i], '\"'))
					remp->r++;
				if (!ft_cmpchar(parse->cmd[remp->i], '\'') && remp->r == 0)
					remp->c++;
				remp->i++;
				remp->g++;
			}
		}
		remp->i++;
	}
	remp->h = remp->i;
	remp->i = 0;
}

void	cmdi(t_parse *parse, t_exp *atc, t_remp *remp)
{
	char	*doll;

	remp->i = 0;
	remp->d = 0;
	remp->g = 0;
	remp->r = 0;
	remp->c = 0;
	cmdi2(parse, remp);
	doll = NULL;
	if (remp->g == 0)
		cmdi3(parse, remp, doll);
	else
	{
		while (parse->cmd[remp->i])
		{
			cmdi_11(parse, remp, doll, atc);
			remp->i++;
		}
	}
}
