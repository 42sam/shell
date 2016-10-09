/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   myshell.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssachet <ssachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/22 22:09:20 by ssachet           #+#    #+#             */
/*   Updated: 2015/03/31 19:23:26 by ssachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MYSHELL_H
# define MYSHELL_H
# include "libft/libft.h"
# include "signal.h"
# include <unistd.h>
# include <sys/wait.h>

# define CLINEMAX 42000
# define BUFSIZE 42

t_list			*g_history;
t_winsz			*g_win;

struct termios	oldterm;
struct termios	newterm;

typedef	struct	s_line
{
	int			char_nb;
	int			index;
	int			prlen;
}				t_line;

typedef	struct	s_envs
{
	t_list		*env;
	t_list		*tmp_env;
	t_list		*one_time_env;
}				t_envs;

char			*autocompletion(char *rush, t_line *line);
char			*get_first_file(char *to_complete);
char			*get_path(char *path, char *args);
char			*get_pwd(char **envp);
char			*get_string_to_complete(char *rush, int index);
char			*output_process(char *rush, int prlen);
char			*strstr_del(char *s1, int cnb, int index);
char			*strstr_insert(char *str, char *to_insert, int index);
int				cd(char **args, t_list *env);
int				echo(char **args, t_list *env, char *line);
int				is_quit_cmd(char *cmd);
int				launch(char **cmd, t_list **env, char *line);
int				launch_exec(char **args, t_list **env_list);
void			line_to_commands(char **rush, char **line, char ***commands);
int				launch_command(char **cmd, t_list **env, char *line);
int				loop_throo_commands(char **commands, t_envs **e, char *line);
int				myenv(char **args, t_envs **e);
int				mysetenv(char **args, int overwrite, t_list	**env);
int				print_env(t_list *env);
int				print_prompt(t_list *env);
int				pwd(char **args, t_list *env);
t_list			*build_env_from_pwd(void);
void			array_to_lst(char **envp, t_list **head);
void			call_execve(char *path, char **args, char **env);
void			handle_signal(int signum);
int				init_env(t_envs *env);
int				init(char **env_array, t_envs *envsp);
void			null_void(char **commands, int argc, char **argv, char **rush);
void			print_builtins();
void			print_history(char **args);
void			set_history(char **line);
void			key_process_init(t_line *line, char **buf, char **rush,
																t_attr *atty);
int				print_buffer(t_attr *atty, int prlen, int index, char *rush);
void			reinit_cursor_position(int index, t_attr *atty, int prlen);
char			*get_user_input(char *rush, int prlen);
void			init_child_signals(void);
void			init_child_signals2(void);
#endif
