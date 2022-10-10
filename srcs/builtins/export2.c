/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbally <lbally@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/28 19:14:26 by lbally            #+#    #+#             */
/*   Updated: 2022/10/10 13:33:39 by lbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	**export4(char **tab)
{
	char	*temp;
	int		i;
	int		j;

	i = 0;
	while (tab[i])
	{
		j = i + 1;
		while (tab[j])
		{
			if (!ismore(tab[i], tab[j]))
			{
				temp = tab[i];
				tab[i] = tab[j];
				tab[j] = temp;
			}
			j++;
		}
		i++;
	}
	return (tab);
}

void	export2(char **tab, t_exp *atc)
{
	int		i;
	t_exp	*tmp;

	i = 0;
	tmp = atc;
	while (tab[i])
	{
		if (ft_find_space(tab[i]))
		{
			tmp->name = ft_prt(tab[i]);
			tmp->mean = ft_prt2(tab[i]);
		}
		else
			tmp->name = tab[i];
		tmp = tmp->next;
		i++;
	}
}

void	port2(t_list *alst, t_parse *elem, int p, t_exp *atc)
{
	int	i;

	i = check(elem->arg[p]);
	if (i == 0)
		printf("export: `%s': not a valid identifier\n", elem->arg[p]);
	else
	{
		if (i == 1)
		{
			add(atc, elem->arg[p]);
			add2(alst, elem->arg[p]);
		}
		else if (i == 2)
			add3(atc, elem->arg[p]);
		else if (i == 3)
		{
			add4(atc, elem->arg[p]);
			add5(alst, elem->arg[p]);
		}
		else
		{
			add6(atc, elem->arg[p]);
			add7(alst, elem->arg[p]);
		}
	}
}

void	port(t_exp *atc, t_list *alst)
{
	t_parse	*elem;
	int		i;
	int		p;

	elem = g_global.parse;
	i = 0;
	p = 0;
	if (elem->arg[0] == NULL)
		export(atc);
	else
	{
		while (elem->arg[p])
		{
			port2(alst, elem, p, atc);
			p++;
		}
	}
}
