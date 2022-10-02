/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_proc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vl-hotel <vl-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 16:45:22 by vl-hotel          #+#    #+#             */
/*   Updated: 2022/10/01 23:12:35 by vl-hotel         ###   ########.fr       */
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
	t_parse *tmp;

	// printf("debut de free_all\n");
	tete = g_global.parse;
	killhere();
	while (tete)
	{
		tmp = tete->next;
		// printf("ARG -----\n");
		free_tab(tete->arg);
		// printf("CMD -----\n");
		free(tete->cmd);
		// printf("FLAG -----\n");
		free(tete->flag);
		// printf("CLOSE -----\n");
		if (tete->infile != 0)
			close(tete->infile);
		if (tete->outfile != 1)
			close(tete->outfile);
		// printf("SFILE -----\n");
		free(tete->sfile);
		// printf("TETE -----\n");
		free(tete);
		tete = tmp;
	}
	// printf("END boucle free -----\n");
	free(g_global.indice);
	dup2(g_global.old_stdin, STDIN_FILENO);
	dup2(g_global.old_stdout, STDOUT_FILENO);
}
