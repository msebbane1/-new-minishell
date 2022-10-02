/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_and_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vl-hotel <vl-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/16 15:53:53 by vl-hotel          #+#    #+#             */
/*   Updated: 2022/10/02 15:25:53 by vl-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_cmd_arg(char *line, int i, t_parse *tete)
{
	int		j;
	char	*nextw;

	j = i;
	nextw = nextword(line + i, &j);
	if (tete->first == 0)
	{
		tete->cmd = nextw;
		tete->first++;
	}
	else
	{
		tete->arg = ft_realloc2char(tete->arg, len_envp(tete->arg) + 1, 0);
		tete->arg[len_envp(tete->arg)] = nextw;
	}
	return (j);
}

char	**ft_realloc2char(char **src, int size, int start)
{
	char	**dest;
	int		i;

	i = 0;
	if (src == NULL)
		return (NULL);
	dest = ft_calloc(sizeof(char *), size - start + 1);
	while (start < size)
	{
		dest[i] = ft_strdup(src[start]);
		i++;
		start++;
	}
	free_tab(src);
	return (dest);
}

t_parse	*ft_pipe(t_parse *tete, int *i)
{
	*i += 1;
	if (tete->sfile == NULL || !tete->sfile)
		tete->sfile = ft_strdup("NOinfile");
	ft_lstadd_back_parse(&g_global.parse, ft_lstnew_parse());
	tete = tete->next;
	return (tete);
}
