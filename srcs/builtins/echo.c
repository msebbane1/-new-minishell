/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vl-hotel <vl-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 13:05:35 by msebbane          #+#    #+#             */
/*   Updated: 2022/10/02 21:37:11 by vl-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	echo_check_flag(char *str)
{
	int	i;

	i = 0;
	if (ft_strlen(str) == 1)
		return (0);
	while (str[i])
	{
		if (str[i] != '-' && str[i] != 'n')
		{
			return (1);
		}
		i++;
	}
	return (0);
}

int	helpecho(t_parse *parse, int *j)
{
	if (echo_check_flag(parse->flag) == 1 && *j > 0)
		return (0);
	if (echo_check_flag(parse->flag) == 1 && *j == 0)
	{
		printf("%s", parse->flag);
		*j += 1;
		return (0);
	}
	else if (ft_strlen(parse->flag) == 1)
		return (0);
	return (1);
}

void	ft_echo(t_parse *parse)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	helpecho(parse, &j);
	while (parse->arg && parse->arg[i])
	{
		if (j == 0 && parse->arg[i][0])
		{
			j = 1;
			printf("%s", parse->arg[i]);
		}
		else if (parse->arg[i][0])
			printf(" %s", parse->arg[i]);
		i++;
	}
	if (helpecho(parse, &j) == 0)
		printf("\n");
}
