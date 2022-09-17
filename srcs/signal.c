/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msebbane <msebbane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 22:23:46 by lbally            #+#    #+#             */
/*   Updated: 2022/09/07 12:55:57 by msebbane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	ft_signal(int signum)
{
	if (signum == SIGINT)
	{
		printf("\e[2K");
		rl_on_new_line();
		rl_redisplay();
		printf("\n");
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}	
	if (signum == SIGQUIT)
	{
		printf("\e[2K");
		rl_on_new_line();
		rl_redisplay();
	}
}

void	signal_exit(void)
{
	printf("\e[2K");
	rl_on_new_line();
	rl_redisplay();
	printf("exit");
	printf("\n");
	exit(EXIT_SUCCESS);
}

void	signals(void)
{
	//if (!ft_strcmp(str, "cat") && signal(SIGQUIT, ft_signal))
		//printf("^Quit: 3");
	signal(SIGINT, ft_signal);
	signal(SIGQUIT, ft_signal);
}
