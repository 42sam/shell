/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built-ins.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssachet <ssachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/24 03:12:28 by ssachet           #+#    #+#             */
/*   Updated: 2015/03/17 05:05:44 by ssachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myshell.h"

int		special_cd(int len, char *arg, t_list *env)
{
	if (len >= 3)
	{
		ft_printf("cd: Too many arguments.\n");
		return (-1);
	}
	else if ((len == 1) || ((len == 2) && (ft_strequ("~", arg))))
	{
		if (chdir(get_value("HOME", env)) == -1)
			ft_printf("cd: Can't change to home directory.\n");
		return (-1);
	}
	else if (((len == 2) && (ft_strequ("-", arg))))
	{
		if (chdir(get_value("OLDPWD", env)) == -1)
			ft_printf("cd: Can't change to previous directory.\n");
		return (-1);
	}
	else
		return (0);
}

int		cd(char **args, t_list *env)
{
	char	buf[PATH_MAX];
	int		len;
	char	*arg;

	arg = args[1];
	len = tablen(args);
	getcwd(buf, PATH_MAX);
	if (!special_cd(len, arg, env))
	{
		if (!file_exists(arg))
			ft_printf("cd:cd:13: No such file or directory: %s\n", arg);
		else if (!is_directory(arg))
			ft_printf("cd:cd:13: Not a directory: %s\n", arg);
		else if (chdir(arg) == -1)
		{
			ft_printf("cd:cd:13: Permission denied: %s\n", arg);
			return (-1);
		}
	}
	getcwd(buf, PATH_MAX);
	set_value("OLDPWD", get_value("PWD", env), 1, env);
	set_value("PWD", buf, 1, env);
	return (0);
}

int		pwd(char **args, t_list *env)
{
	char	*pwd;
	int		len;

	len = tablen(args);
	if (len == 1)
	{
		if (NULL == (pwd = get_value("PWD", env)))
			return (1);
		ft_putendl(pwd);
	}
	else
		ft_printf("%s: too many arguments\n", args[0]);
	return (0);
}

int		echo(char **args, t_list *env, char *line)
{
	char *var;

	if (!args[1])
	{
		ft_putendl("");
		return (0);
	}
	var = NULL;
	if (*args[1] && (*args[1] != '$'))
	{
		ft_putendl(ft_strchr(line, ' ') + 1);
		return (0);
	}
	if (NULL == (var = get_value(ft_strchr(args[1], '$') + 1, env)))
	{
		E("");
		return (1);
	}
	ft_putendl(var);
	return (0);
}
