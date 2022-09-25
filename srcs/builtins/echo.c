/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vl-hotel <vl-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 13:05:35 by msebbane          #+#    #+#             */
/*   Updated: 2022/09/25 16:09:06 by vl-hotel         ###   ########.fr       */
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
		printf("[echo_flag] %c\n", str[i]);
		if (str[i] != '-' && str[i] != 'n')
		{
			printf("[echo_flag] in return %c\n", str[i]);
			return (1);
		}
		i++;
	}
	return (0);
}

void	ft_echo(t_parse *parse)
{
	int	i;
	int	t;

	t = 0;
	i = 0;
	if (echo_check_flag(parse->flag) == 1)
		printf("%s ", parse->flag);
	else if (ft_strlen(parse->flag) == 1)
		t = 0;
	else
		t = 1;
	while (parse->arg && parse->arg[i])
	{
		if (i == 0)
			printf("%s", parse->arg[i]);
		else
			printf(" %s", parse->arg[i]);
		i++;
	}
	if (t == 0)
		printf("\n");
}
