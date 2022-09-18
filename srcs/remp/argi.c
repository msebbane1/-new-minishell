/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbally <lbally@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 18:02:42 by lbally            #+#    #+#             */
/*   Updated: 2022/09/18 15:57:22 by lbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*no_qot(char *arg, int g, int i)
{
	char	*doll;
	int		d;

	d = 0;
	doll = malloc(sizeof(char) * (g));
	printf("DOLL1 ===== %s\n", doll);
	while (arg[i])
	{
		if (!ft_cmpchar(arg[i], '\''))
			break ;
		doll[d] = arg[i];
//					printf("LALA ===== %c\n", arg[i]);
//					printf("LALA1 ===== %c\n", doll[d]);
//					printf("LALA2 ===== %s\n", doll);
		i++;
		d++;
	}
	return (doll);
}

void	argi(t_parse *parse, t_exp *atc, char *arg, int w)
{
	char	*doll;
	int		i;
	int		d;
	int		h;
	int		g;
	int		r;
	int		c;
	char	*lala;

	i = 0;
	d = 0;
	g = 0;
	r = 0;
	c = 0;
	while (arg[i])
	{
		if (ft_cmpchar(arg[i], '$'))
		{
			while (arg[i])
			{
				if (!ft_cmpchar(arg[i], '\"'))
					r++;
				if (!ft_cmpchar(arg[i], '\'') && r == 0)
					c++;
				i++;
				g++;
			}
		}
		i++;
	}
	h = i;
	i = 0;
	printf("CMD2 ===== %s\n", arg);
	while (arg[i])
	{
		if (!ft_cmpchar(arg[i], '\''))
			d++;
		if (!ft_cmpchar(arg[i], '$') && (ft_cmpchar(arg[i + 1], '?') || d != 0))
		{
			i++;
			if (!arg[i])
				parse->arg[w] = arg;
			else if (ft_isdigit(arg[i]) || (d != 0 && c != 0))
			{
				doll = dollar(arg);
				parse->arg[w] = doll;
				printf("PIIPIP ====== %s\n\n", parse->arg[w]);
			}
			else
			{
				if (r == 0)
				{
					//					doll = no_qot(arg, g, i);
					d = 0;
				//	printf("GGGG ===== %d  DDD ====== %d  IIII ==== %d\n", g, d, i);
					doll = ft_calloc(g, sizeof(char));
				//	printf("DOLL1 ===== %s 1\n", doll);
					while (arg[i])
					{
						if (!ft_cmpchar(arg[i], '\''))
							break ;
						doll[d] = arg[i];
					// printf("ARG[I] ===== %c\n", arg[i]);
					// printf("DOLL[D] ===== %c\n", doll[d]);
					// printf("DOLL ===== %s\n", doll);
						i++;
						d++;
					}
					doll[d] = '\0';
					printf("DOLL1 ===== %s 1\n", doll);
				}
				else
				{
					d = 0;
					doll = malloc(sizeof(char) * (g - 1));
				//	printf("DOLL0 ===== %s 2\n", doll);
					while (arg[i])
					{
						if (!ft_cmpchar(arg[i], '\"') && c == 0)
							break ;
						if (!ft_cmpchar(arg[i], '\'') && c == 0)
							break ;
						doll[d] = arg[i];
						i++;
						d++;
					}
				}
				g = i;
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
				else
				{
					d = 0;
					while (doll[d])
						d++;
				}
				lala = malloc(sizeof(char) * (h - g + d));
				d = 0;
				h = 0;
				printf("DOLL ===== %s\n", doll);
				while (arg[i])
				{
					if (!ft_cmpchar(arg[i], '\"') && c == 0)
						i++;
					if (!ft_cmpchar(arg[i], '\'') && c != 0)
						i++;
					if (!ft_cmpchar(arg[i], '$'))
					{
						if (doll != NULL)
						{
							while (ft_isprint(doll[h]) == 1)
							{
//								if (!ft_cmpchar(arg[i], '\"') && c == 0)
//									i++;
								lala[d] = doll[h];
								d++;
								h++;
							}
						}
						while (i < g)
							i++;
			//			free (doll);
					}
					if (!ft_cmpchar(arg[i], '\"') && c == 0)
						i++;
					if (!ft_cmpchar(arg[i], '\'') && c != 0)
						i++;
					lala[d] = arg[i];
					i++;
					d++;
				}
				parse->arg[w] = lala;
			//	free (lala);
				printf("PAAPAP ====== %s\n\n", parse->arg[w]);
			}
		}
		i++;
	}
}