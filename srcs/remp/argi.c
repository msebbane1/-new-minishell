/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbally <lbally@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 18:02:42 by lbally            #+#    #+#             */
/*   Updated: 2022/09/28 22:03:34 by lbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

void	argi(t_parse *parse, t_exp *atc, char *arg, int w)
{
	char	*dolli;
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
		if (!ft_cmpchar(arg[i], '\"'))
			r++;
		if (!ft_cmpchar(arg[i], '\'') && r == 0)
			c++;
		if (!ft_cmpchar(arg[i], '$'))
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
	if (g == 0)
	{
		if (c == 0)
		{
			dolli = NULL;
			dolli = malloc(sizeof(char) * (h - r + 1));
			while (arg[i])
			{
				if (!ft_cmpchar(arg[i], '\"'))
				{
					i++;
					continue ;
				}
				dolli[d] = arg[i];
				d++;
				i++;
			}
			dolli[d] = '\0';
			parse->arg[w] = dolli;
		}
		else
		{
			dolli = malloc(sizeof(char) * (h - c + 1));
			while (arg[i])
			{
				if (!ft_cmpchar(arg[i], '\''))
				{
					i++;
					continue ;
				}
				dolli[d] = arg[i];
				i++;
				d++;
			}
			dolli[d] = '\0';
			parse->arg[w] = dolli;
		}
	}
	else
	{
		while (arg[i])
		{
			if (!ft_cmpchar(arg[i], '\''))
				d++;
			if (!ft_cmpchar(arg[i], '$') || d != 0)
			{
				i++;
				if (!ft_cmpchar(arg[i], '?'))
					parse->arg[w] = ft_itoa(g_global.status);
				else if (!arg[i])
					parse->arg[w] = arg;
				else if (ft_isdigit(arg[i]) || (d != 0 && c != 0))
				{
					dolli = dollar(arg, c);
					parse->arg[w] = dolli;
				}
				else
				{
					if (r == 0)
					{
						d = 0;
						dolli = ft_calloc(g, sizeof(char));
						while (arg[i])
						{
							if (!ft_cmpchar(arg[i], '\''))
								break ;
							dolli[d] = arg[i];
							i++;
							d++;
						}
						dolli[d] = '\0';
					}
					else
					{
						d = 0;
						dolli = malloc(sizeof(char) * (g - 1));
						while (arg[i])
						{
							if (!ft_cmpchar(arg[i], '\"') && c == 0)
								break ;
							if (!ft_cmpchar(arg[i], '\'') && c == 0)
								break ;
							dolli[d] = arg[i];
							i++;
							d++;
						}
					}
					g = i;
					d = 0;
					i = 0;
					while (atc)
					{
						if (!ft_strcmp(dolli, atc->name))
						{
							dolli = atc->mean;
							d++;
						}
						atc = atc->next;
					}
					if (d == 0)
						dolli = NULL;
					else
					{
						d = 0;
						while (dolli[d])
							d++;
					}
					lala = malloc(sizeof(char) * (h - g + d));
					d = 0;
					h = 0;
					while (arg[i])
					{
						if (!ft_cmpchar(arg[i], '\"') && c == 0)
							i++;
						if (!ft_cmpchar(arg[i], '\'') && c != 0)
							i++;
						if (!ft_cmpchar(arg[i], '$'))
						{
							if (dolli != NULL)
							{
								while (ft_isprint(dolli[h]) == 1)
								{
									lala[d] = dolli[h];
									d++;
									h++;
								}
							}
							while (i < g)
								i++;
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
				}
			}
			i++;
		}
	}
}
