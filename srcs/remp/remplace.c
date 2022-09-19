/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remplace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbally <lbally@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 13:10:44 by lbally            #+#    #+#             */
/*   Updated: 2022/09/18 17:29:07 by lbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_parse	*remplace(t_parse *parse, t_exp *atc)
{
	int	i;

	i = 0;
	cmdi(parse, atc);
	flagi(parse, atc);
	while (parse->arg[i])
	{
		argi(parse, atc, parse->arg[i], i);
		i++;
	}
	printf("test = |%s|\n", parse->cmd);
	printf("test = |%s|\n", parse->flag);
	printf("test = |%s|\n\n\n", parse->arg[0]);
	return (parse);
}
