/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flagi2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbally <lbally@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 22:24:42 by lbally            #+#    #+#             */
/*   Updated: 2022/09/29 08:01:18 by lbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	flagi5(t_remp *remp, t_parse *parse)
{
	while (parse->flag[remp->i])
	{
		if (!ft_cmpchar(parse->flag[remp->i], '\"'))
			remp->r++;
		if (!ft_cmpchar(parse->flag[remp->i], '\'') && remp->r == 0)
			remp->c++;
		if (!ft_cmpchar(parse->flag[remp->i], '$'))
		{
			while (parse->flag[remp->i])
			{
				if (!ft_cmpchar(parse->flag[remp->i], '\"'))
					remp->r++;
				if (!ft_cmpchar(parse->flag[remp->i], '\'') && remp->r == 0)
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

char	*flagi7(t_remp *remp, t_parse *parse)
{
	char	*str;

	remp->d = 0;
	str = malloc(sizeof(char) * (remp->g));
	while (parse->flag[remp->i])
	{
		if (!ft_cmpchar(parse->flag[remp->i], '\''))
			break ;
		str[remp->d] = parse->flag[remp->i];
		remp->i++;
		remp->d++;
	}
	str[remp->d] = '\0';
	remp->g = remp->i;
	return (str);
}

char	*flagi6(t_remp *remp, t_parse *parse)
{
	char	*str;

	if (remp->r != 0)
	{
		remp->d = 0;
		str = malloc(sizeof(char) * (remp->g - 1));
		while (parse->flag[remp->i])
		{
			if (!ft_cmpchar(parse->flag[remp->i], '\"') && remp->c == 0)
				break ;
			if (!ft_cmpchar(parse->flag[remp->i], '\'') && remp->c == 0)
				break ;
			str[remp->d] = parse->flag[remp->i];
			remp->i++;
			remp->d++;
		}
		remp->g = remp->i;
	}
	else
		str = flagi7(remp, parse);
	remp->d = 0;
	remp->i = 0;
	return (str);
}

void	flagi9(t_remp *remp, t_parse *parse)
{
	if (!ft_cmpchar(parse->flag[remp->i], '\"') && remp->c == 0)
		remp->i++;
	if (!ft_cmpchar(parse->flag[remp->i], '\'') && remp->c != 0)
		remp->i++;
}

void	flagi8(t_remp *remp, t_parse *parse, char *str)
{
	char	*lala;

	lala = malloc(sizeof(char) * (remp->h - remp->g + remp->d));
	remp->d = 0;
	remp->h = 0;
	lala = flagi_10(remp, parse, str, lala);
	parse->flag = lala;
}
