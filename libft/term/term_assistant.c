/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term_assistant.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssachet <ssachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 10:43:10 by ssachet           #+#    #+#             */
/*   Updated: 2015/04/03 15:45:35 by ssachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "termlib.h"

char	*read_term(char *buf)
{
	int		rd;

	ft_bzero(buf, 10);
	rd = read(0, buf, 12);
	buf[rd] = '\0';
	return (buf);
}

t_winsz	*window_management(void)
{
	struct winsize	wsize;
	t_winsz			*win;

	win = (t_winsz *)malloc(sizeof(t_winsz));
	ioctl(0, TIOCGWINSZ, &wsize);
	win->width = wsize.ws_col;
	win->height = wsize.ws_row;
	return (win);
}

void	init_random_cursor_motion(t_attr *g_attr)
{
	tputs(g_attr->init_random_cursor_motion, 1, (void*)ft_put_tty);
}
