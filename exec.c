/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssachet <ssachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/27 14:39:47 by ssachet           #+#    #+#             */
/*   Updated: 2015/03/16 23:54:12 by ssachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myshell.h"

void		child_process(char **args)
{
	if (access(*args, F_OK) == 0)
	{
		if (CI(*args, '/') != -1)
			ft_printf("%s: Permission denied.\n", *args);
		else
			ft_printf("%s: %s\n", *args, "Command not found");
	}
	else
		ft_printf("%s: %s\n", *args, "Command not found");
	exit(1);
}

int			launch_exec(char **args, t_list **env_list)
{
	int		status;
	char	*path;
	char	**env;
	int		pid;

	path = get_path(get_value("PATH", *env_list), *args);
	if ((pid = fork()) == 0)
	{
		env = lst_to_array(*env_list);
		if (!env)
			env = lst_to_array(build_env_from_pwd());
		if (execve(path, args, env) == -1)
			child_process(args);
	}
	else
		wait(&status);
	return (0);
}
