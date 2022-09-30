/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rempv.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vl-hotel <vl-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 21:29:39 by vl-hotel          #+#    #+#             */
/*   Updated: 2022/09/30 02:46:44 by vl-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "../../include/minishell.h"

char *ft_expand(char *str)
{
	char *res;
	int i;

	res = ft_strdup("");
	i = 0;
	while (str && str[i])
	{
		if(str[i] == '\'')
		{
			i++;
			res = repquotes(&i, res, str + i);
		}
		else if(str[i] == '\"')
		{
			i++;
			res = repdblquotes(&i, res, str + i);
		}
		else if(str[i] == '$')
		{
			i++;
			res = repdollar(&i, res, str + i);
		}
		else
			res = repelse(&i, res, str + i);
	}
	free(str);
	return (res);
}

void	remplacev(void)
{
	t_parse	*tete;
	int		i;

	i = 0;
	tete = g_global.parse;
	while (tete)
	{
		if (tete->cmd)
			tete->cmd = ft_expand(tete->cmd);
		if (tete->flag && ft_strlen(tete->flag) > 1)
			tete->flag = ft_expand(tete->flag);
		while(tete->arg && tete->arg[i])
		{
			tete->arg[i] = ft_expand(tete->arg[i]);
			i++;
		}
		tete = tete->next;
	}
}