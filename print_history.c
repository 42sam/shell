/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_history.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssachet <ssachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/10 22:15:13 by ssachet           #+#    #+#             */
/*   Updated: 2015/03/17 05:05:44 by ssachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myshell.h"

static int		set_width(t_list *node)
{
	int		width;
	int		digits;

	node = g_history;
	width = 1;
	while (node)
	{
		digits = ft_atoi(node->name);
		node = node->next;
	}
	node = g_history;
	while (digits /= 10)
		width++;
	return (width);
}

static void		print_history_index_grep(char **args, t_list *node, int width)
{
	if (args[2])
		ft_printf("fc: too many arguments\n");
	else if (is_digitstr(args[1]))
	{
		while (node && !ft_strequ(node->name, args[1]))
		{
			ft_printf("%*s   %s\n",
								width, node->name, node->value);
			node = node->next;
		}
		if (node)
			ft_printf("%*s   %s\n",
								width, node->name, node->value);
	}
	else
	{
		while (node)
		{
			if (ft_strstr(node->value, args[1]))
				ft_printf("%*s   %s\n",
								width, node->name, node->value);
			node = node->next;
		}
	}
}

void			print_history(char **args)
{
	t_list	*node;
	int		width;

	S(GRN);
	node = g_history;
	width = set_width(node);
	if (!args[1])
	{
		while (node)
		{
			ft_printf("%*s   %s\n",
								width, node->name, node->value);
			node = node->next;
		}
	}
	else
		print_history_index_grep(args, node, width);
	ft_putstr("\033[0m");
}
