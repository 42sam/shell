/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myshell.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssachet <ssachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/22 21:36:51 by ssachet           #+#    #+#             */
/*   Updated: 2015/03/31 19:22:12 by ssachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myshell.h"

int		main(int argc, char **argv, char **env_ar)
{
	char	**commands;
	char	*rush;
	char	*line;
	int		prlen;
	t_envs	*e;

	e = (t_envs *)malloc(sizeof(t_envs));
	commands = NULL;
	null_void(commands, argc, argv, &rush);
	init(env_ar, e);
	while (42)
	{
		if ((init_env(e)) == -1)
			return (-1);
		prlen = print_prompt(e->env);
		if ((rush = get_user_input(rush, prlen)) == NULL)
			return (0);
		line_to_commands(&rush, &line, &commands);
		set_history(&rush);
		loop_throo_commands(commands, &e, line);
	}
	return (0);
	free(e);
	free(rush);
	free(line);
}
