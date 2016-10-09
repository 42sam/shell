/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assistant.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssachet <ssachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/01 16:14:35 by ssachet           #+#    #+#             */
/*   Updated: 2015/03/31 19:31:26 by ssachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myshell.h"

int		is_quit_cmd(char *args)
{
	if (ft_strequ(args, "quit")
			|| (ft_strequ(args, "exit"))
			|| (ft_strequ(args, "q")))
		return (1);
	return (0);
}

int		is_openable(char *path)
{
	int		fd;

	if ((fd = open(path, O_RDONLY)) > 0)
	{
		close(fd);
		return (1);
	}
	return (0);
}

char	*get_path(char *path, char *args)
{
	char	**paths;
	char	*right_path;
	int		i;

	if (ft_strnequ(args, "./", 2))
	{
		JOIN(&right_path, "%s/%s", get_current_dir(),
											ft_strsub(args, 2, LEN(args) - 2));
		if (is_openable(right_path))
			return (right_path);
	}
	else if (((*args == '/') || (*args == '.')) && (is_openable(args)))
		return (args);
	if (!path || (ft_strnequ(args, "./", 2)))
		return (NULL);
	i = 0;
	paths = ft_strsplit(path, ':');
	while (paths[i])
	{
		JOIN(&right_path, "%s/%s", paths[i++], args);
		if (is_openable(right_path))
			return (right_path);
	}
	return (NULL);
}
