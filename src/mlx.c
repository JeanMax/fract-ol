/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/16 18:26:16 by mcanal            #+#    #+#             */
/*   Updated: 2015/02/22 13:50:13 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** mlx functions...
*/

#include "header.h"

int					ex_hook(t_env *e)
{
	mlx_destroy_image(e->mlx, e->img);
	if (!(e->img = mlx_new_image(e->mlx, WIN_SIZE, WIN_SIZE)))
		error(IMG_PTR);
	e->data = mlx_get_data_addr(e->img, &(e->bpp), &(e->x_len), &(e->endian));
	if (e->fractal == 'M')
		mandelbrot(e, 0);
	else if (e->fractal == 'J')
		julia(e, 0);
	else if (e->fractal == 'S')
		schottky(e, 0);
	else if (e->fractal == 'C')
		chromosom(e, 0);
	else if (e->fractal == 'N')
		noun(e, 0);
	else if (e->fractal == 'D')
		rabbit(e, 0);
	return (0);
}

void				put_pixel_to_img(t_env *e, int x, int y, int color)
{
	int		i;
	int		col_tmp;

	if (x > WIN_SIZE || y > WIN_SIZE)
		error(PUT_PIX);
	col_tmp = mlx_get_color_value(e->mlx, color);
	i = y * e->x_len + x * (e->bpp / 8);
	if (!(e->endian))
	{
		e->data[i] = (col_tmp & 0x0000FF);
		e->data[i + 1] = (col_tmp & 0x00FF00) >> 8;
		e->data[i + 2] = (col_tmp & 0xFF0000) >> 16;
	}
	else
	{
		e->data[i + 1] = (col_tmp & 0xFF0000) >> 8;
		e->data[i + 2] = (col_tmp & 0x00FF00) >> 16;
		e->data[i + 3] = (col_tmp & 0x0000FF) >> 24;
	}
}
