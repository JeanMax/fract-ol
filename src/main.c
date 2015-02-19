/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <zboub@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/16 18:09:34 by mcanal            #+#    #+#             */
/*   Updated: 2015/02/19 10:07:33 by mcanal           ###   ########.fr       */
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
			if (*s != 'M' && *s != 'J' && *s != 'S' && *s != 'C' && *s != 'D'\
				&& *s != 'N' && *s != '-')
				error(USAGE);
			s++;
		}
		flag[0] = ft_strchr(*av, 'M') ? 'M' : flag[0];
		flag[1] = ft_strchr(*av, 'J') ? 'J' : flag[1];
		flag[2] = ft_strchr(*av, 'S') ? 'S' : flag[2];
		flag[3] = ft_strchr(*av, 'C') ? 'C' : flag[3];
		flag[4] = ft_strchr(*av, 'D') ? 'D' : flag[4];
		flag[5] = ft_strchr(*av, 'N') ? 'N' : flag[5];
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
	t_env		e[6];

	flag[0] ? init(&e[0], "Mandelbrot") : NULL;
	flag[1] ? init(&e[1], "Julia") : NULL;
	flag[2] ? init(&e[2], "Schottky") : NULL;
	flag[3] ? init(&e[3], "Chromosom") : NULL;
	flag[4] ? init(&e[4], "Douady Rabbit") : NULL;
	flag[5] ? init(&e[5], "Noun") : NULL;
	if (!(pid = fork()))
		if (!(pid = fork()))
			if (!(pid = fork()))
				if (!(pid = fork()))
					if (!(pid = fork()))
						flag[5] ? mlx_loop(e[5].mlx) : 0;
					else
						flag[4] ? mlx_loop(e[4].mlx) : 0, wait(NULL);
				else
					flag[3] ? mlx_loop(e[3].mlx) : 0, wait(NULL);
			else
				flag[2] ? mlx_loop(e[2].mlx) : 0, wait(NULL);
		else
			flag[1] ? mlx_loop(e[1].mlx) : 0, wait(NULL);
	else
		flag[0] ? (mlx_loop(e[0].mlx)) : 0, wait(NULL);

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
