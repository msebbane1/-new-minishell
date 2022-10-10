/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilexec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vl-hotel <vl-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 20:36:02 by vl-hotel          #+#    #+#             */
/*   Updated: 2022/10/10 18:11:07 by vl-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	len_parse(void)
{
	t_parse	*lst;
	int		i;

	i = 0;
	lst = g_global.parse;
	while (lst)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

int	cmdin_parse(t_parse *parse)
{
	t_parse	*lst;

	lst = parse;
	while (lst)
	{
		if (lst->infile == 0 && lst->outfile == 1
			&& lst->cmd == NULL && ft_strlen(lst->flag) == 1)
		{
			if (len_parse() == 1)
				return (1);
			ft_putstr_fd("syntax error near unexpected token `|'\n", 2);
			g_global.status = 258;
			return (1);
		}
		if ((lst->infile == -1 || lst->outfile == -1)
			&& lst->sfile[0] == '\0')
		{
			ft_putstr_fd("syntax error near unexpected token `newline'\n", 2);
			g_global.status = 258;
			return (1);
		}
		lst = lst->next;
	}
	return (0);
}

void	exec_cmdmulti(t_parse *parse, t_list *alst, t_exp *atc, char **lab)
{
	if (!ft_strcmp(parse->cmd, "exit"))
		ft_exit(parse->arg);
	else if (!ft_strcmp(tolower2(parse->cmd), "env"))
		print_list(alst);
	else if (!ft_strcmp(tolower2(parse->cmd), "echo"))
		ft_echo(parse);
	else if (!ft_strcmp(tolower2(parse->cmd), "pwd"))
		ft_pwd();
	else if (!ft_strncmp(parse->cmd, "cd", 2))
		cd(parse, alst);
	else if (!ft_strcmp(parse->cmd, "unset"))
		unset(&alst, &atc);
	else if (!ft_strcmp(parse->cmd, "export"))
		port(atc, alst);
	else
	{
		if (execve(lab[0],
				lab, enov(alst)) == -1)
		{
			ft_err_excve(parse);
		}
	}
}

void	execlab(t_parse *elem, t_list *alst, t_exp *atc)
{
	char	**lab;

	lab = NULL;
	lab = check_elem(elem, alst, lab);
	if (len_parse() == 1)
		exec_cmd(elem, alst, atc, lab);
	else
	{
		exec_cmdmulti(elem, alst, atc, lab);
		free_tab(lab);
		exit(0);
	}
	free_tab(lab);
}
