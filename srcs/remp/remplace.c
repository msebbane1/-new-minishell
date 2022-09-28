/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remplace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msebbane <msebbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 13:10:44 by lbally            #+#    #+#             */
/*   Updated: 2022/09/28 18:20:33 by msebbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

t_parse	*remplace(t_parse *parse, t_exp *atc)
{
	int	i;

	i = 0;
	if (parse->cmd)
		cmdi(parse, atc);
	if (ft_strlen(parse->flag) > 1)
		flagi(parse, atc);
	while (parse->arg[i])
	{
		argi(parse, atc, parse->arg[i], i);
		i++;
	}
	return (parse);
}
