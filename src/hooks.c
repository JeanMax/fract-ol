/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <mcanal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/29 17:28:24 by mcanal            #+#    #+#             */
/*   Updated: 2015/02/19 17:22:26 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** hooks et plus si affinité
*/

#include "header.h"

int		ex_hook(t_env *e)
{
//	mlx_destroy_image(e->mlx, e->img);
	if (!(e->img = mlx_new_image(e->mlx, WIN_SIZE, WIN_SIZE)))
		error(IMG_PTR);
	e->data = mlx_get_data_addr(e->img, &(e->bpp), &(e->x_len), &(e->endian));
	if (e->fractal == 'M')
		mandelbrot(e, 0, 0);
	else if (e->fractal == 'J')
		julia(e, 0, 0);
	else if (e->fractal == 'S')
		schottky(e, 0, 0);
	else if (e->fractal == 'C')
		chromosom(e, 0, 0);
	else if (e->fractal == 'N')
		noun(e, 0, 0);
	else if (e->fractal == 'D')
		rabbit(e, 0, 0);
	return (0);
}

int		key_hook(int key, t_env *e)
{
	if (key == ESC)
		ft_putstr_clr("K_THX_BYE", "b"), kill(0, SIGINT);
	else if (key == PAGE_UP && e->iter < 100)
		e->iter += 3;
	else if (key == PAGE_DOWN && e->iter != 3)
		e->iter -= 3;
	else if (key == UP)
		e->y_base -= 10;
	else if (key == DOWN)
		e->y_base += 10;
	else if (key == LEFT)
		e->x_base -= 10;
	else if (key == RIGHT)
		e->x_base += 10;
	else if (key == NUM_PLUS)
		e->zoom /= 0.95;
	else if (key == NUM_MINUS)
		e->zoom *= 0.95;
	else if (key == ONE)
		e->color += 0x100000;
	else if (key == TWO)
		e->color += 0x001000;
	else if (key == THREE)
		e->color += 0x000010;
	else if (key == FOUR)
		e->color -= 0x100000;
	else if (key == FIVE)
		e->color -= 0x001000;
	else if (key == SIX)
		e->color -= 0x000010;
	else if (key == SPACE)
	{
		e->x_base = WIN_SIZE * 0.5;
		e->y_base = WIN_SIZE * 0.5;
		e->zoom = 1;
		e->iter = 49;
		ex_hook(e);
	}
	else if (key == ENTER)
		e->lock += e->lock == 0 ? 1 : -1;
	else if (key == L_CTRL)
	{
		while (42)
		{
			e->color += 0x100000;
			ex_hook(e);
		}
	}
	else
		ft_debugnbr("key", key); //debug
	if (key == PAGE_UP || key == PAGE_DOWN)
		ft_debugnbr("IterationLevel", e->iter), ex_hook(e);  //debug
	else if (key >= LEFT && key <= DOWN)
		ft_debugnbr("x", e->x_base), ft_debugnbr("y", e->y_base), ex_hook(e);//d
	else if (key == NUM_PLUS || key == NUM_MINUS)
		ft_debugdbl("zoom", e->zoom), ex_hook(e); //debug
	else if (key >= ONE && key <= SIX)
		ex_hook(e);
	return (0);
}

int		mouse_hook(int button, int x, int y, t_env *e)
{
	if (button == SCROLL_UP)
	{
		e->zoom /= 0.95;
		e->x_base += (int)((WIN_SIZE / 2) - x) / (double)(20.0 / e->zoom);
		e->y_base += (int)((WIN_SIZE / 2) - y) / (double)(20.0 / e->zoom);
		ft_debugdbl("zoom", e->zoom); //debug
	}
	else if (button == SCROLL_DOWN)
	{
		e->zoom *= 0.95;
		e->x_base -= (int)((WIN_SIZE / 2) - x) / (double)(20.0 / e->zoom);
		e->y_base -= (int)((WIN_SIZE / 2) - y) / (double)(20.0 / e->zoom);
		ft_debugdbl("zoom", e->zoom); //debug
	}
	else
		ft_debugnbr("button", button), ft_debugnbr("x", x), ft_debugnbr("y", y); //debug
	if (button == SCROLL_UP || button == SCROLL_DOWN)
		ex_hook(e);
	return (0);
}

int		mouse_move(int x, int y, t_env *e)
{
	if (!((x + y) % 10) && !e->lock)
	{
		e->iter = ((x + y) / 8 ) + 1;
		ft_debugnbr("IterationLevel", e->iter), ex_hook(e);  //debug
	}
	return (0);
}
