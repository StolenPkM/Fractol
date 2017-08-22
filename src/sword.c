/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sword.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabonnin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/28 01:58:47 by pabonnin          #+#    #+#             */
/*   Updated: 2017/06/28 21:03:06 by pabonnin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	pick_s(t_env *e, char *argv)
{
	init_env(e, argv);
	sword(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	legend(e);
	mlx_mouse_hook(e->win, mouse_hook_s, e);
	mlx_hook(e->win, 2, 3, s_key_hook, e);
	mlx_loop(e->mlx);
}

void	init_s(t_env *e)
{
	e->x1 = -2;
	e->x2 = 2.5;
	e->y1 = -1.5;
	e->y2 = 3;
	e->c_r = 0.285;
	e->c_i = 0.01;
	e->zoom = 350;
	e->iter_max = 140;
	e->r = 3;
	e->g = 4;
	e->b = 5;
	e->motion = 0;
}

void	sword(t_env *e)
{
	e->image_x = HEIGHT;
	e->image_y = WIDTH;
	e->x = 0;
	while (e->x < e->image_x)
	{
		e->y = 0;
		while (e->y < e->image_y)
		{
			e->c_r = e->c_r;
			e->c_i = e->c_i;
			e->z_r = e->x / e->zoom + e->x1;
			e->z_i = e->y / e->zoom + e->y1;
			e->i = 0;
			while (e->z_r * e->z_r + e->z_i * e->z_i < 4 && e->i < e->iter_max)
			{
				e->tmp = e->z_r;
				e->z_r = fabs(e->z_r * e->z_r - e->z_i * e->z_i + e->c_r);
				e->z_i = fabs(2 * e->z_i * e->tmp + e->c_i);
				e->i++;
			}
			fill_pixel(e);
			e->y++;
		}
		e->x++;
	}
}
