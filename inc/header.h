/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <mcanal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/29 13:23:15 by mcanal            #+#    #+#             */
/*   Updated: 2015/02/17 01:16:03 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H

/*
** define
*/
# define HEADER_H
# define WIN_SIZE 800
# define ESC 65307
# define NUM_PLUS 65451
# define NUM_MINUS 65453
# define LEFT 65361
# define UP 65362
# define RIGHT 65363
# define DOWN 65364
# define USAGE "Usage: ./fractol -[M]"
# define DEBUG { ft_putstr_clr(__func__, "r"); ft_putstr_clr(" (", "r"); ft_putstr_clr(__FILE__, "red"); ft_putstr_clr(") - line: ", "r"); ft_putnbr_clr(__LINE__, "r"); ft_putendl(""); } //debug

/*
** include
*/
# include "../libft/inc/libft.h"
# include <mlx.h>
# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <complex.h>

/*
** struct def
*/
typedef struct s_env	t_env;
struct	s_env
{
	void	*mlx;
	void	*win;
	void	*img;
	int		bpp;
	int		size_line;
	int		endian;
	char	*data;
	int		iter; //move to another struct?
	double	zoom; //TODO //move to another struct?
	int		x_base; //move to another struct?
	int		y_base; //move to another struct?
	int		x_centre; //TODO //move to another struct?
	int		y_centre; //TODO //move to another struct?
};

typedef struct s_coord	t_coord;
struct s_coord
{
	int		x;
	int		y;
	double	xo;
	double	yo;
};

/*
** prototypes
*/
void	mandelbrot(t_env *e);
int		key_hook(int key, t_env *e);
int		mouse_hook(int button, int x, int y, t_env *e);
int		ex_hook(t_env *e);
void	mlx_put_pixel_to_img(t_env *e, int x, int y, int color);

#endif
