/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssachet <ssachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/10 20:51:34 by ssachet           #+#    #+#             */
/*   Updated: 2015/03/17 05:05:44 by ssachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myshell.h"

int			setenv_checks(char **args, t_list **env, char **value, char **name)
{
	if (!args[1])
	{
		print_env(*env);
		return (-1);
	}
	if (ft_strchr(args[1], '='))
	{
		ft_printf("setenv: Syntax Error.\n");
		return (-1);
	}
	if (ft_strequ(args[1], "''"))
		*name = makestr("");
	else
		*name = ft_strsub(args[1], 0, CI(args[1], '='));
	if (args[2] && (args[3]))
	{
		ft_printf("setenv: Too many arguments.\n");
		return (-1);
	}
	*value = (args[2]) ? makestr(args[2]) : makestr("");
	return (0);
}

int			mysetenv(char **args, int overwrite, t_list **env)
{
	int		var_found;
	char	*name;
	char	*value;
	t_list	*node;
	t_list	*before;

	if ((setenv_checks(args, env, &value, &name)) == -1)
		return (0);
	node = *env;
	var_found = 0;
	while (node)
	{
		if (ft_strequ(node->name, name))
			if (overwrite != 0)
			{
				if (!ft_strequ(value, ""))
					node->value = makestr(value);
				var_found = 1;
			}
		before = node;
		node = node->next;
	}
	if (!var_found)
		before->next = new_dict(name, value, NULL);
	return (0);
}
