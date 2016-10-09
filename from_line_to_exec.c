/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   from_line_to_exec.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssachet <ssachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/10 22:47:39 by ssachet           #+#    #+#             */
/*   Updated: 2015/03/31 19:22:55 by ssachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myshell.h"

int			first_set(char **args, t_envs **e, char *line)
{
	if (is_quit_cmd(args[0]))
	{
		ft_printf("exit\n");
		exit(0);
	}
	else if (ft_strequ(args[0], "env"))
		myenv(args, e);
	else if (ft_strequ(args[0], "pwd"))
	{
		if (pwd(args, (*e)->env) != 0)
		{
			ft_putendl("PWD: Missing");
			return (1);
		}
	}
	else if (ft_strequ(args[0], "cd"))
		cd(args, (*e)->env);
	else if (ft_strequ(args[0], "quel"))
		ft_putstr("\033[35m42\033[0m\n");
	else if (ft_strequ(args[0], "echo"))
		echo(args, (*e)->env, line);
	else
		return (0);
	return (1);
}

int			second_set(char **args, t_envs **e)
{
	if (ft_strequ(args[0], "unsetenv"))
	{
		if (!args[1])
			ft_printf("unsetenv: Too few arguments.\n");
		else
			tab_del_i(args, &(*e)->env);
	}
	else if (ft_strequ(args[0], "setenv"))
		mysetenv(args, 1, &(*e)->env);
	else if (ft_strequ(args[0], "builtins"))
		print_builtins();
	else if (ft_strequ(args[0], "history"))
		print_history(args);
	else
		return (0);
	return (1);
}

int			launch_cmd(char **args, t_envs **e, char *line)
{
	if (!first_set(args, e, line))
		if (!second_set(args, e))
			return (0);
	return (1);
}

int			loop_throo_commands(char **commands, t_envs **e, char *line)
{
	int		i;
	char	**cmd;

	i = 0;
	while (commands[i])
	{
		cmd = ft_strsplit(commands[i], ' ');
		if (!launch_cmd(cmd, e, line))
			launch_exec(cmd, &(*e)->env);
		if ((*e)->tmp_env)
		{
			lst_del_node((*e)->tmp_env, &((*e)->env));
		}
		i++;
	}
	return (0);
}

void		line_to_commands(char **rush, char **line, char ***commands)
{
	*line = makestr(*rush);
	if ((*line = tab_to_space(*line)) == NULL)
	{
		*line = makestr("\n");
		ft_putchar('\n');
	}
	*line = trim_all(*line);
	*commands = ft_strsplit(*line, ';');
}
