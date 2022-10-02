/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vl-hotel <vl-hotel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 22:23:46 by lbally            #+#    #+#             */
/*   Updated: 2022/10/01 23:39:55 by vl-hotel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	echo_control_seq(int c)
{
	struct termios	conf;

	ioctl(ttyslot(), TIOCGETA, &conf);
	if (c == 1)
		conf.c_lflag |= ECHOCTL;
	else if (c == 0)
		conf.c_lflag &= ~(ECHOCTL);
	ioctl(ttyslot(), TIOCSETA, &conf);
}

void	ft_signal(int signum)
{
	(void)signum;
	if (g_global.here == 1)
	{
		printf("\r");
		write(1, "\n", 1);
		close(0);
	}
	else
	{
		printf("\r");
		printf("\n");
		if (rl_done)
			return ;
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
	g_global.status = 1;
}

void	ft_signalquit(int signum)
{
	(void)signum;
	if (rl_done)
	{
		printf("Quit: 3\n");
		g_global.status = 131;
		return ;
	}
	printf("\e[2K");
	rl_on_new_line();
	rl_redisplay();
	g_global.status = 0;
}

void	signal_exit(void)
{
	printf("\033[1A");
	printf("%s", rl_prompt);
	printf("exit\n");
	exit(EXIT_SUCCESS);
}

void	init_signals(void)
{
	signal(SIGINT, ft_signal);
	signal(SIGQUIT, ft_signalquit);
	echo_control_seq(0);
}
