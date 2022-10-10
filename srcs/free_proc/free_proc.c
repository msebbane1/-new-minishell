/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_proc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msebbane <msebbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 16:45:22 by vl-hotel          #+#    #+#             */
/*   Updated: 2022/10/10 14:04:51 by msebbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	killhere(void)
{
	t_parse	*tete;

	tete = g_global.parse;
	while (tete)
	{
		if (tete->fd_kill > 0)
		{
			close(tete->fd_kill);
		}
		tete = tete->next;
	}
	unlink("/tmp/heredoc.tmp");
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab && tab[i] != '\0')
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	free_all(void)
{
	t_parse	*tete;
	t_parse	*tmp;

	tete = g_global.parse;
	killhere();
	while (tete)
	{
		tmp = tete->next;
		free_tab(tete->arg);
		free(tete->cmd);
		free(tete->flag);
		if (tete->infile != 0)
			close(tete->infile);
		if (tete->outfile != 1)
			close(tete->outfile);
		free(tete->sfile);
		free(tete);
		tete = tmp;
	}
	free(g_global.indice);
	dup2(g_global.old_stdin, STDIN_FILENO);
	dup2(g_global.old_stdout, STDOUT_FILENO);
}
