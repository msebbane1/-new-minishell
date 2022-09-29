/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbally <lbally@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 18:02:42 by lbally            #+#    #+#             */
/*   Updated: 2022/09/29 11:55:59 by lbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	argi4(char *arg, t_remp *remp, t_parse *parse, char *dolli)
{
	dolli = malloc(sizeof(char) * (remp->h - remp->c + 1));
	while (arg[remp->i])
	{
		if (!ft_cmpchar(arg[remp->i], '\''))
		{
			remp->i++;
			continue ;
		}
		dolli[remp->d] = arg[remp->i];
		remp->i++;
		remp->d++;
	}
	dolli[remp->d] = '\0';
	parse->arg[remp->w] = dolli;
}

void	argi3(char *arg, t_remp *remp, t_parse *parse, char *dolli)
{
	if (remp->c == 0)
	{
		dolli = NULL;
		dolli = malloc(sizeof(char) * (remp->h - remp->r + 1));
		while (arg[remp->i])
		{
			if (!ft_cmpchar(arg[remp->i], '\"'))
			{
				remp->i++;
				continue ;
			}
			dolli[remp->d] = arg[remp->i];
			remp->d++;
			remp->i++;
		}
		dolli[remp->d] = '\0';
		parse->arg[remp->w] = dolli;
	}
	else
		argi4(arg, remp, parse, dolli);
}

void	argi2(char *arg, t_remp *remp)
{
	while (arg[remp->i])
	{
		if (!ft_cmpchar(arg[remp->i], '\"'))
			remp->r++;
		if (!ft_cmpchar(arg[remp->i], '\'') && remp->r == 0)
			remp->c++;
		if (!ft_cmpchar(arg[remp->i], '$'))
		{
			while (arg[remp->i])
			{
				if (!ft_cmpchar(arg[remp->i], '\"'))
					remp->r++;
				if (!ft_cmpchar(arg[remp->i], '\'') && remp->r == 0)
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

void	argi0(char *arg, t_remp *remp)
{
	init(remp);
	argi2(arg, remp);
}

void	argi(t_parse *parse, t_exp *atc, char *arg, t_remp *remp)
{
	char	*dolli;

	dolli = NULL;
	argi0(arg, remp);
	if (remp->g == 0)
		argi3(arg, remp, parse, dolli);
	else
	{
		while (arg[remp->i])
		{
			if (!ft_cmpchar(arg[remp->i], '\''))
				remp->d++;
			if (!ft_cmpchar(arg[remp->i], '$') || remp->d != 0)
			{
				remp->i++;
				if (!argi_11(arg, remp, dolli, parse))
				{
					dolli = argi5(arg, remp, dolli);
					dolli = argi7(remp, dolli, atc);
					argi8(arg, remp, dolli, parse);
				}
			}
			remp->i++;
		}
	}
}
