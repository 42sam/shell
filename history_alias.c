/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history_alias.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssachet <ssachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 08:50:38 by ssachet           #+#    #+#             */
/*   Updated: 2015/03/11 21:36:11 by ssachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myshell.h"

void	set_history(char **line)
{
	t_list		*node;
	static int	command_nb;

	if (!is_space_str(*line))
	{
		if (!g_history)
			g_history = new_dict(ft_itoa(command_nb), *line, NULL);
		else
		{
			node = g_history;
			while (node->next)
				node = node->next;
			node->next = new_dict(ft_itoa(command_nb), *line, NULL);
		}
		command_nb++;
	}
}
