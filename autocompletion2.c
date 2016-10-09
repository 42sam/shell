/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autocompletion2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssachet <ssachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/17 02:51:11 by ssachet           #+#    #+#             */
/*   Updated: 2015/03/17 05:05:44 by ssachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myshell.h"

char	*get_first_file(char *to_complete)
{
	char			*completion;
	DIR				*dir;
	struct dirent	*file;

	completion = NULL;
	if ((dir = opendir(to_complete)) == NULL)
		return (completion);
	while ((file = readdir(dir)) != NULL)
	{
		if (char_index(file->d_name, '.') != 0)
		{
			completion = makestr(file->d_name);
			closedir(dir);
			return (completion);
		}
	}
	closedir(dir);
	return (completion);
}
