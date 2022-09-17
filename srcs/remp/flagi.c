/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flagi.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbally <lbally@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 18:01:52 by lbally            #+#    #+#             */
/*   Updated: 2022/09/15 15:59:42 by lbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	flagi(t_parse *parse, t_exp *atc)
{
	char *doll;
	int i;
	int d;
	int h;
	int g;
	int r;
	int c;
	char *lala;

	i = 0;
	d = 0;
	g = 0;
	r = 0;
	c = 0;
	lala = parse->flag;
//	if (!parse->flag)
//		return (parse);
	while (parse->flag[i])
	{
		if (ft_cmpchar(parse->flag[i], '$'))
		{
			while (parse->flag[i])
			{
				if (!ft_cmpchar(parse->flag[i], '\"'))
					r++;
				if (!ft_cmpchar(parse->flag[i], '\'') && r == 0)
					c++;
				i++;
				g++;
			}
		}
		i++;
	}
	h = i;
	i = 0;
//	printf("CMD2 ===== %s\n", parse->flag);
	while (parse->flag[i])
	{
		if (!ft_cmpchar(parse->flag[i], '\''))
			d++;
		if (!ft_cmpchar(parse->flag[i], '$') && (ft_cmpchar(parse->flag[i + 1], '?') || d != 0))
		{
			i++;
			if (!parse->flag[i])
				parse->flag = parse->flag;
//				return (parse);
			else if (ft_isdigit(parse->flag[i]) || (d != 0 && c != 0))
			{
				doll = dollar(parse->flag);
				parse->flag = doll;
				printf("PIIPIP ====== %s\n\n", parse->flag);
//				return (parse);
			}
			else
			{
				if (r != 0)
				{
					d = 0;
					doll = malloc(sizeof(char) * (g - 1));
					while (parse->flag[i])
					{
						if (!ft_cmpchar(parse->flag[i], '\"') && c == 0)
							break ;
						if (!ft_cmpchar(parse->flag[i], '\'') && c == 0)
							break ;
						doll[d] = parse->flag[i];
						i++;
						d++;
					}
					g = i;
				}
				else
				{
					d = 0;
					doll = malloc(sizeof(char) * (g));
					while (parse->flag[i])
					{
						printf("%d\n", i);
						if (!ft_cmpchar(parse->flag[i], '\''))
							break ;
						doll[d] = parse->flag[i];
						i++;
						d++;
					}
					g = i;
				}
				d = 0;
				i = 0;
				while (atc)
				{
					if (!ft_strcmp(doll, atc->name))
					{
						doll = atc->mean;
						d++;
					}
					atc = atc->next;
				}
				if (d == 0)
					doll = NULL;
				lala = malloc(sizeof(char) * (h - g + d));
				d = 0;
				h = 0;
//				printf("DOLL ===== %s\n", doll);
				while (parse->flag[i])
				{
					if (!ft_cmpchar(parse->flag[i], '\"') && c == 0)
						i++;
					if (!ft_cmpchar(parse->flag[i], '\'') && c != 0)
						i++;
					if (!ft_cmpchar(parse->flag[i], '$'))
					{
						if (doll != NULL)
						{
							while (ft_isprint(doll[h]) == 1)
							{
//								if (!ft_cmpchar(parse->flag[i], '\"') && c == 0)
//									i++;
								lala[d] = doll[h];
								d++;
								h++;
							}
						}
						while (i < g)
							i++;
					}
					if (!ft_cmpchar(parse->flag[i], '\"') && c == 0)
						i++;
					if (!ft_cmpchar(parse->flag[i], '\'') && c != 0)
						i++;
					lala[d] = parse->flag[i];
					i++;
					d++;
				}
				parse->flag = lala;
//				printf("PAAPAP ====== %s\n\n", parse->flag);
//				return (parse);
			}
		}
		i++;
	}
//	return (parse);
}
