/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/16 19:50:14 by mcanal            #+#    #+#             */
/*   Updated: 2015/02/17 23:23:06 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** mandel fractal
*/

#include "header.h"

static int		ft_rgb(size_t r, size_t g, size_t b)
{
	if (r < 256 && g < 256 && b < 256)
		return (r + g * 256 + b * 256 * 256);
	else
		return (0);
}

static void		calc_mandel(t_coord *coord, t_env *e)
{
	double complex	c;
	double complex	z;
	int				i;

	c = coord->xo + I * coord->yo;
	z = 0;
	i = 0;
	while (i < e->iter && (int)z < 2)
	{
		z = z * z + c;
		i++;
	}
	if (i < e->iter)
	{
		if (i % 3 != 1)
			mlx_put_pixel_to_img(e, coord->x, coord->y,         \
								 ft_rgb(0, i * 255 / e->iter, 0));
		else
			mlx_put_pixel_to_img(e, coord->x, coord->y,         \
								 ft_rgb(0, 0, i * 255 / e->iter));
	}
//	else
//		mlx_put_pixel_to_img(e, coord->x, coord->y, 0x000033);
}

static void		calc_coord(t_env *e, t_coord *coord)
{
	int			i;
	int			j;
	double		ratio;

	ratio = 2.7 / WIN_SIZE;
	i = 0;
	while (i < WIN_SIZE)
	{
		j = 0;
		while (j < WIN_SIZE)
		{
			coord->x = i;
			coord->y = j;
			coord->xo = ((double)(i - e->x_base) * ratio) * e->zoom;
			coord->yo = ((double)(j - e->y_base) * ratio) * e->zoom;
			calc_mandel(coord, e);
			j++;
		}
		i++;
	}
}

void			mandelbrot(t_env *e)
{
	t_coord		coord;

	calc_coord(e, &coord);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
}
