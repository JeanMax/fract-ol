/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/16 19:50:14 by mcanal            #+#    #+#             */
/*   Updated: 2015/02/19 17:19:19 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** mandel fractal
*/

#include "header.h"

void			mandelbrot(t_env *e, double ratio, t_char it)
{
	double				i;
	double				j;
	double complex		c;
	double complex		z;

	ratio = 2.7 / WIN_SIZE / e->zoom;
	i = -1;
	while (j = -1, ++i < WIN_SIZE)
		while (++j < WIN_SIZE)
		{
			c = (i - e->x_base) * ratio + I * (j - e->y_base) * ratio;
			z = 0;
			it = -1;
			while (++it < e->iter && (int)z < 2)
				z = z * z + c;
			if (it == e->iter)
				put_pixel_to_img(e, i, j, e->color * (0 % 0xFF));
			else
				put_pixel_to_img(e, i, j, e->color * (it % 0xFF));
//			if (it < e->iter)
				//		put_pixel_to_img(e, i, j, e->color * it % 0x0000FF);//rgb(it, e->iter));
		}
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
}
