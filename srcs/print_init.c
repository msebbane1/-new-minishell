/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vl-hotel <vl-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 12:23:58 by lbally            #+#    #+#             */
/*   Updated: 2022/09/25 21:00:42 by vl-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	print_exp(t_exp *atc)
{
	t_exp	*lala;

	lala = atc;
	while (lala)
	{
		if (!ft_strcmp(lala->mean, "(null)"))
			printf("declare -x %s \n", lala->name);
		else
			printf("declare -x %s=\"%s\" \n", lala->name, lala->mean);
		lala = lala->next;
	}
}

void	print_list(t_list *alst)
{
	while (alst)
	{
		printf("%s=%s \n", alst->key, alst->content);
		alst = alst->next;
	}
	g_global.status = 0;
}

void	print_tab(char ** tab)
{
	int	i;
	i = 0;
	while (tab && tab[i])
	{
		printf("%s\n", tab[i]);
		i++;	
	}
}

void	print_global(void)
{
	int		i;
	t_parse	*tete;
	int		count;

	i = 0;
	count = 0;
	printf("debut de print global\n");
	tete = g_global.parse;
	while (tete)
	{
		printf("\nParse numero %i\n", count);
		printf("\nindice %i\n", tete->indice);
		printf("cmd = %s, flag = %s\n", tete->cmd, tete->flag);
		printf("infile = %i, outfile = %i\n", tete->infile, tete->outfile);
		while (tete->arg && tete->arg[i])
		{
			printf("argument n: %i = %s\n", i, tete->arg[i]);
			i++;
		}
		i = 0;
		tete = tete->next;
		count++;
	}
}