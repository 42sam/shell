/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_command_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssachet <ssachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/10 22:30:33 by ssachet           #+#    #+#             */
/*   Updated: 2015/03/17 05:05:44 by ssachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myshell.h"

void		reinit_cursor_position(int index, t_attr *atty, int prlen)
{
	while (index-- > -(prlen))
		go_right(atty);
}

static void	go_to_end_of_prompt(t_attr *atty, int prlen)
{
	int	i;

	i = 0;
	while (i++ < prlen)
		go_right(atty);
}

int			print_buffer(t_attr *atty, int prlen, int index, char *rush)
{
	S(atty->cr);
	go_to_end_of_prompt(atty, prlen);
	t_put(rush);
	S(atty->clear_line);
	S(atty->resetcursor);
	reinit_cursor_position(index, atty, prlen);
	return (0);
}
