/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remplace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbally <lbally@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 13:10:44 by lbally            #+#    #+#             */
/*   Updated: 2022/09/29 09:51:36 by lbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_parse	*remplace(t_parse *parse, t_exp *atc)
{
	t_remp	*remp;

	remp = malloc(sizeof(t_remp));
	if (parse->cmd)
		cmdi(parse, atc, remp);
	free(remp);
	remp = malloc(sizeof(t_remp));
	if (ft_strlen(parse->flag) > 1)
		flagi(parse, atc, remp);
	free(remp);
	remp = malloc(sizeof(t_remp));
	remp->w = 0;
	while (parse->arg[remp->w])
	{
		argi(parse, atc, parse->arg[remp->w], remp);
		remp->w++;
	}
	free(remp);
	return (parse);
}
