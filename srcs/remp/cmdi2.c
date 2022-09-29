/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmdi2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbally <lbally@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 08:30:40 by lbally            #+#    #+#             */
/*   Updated: 2022/09/29 09:41:36 by lbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*cmdi6(t_parse *parse, t_remp *remp, char *doll)
{
	remp->d = 0;
	doll = malloc(sizeof(char) * (remp->g));
	while (parse->cmd[remp->i])
	{
		if (!ft_cmpchar(parse->cmd[remp->i], '\''))
			break ;
		doll[remp->d] = parse->cmd[remp->i];
		remp->i++;
		remp->d++;
	}
	remp->g = remp->i;
	return (doll);
}

char	*cmdi5(t_parse *parse, t_remp *remp, char *doll)
{
	if (remp->r != 0)
	{
		remp->d = 0;
		doll = malloc(sizeof(char) * (remp->g - 1));
		while (parse->cmd[remp->i])
		{
			if (!ft_cmpchar(parse->cmd[remp->i], '\"') && remp->c == 0)
				break ;
			if (!ft_cmpchar(parse->cmd[remp->i], '\'') && remp->c == 0)
				break ;
			doll[remp->d] = parse->cmd[remp->i];
			remp->i++;
			remp->d++;
		}
		remp->g = remp->i;
	}
	else
		doll = cmdi6(parse, remp, doll);
	remp->d = 0;
	remp->i = 0;
	return (doll);
}

void	cmdi9(t_parse *parse, t_remp *remp)
{
	if (!ft_cmpchar(parse->cmd[remp->i], '\"') && remp->c == 0)
		remp->i++;
	if (!ft_cmpchar(parse->cmd[remp->i], '\'') && remp->c != 0)
		remp->i++;
}

char	*cmdi8(t_parse *parse, t_remp *remp, char *lala, char *doll)
{
	while (parse->cmd[remp->i])
	{
		cmdi9(parse, remp);
		if (!ft_cmpchar(parse->cmd[remp->i], '$'))
		{
			if (doll != NULL)
			{
				while (ft_isprint(doll[remp->h]) == 1)
				{
					lala[remp->d] = doll[remp->h];
					remp->d++;
					remp->h++;
				}
			}
			while (remp->i < remp->g)
				remp->i++;
		}
		cmdi9(parse, remp);
		lala[remp->d] = parse->cmd[remp->i];
		remp->i++;
		remp->d++;
	}
	return (lala);
}

void	cmdi7(t_parse *parse, t_remp *remp, char *doll)
{
	char	*lala;

	lala = malloc(sizeof(char) * (remp->h - remp->g + remp->d));
	remp->d = 0;
	remp->h = 0;
	lala = cmdi8(parse, remp, lala, doll);
	parse->cmd = lala;
}
