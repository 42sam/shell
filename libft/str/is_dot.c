/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_dot.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssachet <ssachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/12 19:07:02 by ssachet           #+#    #+#             */
/*   Updated: 2015/03/25 22:13:32 by ssachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int		is_dot(char *str)
{
	return ((*str == '.') ? 1 : 0);
}
