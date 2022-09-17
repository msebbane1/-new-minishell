/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msebbane <msebbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 12:24:48 by lbally            #+#    #+#             */
/*   Updated: 2022/09/09 14:02:46 by msebbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	is_option(char *cmd)
{
	if (cmd[0] == '-')
		return (1);
	return (0);
}

int	is_redir(char *cmd)
{
	if (cmd[0] == '<' || cmd[0] == '>')
		return (1);
	return (0);
}

int	is_pipe(char *cmd)
{
	if (cmd[0] == '|')
		return (1);
	return (0);
}

int	ft_cmpchar(char s1, char s2)
{
	if (s1 != s2)
		return (1);
	else
		return (0);
}

int	back_slash(char *str)
{
	if (str[ft_strlen(str)] == '/')
		return (1);
	return (0);
}
