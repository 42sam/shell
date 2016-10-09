/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssachet <ssachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/11 16:50:48 by ssachet           #+#    #+#             */
/*   Updated: 2015/04/03 15:44:59 by ssachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_colors	*load_colors2(t_colors *color)
{
	ft_strcpy((color[9]).name, "bgblack");
	ft_strcpy((color[9]).code, "\033[40m");
	ft_strcpy((color[10]).name, "bgred");
	ft_strcpy((color[10]).code, "\033[41m");
	ft_strcpy((color[11]).name, "bggreen");
	ft_strcpy((color[12]).code, "\033[42m");
	ft_strcpy((color[13]).name, "bgyellow");
	ft_strcpy((color[14]).code, "\033[43m");
	ft_strcpy((color[15]).name, "bgblue");
	ft_strcpy((color[16]).code, "\033[44");
	ft_strcpy((color[17]).name, "bgpurple");
	ft_strcpy((color[18]).code, "\033[45m");
	ft_strcpy((color[19]).name, "bgcyan");
	ft_strcpy((color[20]).code, "\033[46m");
	ft_strcpy((color[21]).name, "bgwhite");
	ft_strcpy((color[22]).code, "\033[47m");
	ft_strcpy((color[23]).name, "eobg");
	ft_strcpy((color[24]).code, "\033[0m");
	return (color);
}

t_colors	*load_colors(void)
{
	t_colors *color;

	color = (t_colors*)malloc(sizeof(t_colors) * 25);
	ft_strcpy((color[0]).name, "eoc");
	ft_strcpy((color[0]).code, "\033[39m");
	ft_strcpy((color[1]).name, "black");
	ft_strcpy((color[1]).code, "\033[30m");
	ft_strcpy((color[2]).name, "red");
	ft_strcpy((color[2]).code, "\033[91m");
	ft_strcpy((color[3]).name, "yellow");
	ft_strcpy((color[3]).code, "\033[33m");
	ft_strcpy((color[4]).name, "underlined");
	ft_strcpy((color[4]).code, "\033[4m");
	ft_strcpy((color[5]).name, "green");
	ft_strcpy((color[5]).code, "\033[32m");
	ft_strcpy((color[6]).name, "eou");
	ft_strcpy((color[6]).code, "\033[24m");
	ft_strcpy((color[7]).name, "lightred");
	ft_strcpy((color[7]).code, "\033[91m");
	ft_strcpy((color[8]).name, "blue");
	ft_strcpy((color[8]).code, "\033[34m");
	load_colors2(color);
	return (color);
}

void		apply_colors(char **string, t_colors *color, char **variable)
{
	int		i;
	char	*code;

	i = 0;
	if ((**string == '[') && char_index(*string, ']'))
	{
		while (i < 9)
		{
			if (ft_strnequ(*string + 1, (color[i]).name,
						char_index(*string, ']') - 1))
			{
				code = ((color[i]).code);
				if (variable != NULL)
					*variable = ft_strjoin(*variable, code);
				else
					ft_putstr(code);
				*string = *string + char_index(*string, ']') + 1;
			}
			i++;
		}
	}
}
