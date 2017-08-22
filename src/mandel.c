/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandel.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabonnin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/24 12:08:09 by pabonnin          #+#    #+#             */
/*   Updated: 2017/06/28 21:01:12 by pabonnin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	pick_m(t_env *e, char *argv)
{
	init_env(e, argv);
	mandelbrot(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	legend(e);
	mlx_hook(e->win, 2, 3, m_key_hook, e);
	mlx_mouse_hook(e->win, mouse_hook_m, e);
	mlx_loop(e->mlx);
}

void	init_m(t_env *e)
{
	e->x1 = -3;
	e->x2 = 2.5;
	e->y1 = -2;
	e->y2 = 3;
	e->zoom = 242;
	e->iter_max = 100;
	e->r = 3;
	e->g = 4;
	e->b = 5;
	e->motion = 0;
}

void	mandelbrot(t_env *e)
{
	e->image_x = HEIGHT;
	e->image_y = WIDTH;
	e->x = 0;
	while (e->x < e->image_x)
	{
		e->y = 0;
		while (e->y < e->image_y)
		{
			e->c_r = e->x / e->zoom + e->x1;
			e->c_i = e->y / e->zoom + e->y1;
			e->z_r = 0;
			e->z_i = 0;
			e->i = 0;
			while (e->z_r * e->z_r + e->z_i * e->z_i < 4 && e->i < e->iter_max)
			{
				e->tmp = e->z_r;
				e->z_r = e->z_r * e->z_r - e->z_i * e->z_i + e->c_r;
				e->z_i = 2 * e->z_i * e->tmp + e->c_i;
				e->i++;
			}
			fill_pixel(e);
			e->y++;
		}
		e->x++;
	}
}
