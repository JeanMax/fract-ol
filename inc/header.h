/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcanal <mcanal@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/29 13:23:15 by mcanal            #+#    #+#             */
/*   Updated: 2015/02/19 10:14:58 by mcanal           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H

/*
** define
*/
# define HEADER_H
# define WIN_SIZE 600
# define ESC 65307
# define ENTER 65293
# define NUM_PLUS 65451
# define NUM_MINUS 65453
# define LEFT 65361
# define UP 65362
# define RIGHT 65363
# define DOWN 65364
# define PAGE_UP 65365
# define PAGE_DOWN 65366
# define SPACE 32
# define LEFT_CLICK 1
# define RIGHT_CLICK 3
# define SCROLL_UP 4
# define SCROLL_DOWN 5
# define USAGE 1
# define USAGE_MSG1 "Usage: ./fractol -[MJSCDN]"
# define USAGE_MSG2 "(Mandelbrot/Julia/Schottky/Chromosom/Douady-Rabbit/Noun)"
# define IMG_PTR 2
# define IMG_PTR_MSG "Error while creating img pointer."
# define PUT_PIX 3
# define PUT_PIX_MSG "Error while trying to put pixel out of image."
# define DEBUG { ft_putstr_clr(__func__, "r"); ft_putstr_clr(" (", "r"); ft_putstr_clr(__FILE__, "red"); ft_putstr_clr(") - line: ", "r"); ft_putnbr_clr(__LINE__, "r"); ft_putendl(""); } //debug

/*
** include
*/
# include "../libft/inc/libft.h"
# include <X11/X.h>
# include <mlx.h>
# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <complex.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <signal.h>

/*
** struct def
*/

typedef struct s_env	t_env;
struct	s_env
{
	void		*mlx;
	void		*win;
	void		*img;
	int			bpp;
	int			x_len;
	int			endian;
	char		*data;
	t_char		fractal;
	t_char		iter; //move to another struct?
	double		zoom; //move to another struct?  //use LONG DOUBLE?
	t_char		lock; //idem
	int			x_base; //move to another struct? //use LONG LONG?
	int			y_base; //move to another struct? //use LONG LONG?
};

/*
** prototypes
*/
void	error(t_char c);
void	julia(t_env *e, double ratio, t_char it);
void	noun(t_env *e, double ratio, t_char it);
void	rabbit(t_env *e, double ratio, t_char it);
void	chromosom(t_env *e, double ratio, t_char it);
void	mandelbrot(t_env *e, double ratio, t_char it);
void	schottky(t_env *e, double ratio, t_char it);
int		key_hook(int key, t_env *e);
int		mouse_hook(int button, int x, int y, t_env *e);
int		mouse_move(int x, int y, t_env *e);
int		ex_hook(t_env *e);
void	put_pixel_to_img(t_env *e, int x, int y, int color);
int		rgb(t_char i, t_char i_max);

#endif
