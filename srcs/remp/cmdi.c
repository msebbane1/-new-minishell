/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmdi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbally <lbally@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 18:00:55 by lbally            #+#    #+#             */
/*   Updated: 2022/09/19 12:48:29by lbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void cmdi(t_parse *parse, t_exp *atc)
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
	lala = parse->cmd;
//	if (!parse->cmd)
//		return (parse);
	while (parse->cmd[i])
	{
		if (!ft_cmpchar(parse->cmd[i], '\"'))
			r++;
		if (!ft_cmpchar(parse->cmd[i], '\'') && r == 0)
			c++;
		if (!ft_cmpchar(parse->cmd[i], '$'))
		{
			while (parse->cmd[i])
			{
				if (!ft_cmpchar(parse->cmd[i], '\"'))
					r++;
				if (!ft_cmpchar(parse->cmd[i], '\'') && r == 0)
					c++;
				i++;
				g++;
			}
		}
		i++;
	}
	h = i;
	i = 0;
	printf("CMD2 ===== %s\n", parse->cmd);
	if (g == 0)
	{
		if (c == 0)
		{
			doll = NULL;
			doll = malloc(sizeof(char) * (h - r + 1));
			while (i < h)
			{
				if (!ft_cmpchar(parse->cmd[i], '\"'))
				{
					i++;
					continue ;
				}
				doll[d] = parse->cmd[i];
				i++;
				d++;
			}
			doll[d] = '\0';
			free (parse->cmd);
			parse->cmd = NULL;
			parse->cmd = doll;
		}
		else
		{
			doll = malloc(sizeof(char) * (h - c + 1));
			while (parse->cmd[i])
			{
				if (!ft_cmpchar(parse->cmd[i], '\''))
				{
					i++;
					continue ;
				}
				doll[d] = parse->cmd[i];
				i++;
				d++;
			}
			doll[d] = '\0';
			parse->cmd = doll;
		}
	}
	else
	{
		while (parse->cmd[i])
		{
			if (!ft_cmpchar(parse->cmd[i], '\''))
				d++;
			if (!ft_cmpchar(parse->cmd[i], '$') && (ft_cmpchar(parse->cmd[i + 1], '?') || d != 0))
			{
				i++;
				if (!parse->cmd[i])
					parse->cmd = parse->cmd;
				//				return (parse);
				else if (ft_isdigit(parse->cmd[i]) || (d != 0 && c != 0))
				{
					doll = dollar(parse->cmd, c);
					printf("DOLL ==== %s\n", doll);
					parse->cmd = doll;
					printf("PIIPIP ====== %s\n\n", parse->cmd);
					//				return (parse);
				}
				else
				{
					if (r != 0)
					{
						d = 0;
						doll = malloc(sizeof(char) * (g - 1));
						while (parse->cmd[i])
						{
							if (!ft_cmpchar(parse->cmd[i], '\"') && c == 0)
								break;
							if (!ft_cmpchar(parse->cmd[i], '\'') && c == 0)
								break;
							doll[d] = parse->cmd[i];
							i++;
							d++;
						}
						g = i;
					}
					else
					{
						d = 0;
						doll = malloc(sizeof(char) * (g));
						printf("DOLL2 ===== %s\n", doll);
						while (parse->cmd[i])
						{
							if (!ft_cmpchar(parse->cmd[i], '\''))
								break;
							doll[d] = parse->cmd[i];
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
					else
					{
						d = 0;
						while (doll[d])
							d++;
					}
					lala = malloc(sizeof(char) * (h - g + d));
					d = 0;
					h = 0;
					//				printf("DOLL ===== %s\n", doll);
					while (parse->cmd[i])
					{
						if (!ft_cmpchar(parse->cmd[i], '\"') && c == 0)
							i++;
						if (!ft_cmpchar(parse->cmd[i], '\'') && c != 0)
							i++;
						if (!ft_cmpchar(parse->cmd[i], '$'))
						{
							if (doll != NULL)
							{
								while (ft_isprint(doll[h]) == 1)
								{
									//								if (!ft_cmpchar(parse->cmd[i], '\"') && c == 0)
									//									i++;
									lala[d] = doll[h];
									d++;
									h++;
								}
							}
							//						free (doll);
							while (i < g)
								i++;
						}
						if (!ft_cmpchar(parse->cmd[i], '\"') && c == 0)
							i++;
						if (!ft_cmpchar(parse->cmd[i], '\'') && c != 0)
							i++;
						lala[d] = parse->cmd[i];
						i++;
						d++;
					}
					parse->cmd = lala;
					printf("PAAPAP ====== %s\n\n", parse->cmd);
					//				return (parse);
				}
			}
			i++;
		}
	}
}
