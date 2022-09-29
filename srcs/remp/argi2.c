/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argi2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbally <lbally@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 10:11:04 by lbally            #+#    #+#             */
/*   Updated: 2022/09/29 11:35:24 by lbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*argi6(char *arg, t_remp *remp, char *dolli)
{
	remp->d = 0;
	dolli = malloc(sizeof(char) * (remp->g - 1));
	while (arg[remp->i])
	{
		if (!ft_cmpchar(arg[remp->i], '\"') && remp->c == 0)
			break ;
		if (!ft_cmpchar(arg[remp->i], '\'') && remp->c == 0)
			break ;
		dolli[remp->d] = arg[remp->i];
		remp->i++;
		remp->d++;
	}
	return (dolli);
}

char	*argi5(char *arg, t_remp *remp, char *dolli)
{
	if (remp->r == 0)
	{
		remp->d = 0;
		dolli = ft_calloc(remp->g, sizeof(char));
		while (arg[remp->i])
		{
			if (!ft_cmpchar(arg[remp->i], '\''))
				break ;
			dolli[remp->d] = arg[remp->i];
			remp->i++;
			remp->d++;
		}
		dolli[remp->d] = '\0';
	}
	else
		dolli = argi6(arg, remp, dolli);
	remp->g = remp->i;
	remp->d = 0;
	remp->i = 0;
	return (dolli);
}

void	argi_10(char *arg, t_remp *remp)
{
	if (!ft_cmpchar(arg[remp->i], '\"') && remp->c == 0)
		remp->i++;
	if (!ft_cmpchar(arg[remp->i], '\'') && remp->c != 0)
		remp->i++;
}

char	*argi9(char *arg, t_remp *remp, char *dolli, char *lala)
{
	while (arg[remp->i])
	{
		argi_10(arg, remp);
		if (!ft_cmpchar(arg[remp->i], '$'))
		{
			if (dolli != NULL)
			{
				while (ft_isprint(dolli[remp->h]) == 1)
				{
					lala[remp->d] = dolli[remp->h];
					remp->d++;
					remp->h++;
				}
			}
			while (remp->i < remp->g)
				remp->i++;
		}
		argi_10(arg, remp);
		lala[remp->d] = arg[remp->i];
		remp->i++;
		remp->d++;
	}
	return (lala);
}

void	argi8(char *arg, t_remp *remp, char *dolli, t_parse *parse)
{
	char	*lala;

	lala = malloc(sizeof(char) * (remp->h - remp->g + remp->d));
	remp->d = 0;
	remp->h = 0;
	lala = argi9(arg, remp, dolli, lala);
	parse->arg[remp->w] = lala;
	printf("LALA === %s\n", parse->arg[remp->w]);
}
