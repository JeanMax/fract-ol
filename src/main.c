/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/16 18:09:34 by mcanal            #+#    #+#             */
/*   Updated: 2015/02/19 00:36:11 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** this is the main!;D
** *flag : 0=M(andelbrot) 1=J(ulia) 2=B(uddhabrot), 3=T(ob)
*/

#include "header.h"

static char		*check_flag(int ac, char **av, char *flag)
{
	char		*s;

	ac < 2 ? error(USAGE) : NULL;
	while (*av)
	{
		s = *av;
		while (*s)
		{
			if (*s != 'M' && *s != 'J' && *s != 'B' && *s != 'T' && *s != '-')
				error(USAGE);
			s++;
		}
		if (ft_strchr(*av, 'M'))
			flag[0] = 'M';
		if (ft_strchr(*av, 'J'))
			flag[1] = 'J';
		if (ft_strchr(*av, 'B'))
			flag[2] = 'B';
		if (ft_strchr(*av, 'T'))
			flag[3] = 'T';
		av++;
	}
	(!flag[0] && !flag[1] && !flag[2] && !flag[3]) ? error(USAGE) : NULL;
	return (flag);
}

static void		init(t_env *e, char *name)
{
	e->lock = 0;
	e->fractal = name[0];
	e->iter = 49;
	e->zoom = 1;
	e->x_base = WIN_SIZE * 0.5;
	e->y_base = WIN_SIZE * 0.5;
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, WIN_SIZE, WIN_SIZE, name);
	if (!(e->img = mlx_new_image(e->mlx, WIN_SIZE, WIN_SIZE)))
		error(IMG_PTR);
	e->data = mlx_get_data_addr(e->img, &(e->bpp), &(e->x_len), &(e->endian));
	mlx_key_hook(e->win, key_hook, e);
	mlx_mouse_hook(e->win, mouse_hook, e);
	mlx_hook(e->win, MotionNotify, PointerMotionMask, mouse_move, e);
	mlx_expose_hook(e->win, ex_hook, e);
}

static void		launch_loop(char *flag, pid_t pid)
{
	t_env		e1;
	t_env		e2;
	t_env		e3;
	t_env		e4;

	flag[0] ? init(&e1, "Mandelbrot") : NULL;
	flag[1] ? init(&e2, "Julia") : NULL;
	flag[2] ? init(&e3, "Buddhabrot") : NULL;
	flag[3] ? init(&e4, "Tob") : NULL;
	if (!(pid = fork()))
	{
		if (!(pid = fork()))
		{
			if (!(pid = fork()))
				flag[3] ? mlx_loop(e4.mlx) : 0;
			else
				flag[2] ? mlx_loop(e3.mlx) : 0, wait(NULL);
		}
		else
			flag[1] ? mlx_loop(e2.mlx) : 0, wait(NULL);
	}
	else
		flag[0] ? (mlx_loop(e1.mlx)) : 0, wait(NULL);
}

int				main(int ac, char **av)
{
	char		*flag;
	pid_t		pid;

	flag = ft_memalloc(5);
	pid = -42;
	flag = check_flag(ac, &av[1], flag);
	launch_loop(flag, pid);
	free(flag);
	return (0);
}
