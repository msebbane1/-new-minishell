/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brain.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vl-hotel <vl-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 20:35:11 by vl-hotel          #+#    #+#             */
/*   Updated: 2022/10/10 17:43:39 by vl-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	exitstatus(int status)
{
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	else if (WIFSIGNALED(status))
		return (WTERMSIG(status) + 128);
	else if (WIFSTOPPED(status))
		return (WTERMSIG(status) + 128);
	return (0);
}

void	ft_fils(t_parse *elem, t_list *alst, t_exp *atc, int fdin)
{
	pid_t	pid;
	int		fd[2];
	int		t;

	if (!elem)
		return ;
	if (pipe(fd) == -1)
		msg_error("pipe error\n");
	pid = fork();
	if (pid == 0)
	{
		close(fd[0]);
		dupfunction(elem, fd, fdin);
		execlab(elem, alst, atc);
	}
	else
	{
		close(fd[1]);
		ft_fils(elem->next, alst, atc, fd[0]);
		close(fd[0]);
		waitpid(pid, &elem->exit_code, 0);
		t = exitstatus(elem->exit_code);
		if (elem->indice == len_parse())
			g_global.status = t;
	}
}

void	dupfunction(t_parse *elem, int *fd, int fdin)
{
	if (elem->outfile != 1 || elem->indice == len_parse())
		dup2(elem->outfile, STDOUT_FILENO);
	else
		dup2(fd[1], STDOUT_FILENO);
	if (elem->infile != 0)
		dup2(elem->infile, STDIN_FILENO);
	else
		dup2(fdin, STDIN_FILENO);
	if (elem->infile < 0)
	{
		perror(elem->sfile);
		g_global.status = 1;
		exit (1);
	}
}

void	brain(t_list *alst, t_exp *atc)
{
	t_parse	*elem;

	init_signals();
	elem = g_global.parse;
	echo_control_seq(1);
	if (cmdin_parse(elem) == 1)
		return ;
	else if (elem->indice == len_parse())
	{
		if (elem->infile < 0)
		{
			perror(elem->sfile);
			return ;
		}
		dup2(elem->infile, STDIN_FILENO);
		dup2(elem->outfile, STDOUT_FILENO);
		execlab(elem, alst, atc);
	}
	else
		ft_fils(elem, alst, atc, elem->infile);
}
