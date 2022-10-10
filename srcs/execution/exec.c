/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vl-hotel <vl-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 13:04:43 by msebbane          #+#    #+#             */
/*   Updated: 2022/10/10 18:11:19 by vl-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	**check_elem(t_parse *parse, t_list *alst, char **lab)
{
	int		i;
	int		t;
	int		size;

	t = 0;
	i = 1;
	size = len_envp(parse->arg) + 2;
	if (ft_strlen(parse->flag) > 1)
	{
		i++;
		size++;
	}
	lab = ft_calloc(sizeof(char *), size);
	if (parse->cmd != NULL)
		lab[0] = check_path_access(alst, parse->cmd);
	if (ft_strlen(parse->flag) > 1)
		lab[1] = ft_strdup(parse->flag);
	if (parse->arg != NULL)
	{
		while (parse->arg[t])
			lab[i++] = ft_strdup(parse->arg[t++]);
	}
	return (lab);
}

char	**enov(t_list *alst)
{
	t_list	*list;
	int		i;
	char	**env;

	list = alst;
	i = ft_lstsize(list);
	env = malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (alst)
	{
		env[i] = ft_concatenate(alst->key, "=");
		env[i] = ft_concatenate(env[i], alst->content);
		i++;
		alst = alst->next;
	}
	env[i] = NULL;
	return (env);
}

void	ft_execve(t_parse *parse, t_list *alst, char **lab)
{
	int		pid;
	int		i;

	pid = fork();
	i = 0;
	if (pid == -1)
	{
		perror("Fork failed");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		if (execve(lab[0],
				lab, enov(alst)) == -1)
		{
			ft_err_excve(parse);
			exit(g_global.status);
		}
	}
	else
	{
		waitpid(pid, &parse->exit_code, 0);
		g_global.status = exitstatus(parse->exit_code);
	}
}

void	exec_cmd(t_parse *parse, t_list *alst, t_exp *atc, char **lab)
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
		ft_execve(parse, alst, lab);
}
