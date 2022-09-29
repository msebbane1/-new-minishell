/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flagi.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msebbane <msebbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 18:01:52 by lbally            #+#    #+#             */
/*   Updated: 2022/09/29 17:16:04 by msebbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	flagi3(t_parse *parse, t_remp *remp)
{
	char	*str;

	remp->i = 0;
	remp->d = 0;
	str = NULL;
	str = malloc(sizeof(char) * (remp->h - remp->r + 1));
	while (remp->i < remp->h)
	{
		if (!ft_cmpchar(parse->flag[remp->i], '\"'))
		{
			remp->i++;
			continue ;
		}
		str[remp->d] = parse->flag[remp->i];
		remp->d++;
		remp->i++;
	}
	str[remp->d] = '\0';
	parse->flag = str;
}

void	flagi4(t_parse *parse, t_remp *remp)
{
	char	*str;

	remp->i = 0;
	remp->d = 0;
	str = NULL;
	str = malloc(sizeof(char) * (remp->h - remp->c + 1));
	while (parse->flag[remp->i])
	{
		if (!ft_cmpchar(parse->flag[remp->i], '\''))
		{
			remp->i++;
			continue ;
		}
		str[remp->d] = parse->flag[remp->i];
		remp->i++;
		remp->d++;
	}
	str[remp->d] = '\0';
	printf("STr === %s\n", str);
	parse->flag = str;
}

void	flagi2(t_parse *parse, t_remp *remp)
{
	remp->i = 0;
	remp->d = 0;
	if (remp->c == 0)
		flagi3(parse, remp);
	else
		flagi4(parse, remp);
}

void	flagi(t_parse *parse, t_exp *atc, t_remp *remp)
{
	char	*str;

	remp->i = 0;
	remp->d = 0;
	remp->g = 0;
	remp->r = 0;
	remp->c = 0;
	str = NULL;
	flagi5(remp, parse);
	if (remp->g == 0)
		flagi2(parse, remp);
	else
	{
		while (parse->flag[remp->i])
		{
			flagi_12(remp, parse, str, atc);
			remp->i++;
		}
	}
}
