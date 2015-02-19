/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chromosom.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/19 06:09:08 by mcanal            #+#    #+#             */
/*   Updated: 2015/02/19 21:52:19 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** chromosom fractal
*/

#include "header.h"

void			chromosom(t_env *e, double ratio, t_char it)
{
	int				i;
	int				j;
	C_DOUBLE		c;
	C_DOUBLE		z;

	ratio = e->zoom * WIN_SIZE / 2;
	i = -1;
	c = 0.02 + I;
	while (j = -1, ++i < WIN_SIZE)
		while (++j < WIN_SIZE)
		{
			z = (i - WIN_SIZE / 2 - e->x) / ratio + \
				I * (j - WIN_SIZE / 2 - e->y) / ratio;
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
