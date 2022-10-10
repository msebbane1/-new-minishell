/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rempv.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vl-hotel <vl-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 21:29:39 by vl-hotel          #+#    #+#             */
/*   Updated: 2022/10/10 17:46:12 by vl-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*inexpand(int *i, const char *res, char *str)
{
	char	*tmp;

	if (str[*i] == '\'')
	{
		*i += 1;
		tmp = repquotes(i, res, str);
	}
	else if (str[*i] == '\"')
	{
		*i += 1;
		tmp = repdblquotes(i, res, str);
	}
	else
	{
		*i += 1;
		tmp = repdollar(i, res, str);
	}
	return (tmp);
}

char	*ft_expand(char *str)
{
	char	*res;
	int		i;

	res = ft_strdup("");
	i = 0;
	while (str && str[i])
	{
		if (find(str[i], "\'\"$") == 1)
			res = inexpand(&i, res, str);
		else
			res = repelse(&i, res, str);
	}
	free(str);
	return (res);
}

char	*else_dbl(int *i, const char *res, char *str, int *t)
{
	int		size;
	char	*result;

	size = countbefc(str + *i, "\"$");
	if (*t == 0)
		result = ft_strjoin_no_spc(res, ft_strdup2(str + *i, size));
	else
		result = ft_strjoin_no_spc(result, ft_strdup2(str + *i, size));
	*t += 1;
	*i += size;
	return (result);
}

void	remplacev(void)
{
	t_parse	*tete;
	int		i;
	int		t;

	i = 0;
	t = 0;
	tete = g_global.parse;
	while (tete)
	{
		if (tete->cmd)
			tete->cmd = ft_expand(tete->cmd);
		if (tete->flag && ft_strlen(tete->flag) > 1)
			tete->flag = ft_expand(tete->flag);
		while (tete->arg && tete->arg[i])
		{
			tete->arg[i] = ft_expand(tete->arg[i]);
			i++;
		}
		i = 0;
		tete = tete->next;
	}
}
