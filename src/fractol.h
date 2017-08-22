/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabonnin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/24 11:52:51 by pabonnin          #+#    #+#             */
/*   Updated: 2017/06/29 13:44:36 by pabonnin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "../libft/libft.h"
# include <mlx.h>
# include <math.h>

# define HEIGHT 800
# define WIDTH 600
# define WHITE 0xFFFFFF

# define ESC 53
# define H 125
# define B 126
# define L 124
# define R 123
# define PLUS 69
# define MIN 78
# define P 35
# define M 46
# define D 2

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*data;
	int				bpp;
	int				s_l;
	int				endian;
	int				iter_max;
	int				x;
	int				y;
	int				motion;
	int				r;
	int				g;
	int				b;
	double			x1;
	double			x2;
	double			y1;
	double			y2;
	double			zoom;
	double			image_x;
	double			image_y;
	double			c_r;
	double			c_i;
	double			z_r;
	double			z_i;
	double			tmp;
	double			i;
	int				moov;
}					t_env;

void				frac_error();
void				init_env(t_env *e, char *argv);
void				init_m(t_env *e);
void				init_j(t_env *e);
void				init_s(t_env *e);
void				pick_m(t_env *e, char *argv);
void				pick_j(t_env *e, char *argv);
void				pick_s(t_env *e, char *argv);
void				mandelbrot(t_env *e);
void				julia(t_env *e);
void				sword(t_env *e);
int					m_key_hook(int key, t_env *e);
int					j_key_hook(int key, t_env *e);
int					s_key_hook(int key, t_env *e);
double				scale(int key);
void				direction(int key, t_env *e, char *fractype);
void				quit(t_env *e);
void				redraw_m(t_env *e);
void				redraw_j(t_env *e);
void				redraw_s(t_env *e);
int					mouse_j(int x, int y, t_env *e);
int					mouse_hook_m(int key, int x, int y, t_env *e);
int					mouse_hook_s(int key, int x, int y, t_env *e);
int					mouse_hook_j(int key, int x, int y, t_env *e);
void				legend(t_env *e);
void				fill_pixel(t_env *e);

#endif
