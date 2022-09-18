/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vl-hotel <vl-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 14:42:54 by vl-hotel          #+#    #+#             */
/*   Updated: 2022/09/17 20:09:58 by vl-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	gestion_quotes(char *line, int i, t_parse *parse)
{
	int		j;
	char	*nextw;

	j = i;
	nextw = nextword(line + i, &j);
	if (nextw[1] == '-' && nextw[2] != '-')
	{
		nextw = trflag(nextw); // tu retourne le calloc nextw est free mais nouveau malloc dans nextw
		parse->flag = ft_strjoin_no_spc(parse->flag, nextw);
	}
	else if (parse->first == 0)
	{
		parse->cmd = nextw;
		parse->first++;
	}
	else
	{
		i = len_envp(parse->arg);
		printf("gestion quotes i =%i\n", i);
		parse->arg = ft_realloc2char(parse->arg, len_envp(parse->arg) + 1);
		ft_memcpy(parse->arg[i], nextw, ft_strlen(nextw));
	}
	return (j);
}

char	*trflag(char *str)
{
	int		i;
	int		t;
	char	*res;

	i = 0;
	t = 0;
	res = calloc(sizeof(char), ft_strlen(str));
	while (str && str[i])
	{
		if (i != 1)
		{
			res[t] = str[i];
			t++;
		}
		i++;
	}
	free(str);
	return (res);
}

int	verif_quotes(char *str, int i)
{
	char	indic;

	if (str[i] == 34)
		indic = str[i];
	else if (str[i] == 39)
		indic = str[i];
	else
	{
		return (i + 1);
	}
	if (str[i + 1])
		i++;
	while (str[i] && str[i] != indic)
		i++;
	if (str[i] != indic)
		msg_error("unclosed quotes");
	i++;
	return (i);
}
