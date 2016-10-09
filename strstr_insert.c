/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strstr_insert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssachet <ssachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/25 15:52:41 by ssachet           #+#    #+#             */
/*   Updated: 2015/03/17 05:05:45 by ssachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "myshell.h"

char	*strstr_insert2(char *s1, char *s2, int index)
{
	char *s1b;

	s1b = (char *)malloc(sizeof(s1));
	if (index > (int)ft_strlen(s1))
		return (NULL);
	ft_strncpy(s1b, s1, index);
	ft_printf("s1 = %s|\n", s1b);
	ft_strcat(s1b, s2);
	ft_printf("s1 = %s|\n", s1b);
	ft_strcat(s1b, s1 + index);
	ft_printf("s1 = %s|\n", s1b);
	return (s1b);
}

char	*strstr_insert(char *str, char *to_insert, int index)
{
	char *newstr;
	char *end;

	if (index > (int)ft_strlen(str))
		return (NULL);
	if (index == 0)
	{
		newstr = ft_strjoin(to_insert, str);
	}
	else
	{
		newstr = ft_strsub(str, 0, index);
		newstr = ft_strjoin(newstr, to_insert);
		end = ft_strsub(str, index, ft_strlen(str) - index);
		newstr = ft_strjoin(newstr, end);
	}
	return (newstr);
}

char	*strstr_del(char *str, int cnb, int index)
{
	char	*newstr;
	int		slen;

	newstr = str;
	slen = (int)ft_strlen(str);
	if (index > slen)
		return (NULL);
	if (slen == 1)
		return (makestr(""));
	if (cnb > index)
		return (NULL);
	newstr = ft_strsub(str, 0, index - cnb);
	newstr = ft_strjoin(newstr, str + index);
	return (newstr);
}
