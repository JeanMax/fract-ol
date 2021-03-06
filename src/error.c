/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/18 20:39:30 by mcanal            #+#    #+#             */
/*   Updated: 2015/02/19 07:02:50 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** errors handling
*/

#include "header.h"

void			error(t_char c)
{
	if (c == USAGE)
		failn(USAGE_MSG1), failn(USAGE_MSG2);
	else if (c == IMG_PTR)
		failn(IMG_PTR_MSG);
	else if (c == PUT_PIX)
		failn(PUT_PIX_MSG);
	exit(-1);
}
