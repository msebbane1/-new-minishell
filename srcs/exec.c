/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbally <lbally@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 13:04:43 by msebbane          #+#    #+#             */
/*   Updated: 2022/09/18 14:51:36 by lbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

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
		lab[1] = parse->flag;
	if (parse->arg != NULL)
	{
		while (parse->arg[t])
			lab[i++] = parse->arg[t++];
	}
	else
		return (NULL);
	return (lab);
}

char	**enov(t_list *alst)
{
	t_list	*list;
	int		i;
	char	**env;

	i = 0;
	list = alst;
	while (list)
	{
		list = list->next;
		i++;
	}
	env = malloc(sizeof(char **) * i + 1);
	i = 0;
	while (alst)
	{
		env[i] = ft_concatenate(alst->key, "=");
		env[i] = ft_strjoin(env[i], alst->content);
		i++;
		alst = alst->next;
	}
	env[i] = NULL;
	return (env);
}

void	ft_execve(t_parse *parse, t_list *alst, char **lab)
{
	int		pid;
	int		status;
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
		if (execve(check_path_access(alst, parse->cmd),
				lab, enov(alst)) == -1)
		{
			printf("%s: command not found dd\n", parse->cmd);
			g_global.status = 127;
			exit(EXIT_FAILURE);
		}
//		putenv_in_tab(alst);
	}
	else
		waitpid(pid, &status, 0);
}

/*
void	cmp_cmd(t_parse *parse, t_list *alst, t_exp *atc)
{
	if (!ft_strcmp(parse->cmd, "unset"))
		destroy(&alst, &atc);
	else if (!ft_strcmp(parse->cmd, "export"))
		port(atc, alst);
	else if (!ft_strcmp(parse->cmd, "$?"))
		printf(" %i: command not found\n", g_global.status);
	else if (!ft_cmpchar(parse->cmd[0], '$'))
		dollar(alst, parse->cmd + 1);
	else
	{
		printf("%s: command not found ss\n", parse->cmd);
		g_global.status = 127;
	}
}*/

void	exec_cmd(t_parse *parse, t_list *alst, t_exp *atc, char **lab)
{
	if (!ft_strcmp(tolower2(parse->cmd), "exit"))
		ft_exit(parse->arg);
	else if (!ft_strcmp(tolower2(parse->cmd), "env"))
		print_list(alst);
	else if (!ft_strcmp(tolower2(parse->cmd), "echo"))
		ft_echo(parse);
	else if (!ft_strcmp(tolower2(parse->cmd), "pwd"))
		ft_pwd(alst);
	else if (!ft_strncmp(parse->cmd, "cd", 2))
		change_dir(parse, alst);
	else if (!ft_strcmp(parse->cmd, "unset"))
		destroy(&alst, &atc);
	else if (!ft_strcmp(parse->cmd, "export"))
		port(atc, alst);
	else if (!ft_strcmp(parse->cmd, "$?"))
		printf(" %i: command not found\n", g_global.status);
	//else if (!ft_cmpchar(parse->cmd[0], '$'))
		//dollar(alst, parse->cmd + 1);
	else if (parse->cmd)
		ft_execve(parse, alst, lab);
	else
	{
		printf("%s: command not found ss\n", parse->cmd);
		g_global.status = 127;
	}
}

void	my_exec(t_list *alst, t_exp *atc)
{
	t_parse	*elem;
	char	**lab;
	int		i;

	elem = g_global.parse;
	i = 0;
	while (elem)
	{
		lab = check_elem(elem, alst, lab);
		if (lab[0] == NULL)
		{
			signals();
			return ;
		}
		exec_cmd(elem, alst, atc, lab);
		//free_tab(lab);
		elem = elem->next;
	}
}
