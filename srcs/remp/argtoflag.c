/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argtoflag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbally <lbally@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 16:27:22 by vl-hotel          #+#    #+#             */
/*   Updated: 2022/09/28 22:01:50 by lbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	count_dolarg(t_parse *tete)
{
	int	i;

	i = 0;
	while (tete->arg[i][0] == '-')
	{
		i++;
	}
	return (i);
}

void	argtoflag(int n, t_parse *tete)
{
	int		i;
	char	*nextw;

	i = 0;
	while (i < n)
	{
		nextw = tete->arg[i];
		tete->flag = ft_strjoin_no_spc(tete->flag, nextw);
		i++;
	}
}

void	replace_arg_flag(void)
{
	t_parse	*tete;
	int		n;

	tete = g_global.parse;
	while (tete)
	{
		n = count_dolarg(tete);
		argtoflag(n, tete);
		tete->arg = ft_realloc2char(tete->arg, len_envp(tete->arg) + 1, n);
		tete = tete->next;
	}
}
