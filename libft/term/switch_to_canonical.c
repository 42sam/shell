/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switch_to_canonical.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssachet <ssachet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 08:56:55 by ssachet           #+#    #+#             */
/*   Updated: 2015/03/25 21:51:51 by ssachet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	switch_term(void)
{
	newterm.c_cc[VMIN] = 1;
	newterm.c_lflag &= ~(ICANON | ECHO);
	newterm.c_iflag = IGNPAR;
	newterm.c_oflag = 0;
	tcsetattr(0, TCSANOW, &newterm);
}
