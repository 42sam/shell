/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssachet <ssachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/25 19:45:29 by ssachet           #+#    #+#             */
/*   Updated: 2015/03/31 19:30:49 by ssachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myshell.h"

static void	move_key(char *buf, t_line *line, t_attr *atty)
{
	(void)atty;
	if (ISRIGHT(buf))
		if ((line->index) < (line->char_nb))
			(line->index)++;
	if (ISLEFT(buf))
		if (line->index > 0)
			(line->index)--;
	if (ISHOME(buf))
		while (line->index > 0)
			(line->index)--;
	if (ISEND(buf))
		while (line->index < (line->char_nb))
			(line->index)++;
}

static char	*key_process(char *rush, char buf[], t_attr *atty, t_line *line)
{
	if (ISCTRL_CHAR(buf))
	{
		if (ISTAB(buf))
			rush = autocompletion(rush, line);
	}
	else if (ISPRINTABLE(buf))
	{
		rush = strstr_insert(rush, char_to_str(buf[0]), line->index);
		(line->char_nb)++;
		(line->index)++;
	}
	else if (ISARROW(buf))
		move_key(buf, line, atty);
	else if (ISDEL(buf))
	{
		if (line->index > 0)
		{
			rush = strstr_del(rush, 1, line->index);
			(line->index)--;
			(line->char_nb)--;
		}
	}
	return (rush);
}

char		*get_user_input(char *rush, int prlen)
{
	int		rd;
	char	*buf;
	t_attr	*atty;
	t_line	*line;

	if ((atty = term_init()) == NULL)
		return (NULL);
	line = (t_line *)malloc(sizeof(t_line));
	line->prlen = prlen;
	key_process_init(line, &buf, &rush, atty);
	reinit_cursor_position(line->index, atty, prlen);
	while (!ISRETURN(buf))
	{
		ft_memset(buf, '\0', CLINEMAX);
		rd = read(0, buf, BUFSIZE);
		buf[rd] = '\0';
		if (!ISRETURN(buf) && (g_win->width > (line->index + prlen + 1)))
		{
			rush = key_process(rush, buf, atty, line);
			print_buffer(atty, prlen, line->index, rush);
		}
	}
	new_line(atty);
	term_reset(atty, g_pid);
	return (rush);
}
