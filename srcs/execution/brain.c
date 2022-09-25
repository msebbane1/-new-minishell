/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brain.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vl-hotel <vl-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 20:35:11 by vl-hotel          #+#    #+#             */
/*   Updated: 2022/09/25 12:28:34 by vl-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	ft_fils(t_parse *elem, t_list *alst, t_exp *atc, int fdin)
{
	pid_t	pid;
	int		fd[2];

	if (!elem)
		return ;
	if (pipe(fd) == -1)
		msg_error("pipe error\n");
	pid = fork();
	if (pid == -1)
		msg_error("fork error\n");
	if (pid == 0)
	{
		close(fd[0]);
		if (elem->outfile != 1)
			dup2(elem->outfile, STDOUT_FILENO);
		else
			dup2(fd[1], STDOUT_FILENO);
		dup2(fdin, STDIN_FILENO);
		execlab(elem, alst, atc);
	}
	else
	{
		close(fd[1]);
		ft_fils(elem->next, alst, atc, fd[0]);
		close(fd[0]);
		waitpid(pid, NULL, 0);
	}
}

void	brain(t_list *alst, t_exp *atc)
{
	t_parse	*elem;

	elem = g_global.parse;
	if (cmdin_parse(elem) == 1)
		return ;
	else if (elem->indice == len_parse())
	{
		dup2(elem->infile, STDIN_FILENO);
		dup2(elem->outfile, STDOUT_FILENO);
		execlab(elem, alst, atc);
	}
	else
		ft_fils(elem, alst, atc, elem->infile);
}
