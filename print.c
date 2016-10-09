/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssachet <ssachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 06:08:59 by ssachet           #+#    #+#             */
/*   Updated: 2015/03/17 05:05:44 by ssachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myshell.h"

void	print_builtins(void)
{
	E("cd");
	E("pwd");
	E("history");
	E("env");
	E("echo");
	E("set");
	E("unset");
	E("builtins");
}

int		print_env(t_list *env)
{
	char *value;

	if (!env)
		return (-1);
	ft_printf("[blue]");
	while (env)
	{
		value = (ft_strequ(env->value, "")) ? makestr("") : env->value;
		ft_printf("%s=%s\n", env->name, value);
		env = env->next;
	}
	ft_printf("[eoc]");
	return (0);
}

int		print_prompt(t_list *env)
{
	char	*path_display;
	char	*login;
	char	*home;
	char	*pwd;
	int		pr_len;

	home = get_value("HOME", env);
	pwd = get_value("PWD", env);
	login = get_value("LOGNAME", env);
	if (ft_strstr(pwd, home))
		path_display = ft_strjoin("~",
						ft_strsub(pwd, LEN(home), LEN(pwd) - LEN(home)));
	else
		path_display = get_value("PWD", env);
	if (!path_display)
		path_display = makestr("");
	if (!login)
		login = makestr("");
	pr_len = ft_printf("[black]%s[red]:[yellow]%s[red]|[eoc]",
								login, path_display);
	return (pr_len);
}
