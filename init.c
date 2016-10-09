/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssachet <ssachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/24 16:43:48 by ssachet           #+#    #+#             */
/*   Updated: 2015/03/31 19:21:55 by ssachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myshell.h"

int		init_env(t_envs *env)
{
	char *cur_dir;

	cur_dir = get_current_dir();
	env->tmp_env = NULL;
	if (!env)
	{
		if ((env->env = build_env_from_pwd()) == NULL)
			return (-1);
	}
	else
	{
		if (cur_dir)
			set_value("PWD", cur_dir, 1, env->env);
	}
	return (0);
}

void	array_to_lst(char **envp, t_list **head)
{
	int		i;
	t_list	*env;
	t_list	**headref;
	int		equ_sign;

	i = -1;
	*head = NULL;
	headref = head;
	if (*envp == NULL)
		*head = build_env_from_pwd();
	while (envp[++i])
	{
		equ_sign = CI(envp[i], '=');
		env = new_dict(NULL, NULL, NULL);
		if ((env->name = ft_strsub(envp[i], 0, equ_sign)) == NULL)
			env->name = makestr("");
		env->value = ft_strsub(envp[i], equ_sign + 1, LEN(envp[i]) - equ_sign);
		push(headref, env);
		headref = &((*headref)->next);
	}
}

void	null_void(char **commands, int argc, char **argv, char **rush)
{
	(void)commands;
	(void)rush;
	(void)argc;
	(void)argv;
	commands = NULL;
	g_history = NULL;
	*rush = NULL;
}

int		init(char **env_array, t_envs *envsp)
{
	init_signals();
	array_to_lst(env_array, &(envsp->env));
	if ((init_env(envsp)) == -1)
		return (-1);
	if (get_value("SHLVL", envsp->env))
		set_value("SHLVL", ft_itoa(ft_atoi(get_value("SHLVL", envsp->env)) + 1)
				, 1, envsp->env);
	set_value("SHELL", "./ft_minishell1", 1, envsp->env);
	g_win = window_management();
	return (0);
}

void	key_process_init(t_line *line, char **buf, char **rush, t_attr *atty)
{
	line->index = 0;
	line->char_nb = 0;
	*buf = (char *)malloc(CLINEMAX);
	ft_memset(*buf, '\0', CLINEMAX);
	*rush = makestr("");
	S(atty->cr);
	S(atty->savecursor);
}
