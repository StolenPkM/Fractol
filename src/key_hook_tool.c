/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook_tool.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pabonnin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/24 14:21:28 by pabonnin          #+#    #+#             */
/*   Updated: 2017/06/28 21:10:07 by pabonnin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		quit(t_env *e)
{
	mlx_destroy_image(e->mlx, e->img);
	mlx_destroy_window(e->mlx, e->win);
	exit(1);
}

double		scale(int key)
{
	static double scale = 0.4;

	if (key == 83)
		scale = 0.4;
	if (key == 84)
		scale = 0.01;
	if (key == 85)
		scale = 0.00001;
	return (scale);
}

void		direction(int key, t_env *e, char *fractype)
{
	double speed;

	speed = scale(key);
	(key == H) ? e->y1 += speed : 0;
	(key == B) ? e->y1 -= speed : 0;
	(key == L) ? e->x1 += speed : 0;
	(key == R) ? e->x1 -= speed : 0;
	if (!(ft_strcmp("mandel", fractype)))
		redraw_m(e);
	if (!(ft_strcmp("julia", fractype)))
		redraw_j(e);
	if (!(ft_strcmp("sword", fractype)))
		redraw_s(e);
}
