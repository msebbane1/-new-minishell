/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vl-hotel <vl-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 13:04:02 by msebbane          #+#    #+#             */
/*   Updated: 2022/10/02 22:11:33 by vl-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	msg_error(char *err)
{
	perror(err);
	exit (1);
}

int	ft_flag(char *line, int i, t_parse *tete)
{
	int		j;
	char	*nextw;
	char	*tmp;

	i++;
	j = i;
	nextw = nextword(line + i, &j);
	if (tete->first == 0)
	{
		tmp = ft_strdup("-");
		tete->cmd = ft_strjoin_no_spc(tmp, nextw);
		tete->first++;
	}
	else
		tete->flag = ft_strjoin_no_spc(tete->flag, nextw);
	return (j);
}

t_parse	*ft_lstnew_parse(void)
{
	t_parse	*newlist;

	g_global.indice[0] += 1;
	newlist = malloc(sizeof(t_parse));
	if (!newlist)
		return (NULL);
	newlist->first = 0;
	newlist->indice = g_global.indice[0];
	newlist->infile = 0;
	newlist->i = 0;
	newlist->outfile = 1;
	newlist->fd_kill = 0;
	newlist->next = NULL;
	newlist->flag = ft_strncpy("-", 1);
	newlist->arg = malloc(sizeof(char *));
	newlist->arg[0] = NULL;
	newlist->cmd = NULL;
	newlist->sfile = NULL;
	newlist->exit_code = 0;
	return (newlist);
}

void	ft_lstadd_back_parse(t_parse **alst, t_parse *new)
{
	t_parse	*tmp;

	if (!*alst)
		*alst = new;
	else
	{
		tmp = ft_parselast(*alst);
		tmp->next = new;
	}
}

void	lexer(char *line)
{
	int		i;
	t_parse	*tete;

	i = 0;
	g_global.parse = ft_lstnew_parse();
	tete = g_global.parse;
	while (line[i])
	{
		while ((line[i] && (line[i] == ' ' || line[i] == '\t')))
			i++;
		if (line[i] == 34 || line[i] == 39)
			i = gestion_quotes(line, i, tete);
		else if (ft_strchr("><", line[i]) != NULL)
			i = redirection_v(line, i, tete);
		else if (line[i] == '-' && line[i + 1] != '-' && tete->arg[0] == NULL)
			i = ft_flag(line, i, tete);
		else if (line[i] == '|')
			tete = ft_pipe(tete, &i);
		else
			i = ft_cmd_arg(line, i, tete);
	}
	if (tete->sfile == NULL || !tete->sfile)
		tete->sfile = ft_strdup("NOinfile");
}
