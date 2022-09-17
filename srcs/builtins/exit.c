/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msebbane <msebbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 11:33:10 by lbally            #+#    #+#             */
/*   Updated: 2022/09/13 11:21:20 by msebbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	ft_num(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	ft_exit(char **str)
{
	int	lolo;
	int	i;

	i = 0;
	printf("exit\n");
	i = 0;
	if (str[0])
	{
		if (!ft_num(str[0]))
			printf("exit: %s: numeric argument required\n", str[0]);
		else
		{
			lolo = ft_atoi(str[0]);
			i = lolo % 256;
			exit(EXIT_SUCCESS);
		}
	}
	exit(EXIT_SUCCESS);
}
