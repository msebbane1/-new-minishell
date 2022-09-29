/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flagi3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbally <lbally@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 06:28:14 by lbally            #+#    #+#             */
/*   Updated: 2022/09/29 08:07:21 by lbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*flagi_10(t_remp *remp, t_parse *parse, char *str, char *lala)
{
	while (parse->flag[remp->i])
	{
		flagi9(remp, parse);
		if (!ft_cmpchar(parse->flag[remp->i], '$'))
		{
			if (str != NULL)
			{
				while (ft_isprint(str[remp->h]) == 1)
				{
					lala[remp->d] = str[remp->h];
					remp->d++;
					remp->h++;
				}
			}
			while (remp->i < remp->g)
				remp->i++;
		}
		flagi9(remp, parse);
		lala[remp->d] = parse->flag[remp->i];
		remp->i++;
		remp->d++;
	}
	return (lala);
}

void	flagi_11(t_remp *remp, t_parse *parse, char *str, t_exp *atc)
{
	str = flagi6(remp, parse);
	while (atc)
	{
		if (!ft_strcmp(str, atc->name))
		{
			str = atc->mean;
			remp->d++;
		}
		atc = atc->next;
	}
	if (remp->d == 0)
	str = NULL;
	else
	{
		remp->d = 0;
		while (str[remp->d])
			remp->d++;
	}
	flagi8(remp, parse, str);
}

void	flagi_12(t_remp *remp, t_parse *parse, char *str, t_exp *atc)
{
	if (!ft_cmpchar(parse->flag[remp->i], '\''))
		remp->d++;
	if (!ft_cmpchar(parse->flag[remp->i], '$')
		&& (ft_cmpchar(parse->flag[remp->i + 1], '?') || remp->d != 0))
	{
		remp->i++;
		if (!parse->flag[remp->i])
			parse->flag = parse->flag;
		else if (ft_isdigit(parse->flag[remp->i])
			|| (remp->d != 0 && remp->c != 0))
		{
			str = dollar(parse->flag, remp->c);
			parse->flag = str;
		}
		else
			flagi_11(remp, parse, str, atc);
	}
}
