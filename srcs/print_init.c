/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbally <lbally@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 12:23:58 by lbally            #+#    #+#             */
/*   Updated: 2022/10/05 21:15:07 by lbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	print_exp(t_exp *atc)
{
	t_exp	*lala;

	lala = atc;
	while (lala)
	{
		if (lala->mean == NULL)
			printf("declare -x %s=\"\" \n", lala->name);
		else if (!ft_strcmp(lala->mean, "(null)"))
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
		if (alst->content == NULL)
			printf("%s= \n", alst->key);
		else
			printf("%s=%s \n", alst->key, alst->content);
		alst = alst->next;
	}
	g_global.status = 0;
}

void	print_tab(char **tab)
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
		printf("infile = %s\n", tete->sfile);
		printf("exit code = %i\n", tete->exit_code);
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
