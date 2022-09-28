/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flagi.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbally <lbally@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/14 18:01:52 by lbally            #+#    #+#             */
/*   Updated: 2022/09/28 22:30:35by lbally           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

/*char	*flagi5(t_parse *parse, int c)
{
	while (parse->flag[i])
	{
		if (!ft_cmpchar(parse->flag[i], '\"') && c == 0)
			i++;
		if (!ft_cmpchar(parse->flag[i], '\'') && c != 0)
			i++;
		if (!ft_cmpchar(parse->flag[i], '$'))
		{
			if (str != NULL)
			{
				while (ft_isprint(str[h]) == 1)
				{
					lala[d] = str[h];
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
	return (lala);
}*/

void	flagi3(t_parse *parse, int r, int h)
{
	char	*str;
	int		i;
	int		d;

	i = 0;
	d = 0;
	printf("lala\n");
	str = NULL;
	str = malloc(sizeof(char) * (h - r + 1));
	while (i < h)
	{
		if (!ft_cmpchar(parse->flag[i], '\"'))
		{
			i++;
			continue ;
		}
		str[d] = parse->flag[i];
		d++;
		i++;
	}
	str[d] = '\0';
	parse->flag = str;
}

void	flagi4(t_parse *parse, int c, int h)
{
	char	*str;
	int		i;
	int		d;

	i = 0;
	d = 0;
	str = NULL;
	str = malloc(sizeof(char) * (h - c + 1));
	while (parse->flag[i])
	{
		if (!ft_cmpchar(parse->flag[i], '\''))
		{
			i++;
			continue ;
		}
		str[d] = parse->flag[i];
		i++;
		d++;
	}
	str[d] = '\0';
	printf("STR === %s\n", str);
	parse->flag = str;
}

void	flagi2(t_parse *parse, int r, int c, int h)
{
	int		i;
	int		d;

	i = 0;
	d = 0;
	if (c == 0)
		flagi3(parse, r, h);
	else
		flagi4(parse, c, h);
}

void	flagi(t_parse *parse, t_exp *atc)
{
	char	*str;
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
	lala = parse->flag;
	while (parse->flag[i])
	{
		if (!ft_cmpchar(parse->flag[i], '\"'))
			r++;
		if (!ft_cmpchar(parse->flag[i], '\'') && r == 0)
			c++;
		if (!ft_cmpchar(parse->flag[i], '$'))
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
	if (g == 0)
		flagi2(parse, r, c, h);
	else
	{
		while (parse->flag[i])
		{
			if (!ft_cmpchar(parse->flag[i], '\''))
				d++;
			if (!ft_cmpchar(parse->flag[i], '$') && (ft_cmpchar(parse->flag[i + 1], '?') || d != 0))
			{
				i++;
				if (!parse->flag[i])
					parse->flag = parse->flag;
				else if (ft_isdigit(parse->flag[i]) || (d != 0 && c != 0))
				{
					str = dollar(parse->flag, c);
					parse->flag = str;
				}
				else
				{
					if (r != 0)
					{
						d = 0;
						str = malloc(sizeof(char) * (g - 1));
						while (parse->flag[i])
						{
							if (!ft_cmpchar(parse->flag[i], '\"') && c == 0)
								break ;
							if (!ft_cmpchar(parse->flag[i], '\'') && c == 0)
								break ;
							str[d] = parse->flag[i];
							i++;
							d++;
						}
						g = i;
					}
					else
					{
						d = 0;
						str = malloc(sizeof(char) * (g));
						while (parse->flag[i])
						{
							if (!ft_cmpchar(parse->flag[i], '\''))
								break ;
							str[d] = parse->flag[i];
							i++;
							d++;
						}
						str[d] = '\0';
						g = i;
					}
					d = 0;
					i = 0;
					while (atc)
					{
						if (!ft_strcmp(str, atc->name))
						{
							str = atc->mean;
							d++;
						}
						atc = atc->next;
					}
					if (d == 0)
						str = NULL;
					else
					{
						d = 0;
						while (str[d])
							d++;
					}
					lala = malloc(sizeof(char) * (h - g + d));
					d = 0;//
					h = 0;
					while (parse->flag[i])
					{
						if (!ft_cmpchar(parse->flag[i], '\"') && c == 0)
							i++;
						if (!ft_cmpchar(parse->flag[i], '\'') && c != 0)
							i++;
						if (!ft_cmpchar(parse->flag[i], '$'))
						{
							if (str != NULL)
							{
								while (ft_isprint(str[h]) == 1)
								{
									lala[d] = str[h];
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
					parse->flag = lala;//
				}
			}
			i++;
		}
	}
}
