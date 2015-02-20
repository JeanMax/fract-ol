/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   noun.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/18 20:53:20 by mcanal            #+#    #+#             */
/*   Updated: 2015/02/20 17:21:46 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** julia fractal drawing!
*/

#include "header.h"

void			noun(t_env *e, t_char it)
{
	int				i;
	int				j;
	C_DOUBLE		c;
	C_DOUBLE		z;

	i = -1;
	c = -0.846545 + I * -0.2558;
	while (j = -1, ++i < WIN_SIZE)
		while (++j < WIN_SIZE)
		{
			z = (i - e->x + I * (j - e->y)) / e->zoom;
			it = -1;
			while (++it < e->iter && (int)z < 2)
				z = z * z + c;
			if (it == e->iter)
				put_pixel_to_img(e, i, j, e->color * (0 % 0xFF));
			else
				put_pixel_to_img(e, i, j, e->color * (it % 0xFF));
		}
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
}
