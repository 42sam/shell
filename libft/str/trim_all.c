/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssachet <ssachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/23 04:35:58 by ssachet           #+#    #+#             */
/*   Updated: 2015/03/25 22:13:33 by ssachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static void		set_values(int *j, int *k, int *trimlen)
{
	(void)j;
	(void)k;
	(void)trimlen;
	*j = 0;
	*k = 0;
	*trimlen = 0;
}

void			get_trimlen(char *s, int i, int *trimlen)
{
	while (s[i])
	{
		if (!ft_isspace(s[i]) || ((s[i + 1]) && (!ft_isspace(s[i + 1]))))
			trimlen++;
		i++;
	}
}

char			*trim_all(char *s)
{
	char	*trim;
	int		k;
	int		j;
	int		trimlen;

	if (!s)
		return (NULL);
	set_values(&j, &k, &trimlen);
	while (ft_isspace(s[k]))
		k++;
	get_trimlen(s, k, &trimlen);
	if (NULL == (trim = (char *)malloc(trimlen + 1 + 1000)))
		return (NULL);
	while (s[k])
	{
		if (!ft_isspace(s[k]) || !ft_isspace(s[k + 1]))
			trim[j++] = s[k];
		k++;
	}
	trim[j] = '\0';
	return (trim);
}
