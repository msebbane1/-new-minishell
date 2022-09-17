/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remplace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbally <lbally@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 13:10:44 by lbally            #+#    #+#             */
/*   Updated: 2022/09/15 15:59:49 by lbally           ###   ########.fr       */
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
	return (parse);
}
