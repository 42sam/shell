/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssachet <ssachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 10:44:08 by ssachet           #+#    #+#             */
/*   Updated: 2015/03/16 00:20:13 by ssachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termlib.h"

void	switch_to_canonical(void)
{
	tcgetattr(0, &oldterm);
	newterm.c_lflag &= ~(ICANON | ECHO);
	newterm.c_oflag &= ~(OPOST);
	newterm.c_cc[VTIME] = 0;
	newterm.c_cc[VMIN] = 1;
	tcsetattr(0, TCSANOW, &newterm);
}

void	init_sequential_output(t_attr *g_attr)
{
	tputs(g_attr->init_sequential_output, 1, (void*)ft_put_tty);
}

int		get_term_entry(void)
{
	static char	term_buffer[2048];
	char		*termtype;
	int			success;

	if ((termtype = getenv ("TERM")) == NULL)
	{
		C('\n');
		S("Error : TERM not set.\n");
		return (-1);
	}
	success = tgetent (term_buffer, termtype);
	if (success < 0)
	{
		C('\n');
		S("Error: TERM not found.\n");
		return (-1);
	}
	if (success == 0)
	{
		C('\n');
		ft_printf("Terminal type `%s' is not defined.\n", termtype);
		return (-1);
	}
	return (0);
}

t_attr	*term_init(void)
{
	t_attr *attr;

	if ((get_term_entry()) == -1)
		return (NULL);
	if ((attr = load_attributes(g_attr)) == NULL)
		return (NULL);
	switch_to_canonical();
	return (attr);
}

void	term_reset(t_attr *g_attr, int g_pid)
{
	tcsetattr(0, TCSANOW, &oldterm);
	reinit_cursor(g_attr);
	if (g_pid)
		kill(g_pid, SIGKILL);
}
