/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssachet <ssachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/16 22:39:07 by ssachet           #+#    #+#             */
/*   Updated: 2015/03/17 05:05:45 by ssachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myshell.h"

static void		sig_1(int signum)
{
	if (signum == SIGWINCH)
		g_win = window_management();
	if (signum == SIGKILL)
	{
		tcsetattr(0, TCSANOW, &oldterm);
		ft_printf("[1] killed: 9\n");
		exit(0);
	}
	if (signum == SIGCONT)
		term_init();
}

static void		signal_handler(int signum)
{
	sig_1(signum);
}

void			init_signals2(void)
{
	signal(SIGPIPE, signal_handler);
	signal(SIGALRM, signal_handler);
	signal(SIGTERM, signal_handler);
	signal(SIGURG, signal_handler);
	signal(SIGTSTP, signal_handler);
	signal(SIGCONT, signal_handler);
	signal(SIGCHLD, signal_handler);
	signal(SIGTTIN, signal_handler);
	signal(SIGTTOU, signal_handler);
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	signal(SIGIO, signal_handler);
	signal(SIGXCPU, signal_handler);
	signal(SIGXFSZ, signal_handler);
	signal(SIGVTALRM, signal_handler);
	signal(SIGPROF, signal_handler);
	signal(SIGWINCH, signal_handler);
	//signal(SIGINFO, signal_handler); //not supported by linux
}

void			init_signals(void)
{
	init_child_signals();
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGSEGV, signal_handler);
	signal(SIGHUP, signal_handler);
	signal(SIGINT, signal_handler);
	signal(SIGQUIT, signal_handler);
	signal(SIGILL, signal_handler);
	signal(SIGTRAP, signal_handler);
	signal(SIGABRT, signal_handler);
	//signal(SIGEMT, signal_handler); //not supported by linux
	signal(SIGFPE, signal_handler);
	signal(SIGBUS, signal_handler);
	signal(SIGSEGV, signal_handler);
	signal(SIGSYS, signal_handler);
	init_signals2();
}
