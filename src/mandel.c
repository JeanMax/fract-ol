/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/16 19:50:14 by mcanal            #+#    #+#             */
/*   Updated: 2015/02/20 17:20:17 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** mandel fractal
*/

#include "header.h"

void			mandelbrot(t_env *e, t_char it)
{
	double				i;
	double				j;
	C_DOUBLE			c;
	C_DOUBLE			z;

	i = -1;
	while (j = -1, ++i < WIN_SIZE)
		while (++j < WIN_SIZE)
		{
			c = (i - e->x + I * (j - e->y)) / e->zoom;
			z = 0;
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
