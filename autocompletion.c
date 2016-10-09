/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autocompletion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssachet <ssachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/10 22:28:03 by ssachet           #+#    #+#             */
/*   Updated: 2015/03/20 17:19:57 by ssachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myshell.h"

char	*files_loop(char *directory_part, char *piece_of_name)
{
	DIR				*dir;
	struct dirent	*file;
	char			*completion;

	completion = NULL;
	if ((dir = opendir(directory_part)) == NULL)
		return (completion);
	while ((file = readdir(dir)) != NULL)
	{
		if (ft_strnequ(file->d_name, piece_of_name, LEN(piece_of_name)))
		{
			completion = ft_strsub(file->d_name, LEN(piece_of_name),
					LEN(file->d_name) - LEN(piece_of_name));
			closedir(dir);
			return (completion);
		}
	}
	closedir(dir);
	return (NULL);
}

char	*get_complete_filename(char *to_complete)
{
	char			*completion;
	char			*piece_of_name;
	char			*directory_part;

	if (ft_strchr(to_complete, '/'))
	{
		piece_of_name = ft_strsub(to_complete, has_char_rev(to_complete, '/')
				+ 1, LEN(ft_strchr_rev(to_complete, '/') + 1));
		directory_part = ft_strsub(to_complete, 0,
				has_char_rev(to_complete, '/') + 1);
	}
	else
	{
		piece_of_name = to_complete;
		directory_part = makestr(".");
	}
	completion = files_loop(directory_part, piece_of_name);
	if (!completion)
		return (NULL);
	else
		return (completion);
}

char	*get_completion(char *to_complete)
{
	if (!to_complete || ft_strequ(to_complete, ""))
		return (NULL);
	if (is_directory(to_complete))
	{
		if (has_char_at_end(to_complete, '/') == 0)
			return (get_first_file(to_complete));
		else
			return ("/");
	}
	else
		return (get_complete_filename(to_complete));
	return (NULL);
}

char	*get_string_to_complete(char *rush, int index)
{
	char	*ssub;
	char	*start;
	char	*to_complete;
	int		end_of_str;

	if (index == 0)
		return (NULL);
	ssub = ft_strsub(rush, 0, index);
	if ((start = (ft_strchr_rev(ssub, ' '))) == NULL)
		return (NULL);
	start = start + 1;
	if (((end_of_str = has_char(start, ' '))) == -1)
		to_complete = start;
	else
		to_complete = ft_strsub(start, 0, end_of_str);
	return (to_complete);
}

char	*autocompletion(char *rush, t_line *line)
{
	char	*to_complete;
	char	*completion;

	to_complete = get_string_to_complete(rush, line->index);
	if ((completion = get_completion(to_complete)) == NULL)
		return (rush);
	if (g_win->width > line->index + line->prlen + (int)LEN(completion))
	{
		rush = strstr_insert(rush, completion, line->index);
		line->char_nb += ft_strlen(completion);
		line->index += ft_strlen(completion);
	}
	return (rush);
}
