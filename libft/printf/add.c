/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssachet <ssachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 08:57:18 by ssachet           #+#    #+#             */
/*   Updated: 2015/03/11 16:51:54 by ssachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*add_sign(void *myarg, t_a *flag)
{
	if (*(char *)myarg == '-' && !char_conversion(flag)
								&& !string_conversion(flag))
	{
		flag->sign = '-';
		flag->sign_pad = '-';
		myarg = ft_strsub(myarg, 1, ft_strlen(myarg + 1));
	}
	else
		flag->sign = '+';
	return (myarg);
}

int			add_type(char **str, t_a *flag)
{
	if (is_type(**str))
	{
		flag->type = **str;
		return (0);
	}
	return (-1);
}

void		add_ext_width(va_list argp, t_a *flag)
{
	int ext_width;

	if (flag->ext_width)
	{
		ext_width = va_arg(argp, int);
		flag->width = (flag->width == 0) ? ext_width : flag->width;
		if (flag->width < 0)
		{
			flag->width = flag->width * -1;
			flag->pad = 'r';
		}
	}
}
