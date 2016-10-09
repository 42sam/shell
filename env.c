/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssachet <ssachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/10 19:12:47 by ssachet           #+#    #+#             */
/*   Updated: 2015/03/17 05:05:44 by ssachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myshell.h"

t_list		*build_env_from_pwd(void)
{
	t_list	*env;
	char	buf[PATH_MAX];
	int		equ_sign;

	if ((getcwd(buf, PATH_MAX)) == NULL)
		return (NULL);
	equ_sign = CI(buf, '=');
	env = new_dict(makestr("PWD"),
			ft_strsub(buf, equ_sign + 1, LEN(buf) - equ_sign), NULL);
	return (env);
}

int			env_settings(int *i, t_list **one_time_env, char **args,
		t_list **env)
{
	int	from_scratch;

	from_scratch = 0;
	if (!args[1])
	{
		print_env(*env);
		return (-1);
	}
	else if (ft_strequ(args[1], "-i") && (!args[2]))
		return (-1);
	*one_time_env = *env;
	if (ft_strequ(args[1], "-i") && (args[2]))
	{
		*one_time_env = NULL;
		from_scratch = 1;
		*i = 2;
	}
	else
		*i = 1;
	return (from_scratch);
}

int			set_name_value(char **name, char **value, char **args, int *i)
{
	int		equ_sign;

	equ_sign = CI(args[*i], '=');
	if ((*name = ft_strsub(args[*i], 0, CI(args[*i], '='))) == NULL)
		*name = makestr("");
	*value = ft_strsub(args[*i], equ_sign + 1, LEN(args[*i]) - equ_sign);
	return (0);
}

int			set_tmp_env(char **args, t_envs **e, int *from_scratch,
																		int *i)
{
	char	*name;
	char	*value;
	t_list	*node;

	while (args[*i] && (ft_strchr(args[*i], '=')))
	{
		set_name_value(&name, &value, args, i);
		if ((*i == 1) || ((*i == 2) && *from_scratch))
		{
			(*e)->tmp_env = new_dict(name, NULL, NULL);
			node = (*e)->tmp_env;
		}
		else
		{
			node->next = new_dict(name, NULL, NULL);
			node = node->next;
		}
		if (*from_scratch && (*i == 2))
			(*e)->one_time_env = new_dict(name, value, NULL);
		else
			set_value(name, value, 1, (*e)->one_time_env);
		(*i)++;
	}
	return (*i);
}

int			myenv(char **args, t_envs **e)
{
	int		i;
	int		from_scratch;

	if ((from_scratch = env_settings(&i, &(*e)->one_time_env, args,
														&(*e)->env)) == -1)
		return (0);
	i = set_tmp_env(args, e, &from_scratch, &i);
	if (args[i])
	{
		if (launch_exec(&args[i], &(*e)->one_time_env) == -1)
			ft_printf("env: %s: No such file or directory\n", args[i]);
	}
	else
		print_env((*e)->one_time_env);
	return (0);
}
